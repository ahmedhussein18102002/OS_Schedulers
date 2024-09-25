#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../interfaces/data/constants.h"
#include "../interfaces/data/proccess.h"
#include "../interfaces/helpers/math.h"
#include "../interfaces/helpers/utils.h"

/// @brief similar to `print_line()`, we will refactor later
/// @param c The number to print
void simulate_line(char c)
{
  for (int i = 0; i < 107; i++)
  {
    printf("%c", c);
  }
  printf("\n");
}

/// @brief Prints the table header of the running proccesses
void simulate_table_titles()
{
  printf("| %-8s | %-16s | %-54s | %-16s |\n",
         "Core", "Priority/Stride", "Running Processes", "Percentage");
}

void log_proccess_status(struct Process *proccess)
{
  char indecatorChar = proccess->lastExecutedStep == currentStep && !proccess->io_step ? '#' : '~';
  // Get completion percentage of the proccess
  int repeatCount = process_bar_length(proccess);
  char *repeatedString = repeat_char(indecatorChar, repeatCount); // This makes malloc()

  if (proccess->priority > -1)
  {
    printf("| Core-%d   | Priority: %-6d | %c : %-50s |             %3d\% | \n",
           proccess->core,
           proccess->priority,
           proccess->processId,
           repeatedString,
           repeatCount * 2);
  }
  else if (proccess->stride > -1)
  {
    printf("| Core-%d   | Stride: %-8d | %c : %-50s |             %3d\% | \n",
           proccess->core,
           proccess->stride * proccess->executed,
           proccess->processId,
           repeatedString,
           repeatCount * 2);
  }
  else
  {
    printf("| Core-%d   | %-16s | %c : %-50s |             %3d\% | \n",
           proccess->core, " ", proccess->processId, repeatedString, repeatCount * 2);
  }

  free(repeatedString); // Free the memory
  fflush(stdout);       // This is to allow fast logging in the terminal
}

void log_io_proccess_status(struct Process *proccess)
{
  // Get completion percentage of the proccess
  int repeatCount = proccess_io_bar_length(proccess);
  char *repeatedString = repeat_char('#', repeatCount); // This makes malloc()

  // logging the proccess info into the screen
  printf("| I/O      | %-16s | %c : %-50s |             %3d\% | \n",
         " ", proccess->processId, repeatedString, repeatCount * 2);

  free(repeatedString); // Free the memory
  fflush(stdout);       // This is to allow fast logging in the terminal
}

/// @brief Prints the current running proccesses status
/// @param core The core that runs the proccess
void simulate_proccesses()
{

  // For each proccess
  for (size_t i = 0; i < NUM_PROCCSSES; i++)
  {
    /* Checking For waiting proccessings is not implemented yet */

    // If the proccess is executing right now
    if (!processes[i].isExecuted && /* processes[i].executed  > 0 &&*/ processes[i].core > 0)
    {
      // Log the proccess if its currently running, or ready
      log_proccess_status(&processes[i]);

      // If the proccess performs IO, log the IO
      if (processes[i].io_justFinished)
      {
        processes[i].io_justFinished = false;
        log_io_proccess_status(&processes[i]);
      }
      if (processes[i].io_step /* && processes[i].io_executed > 0 */)
      {
        log_io_proccess_status(&processes[i]);
      }
    }

    if (processes[i].justFinished)
    {
      processes[i].justFinished = false;
      log_proccess_status(&processes[i]);
    }
  }
}
