#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdlib.h>
#include <stdio.h>

int advanced_binary(int *array, size_t size, int value);
int rec(int *array, int *copy, size_t size, int value);

#endif