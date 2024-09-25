#include <stdio.h>
#include "../interfaces/data/constants.h"
#include "../interfaces/data/proccess.h"

/// @brief Print a line in the terminal
/// @param c The character to print
void print_line(char c)
{
  for (int i = 0; i < 107; i++)
  {
    printf("%c", c);
  }
  printf("\n");
}

/// @brief Print The proccesses information table head
void print_table_titles()
{
  printf("| %-8s | %-16s | %-16s | %-16s | %-16s | %-16s |\n",
         "Process", "Arrival Time", "Execution Time", "Start Time", "End Time",
         "Turnaround Time");
}

/// @brief Prints all information about the proccess
/// @param process that we will retreives its information
void print_proccess_into(struct Process *process)
{
  printf("| %-8c | %16d | %16d | %16d | %16d | %16d |\n",
         process->processId,
         process->arrivalTime,
         process->executionTime,
         process->startingTime,
         process->endingTime,
         process->turnaroundTime);
}

void print_report()
{
  print_line('=');
  print_table_titles();
  print_line('=');

  // Display proccess information
  for (size_t ii = 0; ii < __schedular_executedProccesses; ii++)
  {
    print_proccess_into(&processes[ii]);
    ii == __schedular_executedProccesses - 1 ? print_line('=') : print_line('-');
  }
}