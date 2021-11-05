#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT  1024
#define SLIDE_RIGHT 2048

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */