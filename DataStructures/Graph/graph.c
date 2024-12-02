#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"

// Initialize the graph with vertex names
bool init_graph(graph *graph, char vertexNames[][MAX_NAME_SIZE], int numVertices){

    if (numVertices <= 0 || vertexNames == NULL) return false;

    graph->numVertices = numVertices;
    graph->head = NULL;

    vertex *tail = NULL;

    for (int i = 0; i < numVertices; i++){

        vertex *newVertex = (vertex *) malloc(sizeof(vertex));
        if (!newVertex) return false;

        strcpy(newVertex->name, vertexNames[i]);
        newVertex->link = NULL;
        newVertex->nextVertex = NULL;

        if (!graph->head){

            graph->head = newVertex;
            tail = newVertex;
            continue;
        }

        tail->nextVertex = newVertex;
        tail = newVertex;
    }

    return true;
}

// Add an edge between source and destination vertices with weight
bool add_edge(graph *graph, char *sourceVertex, char *destinationVertex, int weight){

    vertex *currentVertex = graph->head;

    while(currentVertex) {

        if (strcmp(currentVertex->name, sourceVertex) == 0){

            node *newNode = (node *) malloc(sizeof(node));
            if (!newNode) return false;

            strcpy(newNode->name, destinationVertex);
            newNode->weight = weight;
            newNode->next = NULL;

            if (!currentVertex->link) currentVertex->link = newNode;
            else {

                node *lastNode = currentVertex->link;
                while (lastNode->next) lastNode = lastNode->next;

                lastNode->next = newNode;
            }

            return true;
        }

        currentVertex = currentVertex->nextVertex;
    }

    return false;
}

// Display the graph's adjacency list
void print_graph(graph *graph){

    vertex *currentVertex = graph->head;
    node *currentNode;

    while (currentVertex){

        printf("Vertex: %s -> ", currentVertex->name);

        currentNode = currentVertex->link;

        if (currentNode) {

            while (currentNode){

                printf("%s (%d) -> ", currentNode->name, currentNode->weight);
                currentNode = currentNode->next;
            }
        }

        printf("NULL\n");

        currentVertex = currentVertex->nextVertex;
    }
}

// Free dynamically allocated memory for the graph
void free_graph(graph *graph){

    vertex *currentVertex = graph->head;
    vertex *tempVertex;

    node *currentNode, *tempNode;

    while (currentVertex){

        currentNode = currentVertex->link;

        while (currentNode){

            tempNode = currentNode;
            currentNode = currentNode->next;
            free(tempNode);
        }

        tempVertex = currentVertex;
        currentVertex = currentVertex->nextVertex;
        free(tempVertex);
    }
}
