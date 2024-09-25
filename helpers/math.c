#include "../interfaces/data/proccess.h"

/// @brief Getting the percentage between two numbers in integar format
/// @bug No check for zero denominator value
/// @param numerator
/// @param denominator
/// @return (numerator * 100) / denominator
int exectued_percentage(int numerator, int denominator)
{
  return numerator * 100 / denominator;
}

/// @brief Getting the number of `#` we used to print to express the proccess executed percentage
/// @param process the proccess we will calculate the value for
/// @return percentage / 2 (as we have only 50 place)
int process_bar_length(struct Process *process)
{
  int percent = exectued_percentage(process->executed, process->executionTime);
  int barLength = percent / 2;

  return barLength;
}

int proccess_io_bar_length(struct Process *process)
{
  int percent = exectued_percentage(process->io_executed, IO_TIME);
  int barLength = (int)(percent / 2);

  return barLength;
}