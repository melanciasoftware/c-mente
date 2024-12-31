#include "nn.h";

nn_node nn_create_node (unsigned int output_layer_count)
{
    nn_node node;
    node.output = 0.0;
    node.bias = ((double) rand() / (RAND_MAX)) - 0.5;
    node.gradient = 0.0;
    node.weight_count = output_layer_count;
    node.weights = (double*) malloc(output_layer_count * sizeof(double));

    for (unsigned int i = 0; i < output_layer_count; i++)
    {
        node.weights[i] = ((double) rand() / (RAND_MAX)) - 0.5;
    }

    return node;
}

nn_layer nn_create_layer (unsigned int node_count, unsigned int output_layer_count)
{
    nn_layer layer;
    layer.node_count = node_count;
    layer.nodes = (nn_node*) malloc(node_count * sizeof(nn_node));
    for (unsigned int i = 0; i < node_count; i++)
    {
        layer.nodes[i] = nn_create_node(output_layer_count);
    }
    return layer;
}

nn_network nn_create_network (unsigned int layer_count, unsigned int* layer_node_counts)
{
    nn_network network;
    network.layer_count = layer_count;
    network.layers = (nn_layer*) malloc(layer_count * sizeof(nn_layer));
    for (unsigned int i = 0; i < layer_count; i++)
    {
        unsigned int next_layer_count = (i == layer_count - 1) ? 0 : layer_node_counts[i + 1];
        network.layers[i] = nn_create_layer(layer_node_counts[i], next_layer_count);
    }
    return network;
}