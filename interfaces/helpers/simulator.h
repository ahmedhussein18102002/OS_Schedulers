#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../data/proccess.h"
#include "../helpers/math.h"
#include "../helpers/utils.h"

void simulate_line(char c);

void simulate_table_titles();

void simulate_proccesses();

void log_proccess_status(struct Process *proccess);

void log_io_proccess_status(struct Process *proccess);

#endif