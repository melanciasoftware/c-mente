#ifndef CORE_NN_H_
#define CORE_NN_H_

#include <stdlib.h>

typedef struct nn_node
{
    double output;
    double* weights;
    unsigned int weight_count;
    double bias;
    double gradient;
} nn_node;

typedef struct nn_layer
{
    unsigned int node_count;
    nn_node* nodes;
} nn_layer;

typedef struct nn_network
{
    unsigned int layer_count;
    nn_layer* layers;
} nn_network;

nn_node nn_create_node (unsigned int output_layer_count);
nn_layer nn_create_layer (unsigned int node_count, unsigned int output_layer_count);
nn_network nn_create_network (unsigned int layer_count, unsigned int* layer_node_counts);
void nn_destroy_node (nn_node* node);
void nn_destroy_layer (nn_layer* layer);
void nn_destroy_network (nn_network* network);

#endif // CORE_NN_H_