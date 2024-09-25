#ifndef MATH_H
#define MATH_H

#include "../data/proccess.h"

int exectued_percentage(int executed, int executionTime);
int process_bar_length(struct Process *process);
int proccess_io_bar_length(struct Process *process);

#endif
