#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

struct data {
    double **elements;
    int *targets;
    struct data_shape{
	    double xcoord;
	    double ycoord;
	    double xcoords;
	    double ycoords;
	    double target;
	    int number_of_examples;
	    int number_of_features;
    } data_shape;
};

struct model {
    double *weights;
    struct model_shape{
	    int weight_dimension;
    } model_shape;

};

Data new_Data(const char *fname)
{
    Data data = (Data) malloc(sizeof(Data));
    data->elements = (double**) malloc(data -> data_shape.number_of_examples * sizeof(double));
    return data;
}

static int load_data(char *fname, Data x, Data y, Data targets) // was static void
{
    FILE *fp;

    if ((fp = fopen(fname, "r")) == NULL)  {
        fprintf(stderr, "load_data: can't open %s\n", fname);
        exit(1);
    }

    int i = 0;
    //while (fscanf(fp, "%lf %lf %lf", &x[i], &y[i], &targets[i]) != EOF)
    while (fscanf(fp, "%lf %lf %lf", &(x->elements[i][]), &(y->elements[][i]), &(targets->elements[i])) != EOF)
        i++;

    fclose(fp);

    fprintf(stdout, "load_data: loaded %d examples\n", i);
}

Model new_Model(const Data data)
{
    Model model = (Model) malloc(sizeof(Model));
    model->weights = (double**) malloc((data->data_shape.number_of_features + 1) * sizeof(double));
    return model;
}

static int initialize_model(Model model) //was static void
{
    for (int i = 0; i < model -> model_shape.weight_dimension; i++)
        model->weights[i] = (double) rand() / RAND_MAX;
}

static void sgd(Model model, Data data)
{
    model->weights[2] += data->data_shape.target * data->data_shape.xcoord;
    model->weights[1] += data->data_shape.target * data->data_shape.ycoord;
    //weights[0] = weights[0];
    model->weights[0] += data->data_shape.target * 1;
}

static int predict(Model model, Data data)
{
    double hypothesis = model->weights[2] * data->data_shape.xcoord + model->weights[1] * data->data_shape.ycoord + model->weights[0];
    return (hypothesis < 0) ? -1 : 1;
}

void fit_model(Model model, Data data)
{
    double hypothesis, target;

    bool misclassified = true;
    while (misclassified) {
        misclassified = false;
        for (int i = 0; i < data->data_shape.number_of_examples; i++) {
            hypothesis = predict(model, data);
            target = targets->elements[i];
            if ((hypothesis > 0 && target > 0) || (hypothesis < 0 && target < 0)) // TODO Handle 0
                continue;
            sgd(model, data);  // Update weights using misclassified point
            misclassified = true;
        }
    }
}

void run_scoring_engine(Model model)
{
    double x, y;

    printf("Enter x: \n");
    scanf("%lf", &x);

    printf("Enter y: \n");
    scanf("%lf", &y);

    printf("Prediction = %d\n", predict(model, Data data));
}
