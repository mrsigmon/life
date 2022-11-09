#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define DIMENSIONS 3
#define MAX_ITERATIONS 100000

void load_data(char *fname, double xcoords[], double ycoords[], double targets[]);
void initialize(double weights[]);

void fit(double weights[], double xcoords[], double ycoords[], double targets[], int number_of_examples);

int predict(double weights[], double xcoord, double ycoord);
void run_scoring_engine(double weights[]);

#endif
