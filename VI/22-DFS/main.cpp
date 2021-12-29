#include <iostream>

#define MAX_NODE 100

typedef struct e_node {
    struct v_node *src;
    struct v_node *dest;
    struct e_node *next;
} ENode;


typedef struct v_node {
    int key;
    struct v_node *next;
    struct e_node *edges;
} VNode;


typedef struct graph {
    struct v_node *vertex;
} Graph;


VNode *graph_search_insert_vertex(Graph *g, int n)
{
    VNode *head = g->vertex;
    while (head != NULL)
    {
        if(head->key == n)
            return head;
        else
            head = head->next;
    }
    // insert new vertex node
    VNode *new_node = new VNode{n, NULL, NULL};
    new_node->next = g->vertex;
    g->vertex = new_node;
    return new_node;
}


void graph_insert(Graph *g, int src, int dest)
{
    VNode *src_node = graph_search_insert_vertex(g, src);
    VNode *dest_node = graph_search_insert_vertex(g, dest);

    ENode *new_edge = new ENode{src_node, dest_node, src_node->edges};
    src_node->edges = new_edge;
}


void print_grapg(Graph *g)
{
    // print vertex list
    VNode *v_node = g->vertex;
    while (v_node != NULL)
    {
        std::cout << v_node->key << " ";
        v_node = v_node->next;
    }
    std::cout << std::endl;
}


void dfs(VNode *vertex, int *visited)
{
    ENode *edge = vertex->edges;
    visited[vertex->key] = 1;
    std::cout << vertex->key << " ";
    while (edge != NULL)
    {
        if (visited[edge->dest->key]==0)
            dfs(edge->dest, visited);
        edge = edge->next;
    }
}

void graph_dfs(Graph *g, int start)
{
    int visited [MAX_NODE];
    VNode *vertex = graph_search_insert_vertex(g, start);

    for (size_t i = 0; i < MAX_NODE; i++)
        visited[i] = 0;
    
    dfs(vertex, visited);

    std::cout << std::endl;
}


int main()
{
    /*
             1
           /  \
          2    3
          \    |
           4 - 9
    */
    Graph *g = new Graph{NULL};
    graph_insert(g, 1, 2);
    graph_insert(g, 1, 3);
    graph_insert(g, 2, 4);
    graph_insert(g, 3, 9);
    graph_insert(g, 4, 9);
    print_grapg(g);
    graph_dfs(g, 1);
    return 0;
}
