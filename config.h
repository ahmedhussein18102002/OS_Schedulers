#ifndef CONFIG_H
#define CONFIG_H

// #define NUM_PROCCSSES 8 // The number of running proccesses. (NOTE: you should initialze them all)
#define STEP 500000 // 0.5 second (STEP duration)
#define NUM_CORES 1 // Number of cores (each core can run only one proccess at a STEP)
#define IO_TIME 3   // 3 steps for the I/O operation

// MLFQ MACROS
#define MAX_PRIORITY 2   // The number of priotiry queues + 1
#define PRIORITY_BOOST 5 // Number of steps after which all proccess will go to the top priority queue

#endif
