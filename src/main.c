#include <stdio.h>
#include "core/nn.h"

int main (void) {

    printf("C-MENTE\r\n");

    unsigned int layer_node_counts[] = {10, 10, 2};

    nn_network network = nn_create_network(3, &layer_node_counts[0]);

    printf("Network Layer Count: %d\r\n", network.layer_count);

    for (unsigned int i = 0; i < network.layer_count; i++)
    {
        for (unsigned int j = 0; j < network.layers[i].node_count; j++)
        {
            printf("Layer %d Node %d Bias: %f\r\n", i, j, network.layers[i].nodes[j].bias);

            for (unsigned int k = 0; k < network.layers[i].nodes[j].weight_count; k++)
            {
                printf("\tLayer %d Node %d Weight %d: %f\r\n", i, j, k, network.layers[i].nodes[j].weights[k]);
            }
        }
    }

    return (0);
}