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


void graph_bfs(Graph *g, int start)
{
    int visited [MAX_NODE];
    VNode *queue[MAX_NODE];
    int q_head=0, q_tail=0;
    VNode *vertex = graph_search_insert_vertex(g, start);
    ENode *edge;

    for (size_t i = 0; i < MAX_NODE; i++)
    {
        visited[i] = 0;
        queue[i] = NULL;
    }
    // enqueue
    queue[q_head] = vertex;
    ++q_head;
    while (q_tail < q_head)
    {
        // dequeue
        vertex = queue[q_tail];
        ++q_tail;
        visited[vertex->key] = 1;
        std::cout << vertex->key << " ";
        edge = vertex->edges;
        while (edge != NULL)
        {
            // enqueue
            if(visited[edge->dest->key] == 0)
            {
                queue[q_head] = edge->dest;
                ++q_head;
                edge = edge->next;
            }
        }
    }
    std::cout << std::endl;
}


int main()
{
    /*
            1
           / \
          2   3
          \
           4
    */
    Graph *g = new Graph{NULL};
    graph_insert(g, 1, 2);
    graph_insert(g, 1, 3);
    graph_insert(g, 2, 4);
    print_grapg(g);
    graph_bfs(g, 1);
    return 0;
}
