#include <iostream>


typedef struct e_node {
    struct v_node *src, *dest;
    struct e_node *next;
} ENode;


typedef struct v_node {
    int key;
    struct e_node *edges;
} VNode;


typedef struct graph {
    struct v_node *vertex;
    struct e_node *edge;
} Graph;


VNode *graph_search_vertex(Graph *g, int n)
{

}


void graph_insert(Graph *g, int src, int dest)
{

}


void print_grapg(Graph *g)
{

}


int main()
{
    return 0;
}
