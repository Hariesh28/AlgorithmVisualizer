#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX_NAME_SIZE 10

// Define the edges
typedef struct node {
    char name[MAX_NAME_SIZE];
    int weight;
    struct node *next;
} node;

// Define the Vertex
typedef struct vertex {
    char name[MAX_NAME_SIZE];
    struct node *link;
    struct vertex *nextVertex;
} vertex;

// Define the Adjacency List
typedef struct {
    int numVertices;
    vertex *head;
} graph;

// Function declarations
bool init_graph(graph *graph, char vertexNames[][MAX_NAME_SIZE], int numVertices);
bool add_edge(graph *graph, char *sourceVertex, char *destinationVertex, int weight);
void print_graph(graph *graph);
void free_graph(graph *graph);

#endif
