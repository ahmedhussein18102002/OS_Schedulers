#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../config.h"
#include "../interfaces/data/constants.h"
#include "../interfaces/data/proccess.h"
#include "../interfaces/helpers/printer.h"
#include "../interfaces/helpers/simulator.h"

// -------------------

void decrease_priority()
{
  for (int i = 0; i < NUM_PROCCSSES; i++)
  {
    struct Process *process = &processes[i];

    // Skip the proccess if it is just arrived, or finished or it is an IO process
    if (process->arrivalTime >= currentStep ||
        process->isExecuted ||
        process->io_step)
      continue;

    // Decrease the priority of the proccesses that runs the previous step
    if (process->lastExecutedStep == currentStep - 1 && process->priority > 0)
      process->priority--;
  }
}

void increase_priority()
{
  for (int i = 0; i < NUM_PROCCSSES; i++)
  {
    struct Process *process = &processes[i];

    // Skip the proccess if it is just arrived, or finished or it is an IO process
    if (process->arrivalTime >= currentStep ||
        process->isExecuted)
      continue;

    process->priority = MAX_PRIORITY; // Maximum Priority is 2
  }
}

// Multi-Level Feedback Queue
/// @bug The calculation of CPU time consuming takes place using `currentStep` global variable.
///      So if no processes comes for the first 2 steps for example, the `increase_priority()` will occuar
///      After MAX_PRIORITY - 2 steps.
///
///      It is better to determing the time, from the beginning of the active processes, and stop calculating
///      and increasing steps if there is no process to fire in any core
///
///      But since it is just a simulation, it is OK. And it did not break the logic of the schedular
///      So we will leave the logic as it is
void MLFQ()
{
  print_line('=');
  simulate_table_titles();
  print_line('=');

  // Loop until we finish all proccesses
  while (true)
  {

    initializeRunningCores();

    // Decreasing priority of the running processes when after first execution
    // NOTE: the time after which we decrease is one step, this designer (ME) decision
    if (currentStep > 0)
      decrease_priority();

    // After 5 STEPS, we will increase the priority of all active processes to the MAX_PRIORITY
    if (currentStep > 0 && currentStep % PRIORITY_BOOST == 0)
      increase_priority();

    // Check if there is a running proccess or not
    bool needSleep = true;

    // proccesses indexes that will run in this iteration
    int running_proccesses_indexes[NUM_CORES];
    for (int __i = 0; __i < NUM_CORES; __i++)
      running_proccesses_indexes[__i] = -1;

    // The index of the proccess that will run the I/O
    int io_proccess_index = -1;

    /* Put each proccess to its suitable core, and handle IO requests */
    for (int i = 0; i < NUM_PROCCSSES; i++)
    {
      struct Process *process = &processes[i];

      // Simulate Running the proccess if this proccess arrived and not finished yet
      if (currentStep < process->arrivalTime || process->isExecuted)
        continue;

      // To not sleep the CPU, as it will execute a proccess insteaed
      // We will reset this variable to false more than one time, but who cares
      needSleep = false;

      // The proccess is firstly executed
      if (process->core == 0)
      {
        process->core = __schedular_availableCore++;

        // Reseting the cores if we reached the maximum
        if (__schedular_availableCore == NUM_CORES + 1)
        {
          __schedular_availableCore = 1;
        }
      }

      // Knowing what cores will be in running state in this step
      if (process->core > 0 && !process->isExecuted)
      {
        if (!__running_cores[process->core - 1])
          __running_cores[process->core - 1] = true;
      }

      // If the proccess requested an I/O, we will set the `io_arrivalTime` to the current step
      if (process->io_interrupt == process->executed &&
          process->io_executed < IO_TIME &&
          process->io_arrivalTime == -1)
      {
        process->io_step = true;               // Allow the `io_step` to stop proccessing it by the core
        process->io_arrivalTime = currentStep; // Setting the `io_arrival` time of the proccess
      }

      // When `process->io_executed < IO_TIME` the io_step will set to false before ending the process,
      // no need to handle it.
      // And this condition `process->io_executed < IO_TIME` will not happen any more,
      // so everything should work properly.
    }

    /* Loop through each core, and know what is the proccess it will run in this step */
    for (int i_cores = 0; i_cores < NUM_CORES; i_cores++)
    {
      // Skip the core, if it doesn't run any process
      if (!__running_cores[i_cores])
        continue;

      /* Schedular Algorism ... */

      int proccessIndex = -1; // -1 represents that there is no proccess running

      // Looping through all proccesses and getting the Id of the first arrival one (FIFO algorism)
      for (int i_proccess = 0; i_proccess < NUM_PROCCSSES; i_proccess++)
      {
        struct Process *process = &processes[i_proccess];

        // Getting the proccesses that the `core-*` will run
        // Update the `proccessIndex` that represents the proccess that will ran by the core-1, core-2,...
        if (process->core == i_cores + 1 && !process->isExecuted)
        {
          // printf("process(%c)->priority: %d \n", process->processId, process->priority);
          if (process->io_step)
            continue;

          if (proccessIndex == -1)
            proccessIndex = i_proccess;

          if (process->priority > processes[proccessIndex].priority)
          {
            proccessIndex = i_proccess;
          }

          if (process->lastExecutedStep < processes[proccessIndex].lastExecutedStep &&
              process->priority == processes[proccessIndex].priority)
          {
            proccessIndex = i_proccess;
          }

          if (process->lastExecutedStep == processes[proccessIndex].lastExecutedStep &&
              process->priority == processes[proccessIndex].priority &&
              process->arrivalTime < processes[proccessIndex].arrivalTime)
          {
            proccessIndex = i_proccess;
          }
        }
      }

      // If the core will run a proccess at this time
      if (proccessIndex > -1)
      {
        running_proccesses_indexes[i_cores] = proccessIndex;
      }
    }

    /* Handle what which proccess the IO will run (if needed) */
    for (int i_proccess = 0; i_proccess < NUM_PROCCSSES; i_proccess++)
    {
      if (processes[i_proccess].io_step)
      {

        /*
          All IO processes are rejected from RR, so we can assume that all the processes that
          come to this region are Not executing by any core.
        */

        if (io_proccess_index == -1)
        {
          io_proccess_index = i_proccess;
        }
        else if (processes[i_proccess].io_arrivalTime < processes[io_proccess_index].io_arrivalTime)
        {
          io_proccess_index = i_proccess;
        }
      }
    }

    /* Run Proccesses */
    pthread_t __running_proccess[NUM_CORES];
    for (int i_run = 0; i_run < NUM_CORES; i_run++)
    {

      // If the core is not in running state, we will not make a request
      if (!__running_cores[i_run])
        continue;

      int cachedProccessIndex = running_proccesses_indexes[i_run];

      // Check if the core has a proccess to execute or not
      if (cachedProccessIndex == -1 || processes[cachedProccessIndex].io_step)
        continue;

      pthread_create(&__running_proccess[i_run], NULL, (void *)execute_process, &processes[cachedProccessIndex]);
    }

    /* Run IO */
    pthread_t __running_io_proccess;

    // Check if the core has a proccess to execute or not
    if (io_proccess_index > -1)
    {
      pthread_create(&__running_io_proccess, NULL, (void *)execute_io_process, &processes[io_proccess_index]);
    }

    // Waiting all cores to run there proccess
    for (int i_join = 0; i_join < NUM_CORES; i_join++)
    {
      if (!__running_cores[i_join] || __running_proccess[i_join] == -1)
        continue;
      pthread_join(__running_proccess[i_join], NULL);
    }

    // Waiting IO proccess to finish
    if (io_proccess_index > -1)
      pthread_join(__running_io_proccess, NULL);

    // Log the status for all proccesses we have
    simulate_proccesses();

    // If the number of ended proccesses equals the number of proccesses entered the system
    // We will log the proccesses informations, then close the program
    if (__schedular_executedProccesses == NUM_PROCCSSES)
    {
      print_report();
      break; // Close The schedular
    }

    // sleep if there is no proccess is running (idle STEP)
    if (needSleep)
      usleep(STEP);

    ++currentStep; // Increase the steps by 1

    print_line('-');
  }
}
