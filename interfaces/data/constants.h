#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdbool.h>
#include "../../config.h"

extern int NUM_PROCCSSES;
extern int __schedular_availableCore;
extern int __schedular_executedProccesses;
extern int currentStep;

extern _Bool __running_cores[NUM_CORES];

void initializeRunningCores();

#endif