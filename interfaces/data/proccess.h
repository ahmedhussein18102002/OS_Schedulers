#ifndef PROCCESS_H
#define PROCCESS_H

#include <stdbool.h>
#include "../../config.h"

struct Process
{
    char processId;        // Identfy the proccess by an ID
    int core;              // The core that will execute this proccess
    int arrivalTime;       // The time the proccess enters the system
    int executionTime;     // The number of steps, the proccess will do
    int startingTime;      // The starting time of the proccess (set in running)
    int endingTime;        // ending time of the proccess
    int executed;          // the number of executed steped the proccess has made
    int lastExecutedStep;  // The last time (STEP) the proccess executed, used in RR and MLFQ
    int priority;          // represents priority in Priority and MLFQ
    int stride;            // represents stride in Stride
    int turnaroundTime;    // the timearound of the proccess, calculated after ending execution
    _Bool isExecuted;      // determine if the proccess ends or not
    _Bool justFinished;    // Used in logging in the terminal not else
    int io_interrupt;      // The time the proccess will ask for IO, -1 means no IO
    int io_arrivalTime;    // The time the proccess entered the IO state
    int io_executed;       // The time the proccess will ask for IO, -1 means no IO
    _Bool io_step;         // true when IO execution, false in normal execution
    _Bool io_justFinished; // Used in logging in the terminal not else
};

// Global proccesses variable
extern struct Process *processes;

/// @brief Initialize an array of processes by allocation its size in memory
void init_processes_array(int numProcesses);

/// @brief Checkign if the executed proccess ends or not
void check_proccess_end(struct Process *process);

/// @brief Initialze new proccess
void init_process(struct Process *process, char Id, int arrivalTime, int executionTime, int io_interrupt, int priority, int stride);

/// @brief execute a process by increasing proccess->executed by 1
void *execute_process(void *arg);

/// @brief executes an IO proccess
void *execute_io_process(void *arg);

/// @brief Getting the reamining time (steps) of the given proccess
int remainingTime(struct Process *process);

/// @brief Getting the pass executed by the given process in Stride schedular
int process_stride_pass(struct Process *process);

#endif