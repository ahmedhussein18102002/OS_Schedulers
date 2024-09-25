// Checking if the header is already been declared or not
// This is importnat to prevent redeclaration of the same Macros more than one time
#ifndef PRINTER_H
#define PRINTER_H

#include "../data/proccess.h"

void print_line(char c);
void print_table_titles();
void print_proccess_into(struct Process *process);
void print_report();

#endif
