#include <iostream>


typedef struct node {
    int red;    // 0 for black, 1 for red
    int value;
    struct node *left;
    struct node *right;
    struct node *p;
} Node;


void left_rotate(Node *node)
{
    if(node->p != NULL)
    {
        if(node->p->left == node)
            node->p->left = node->right;
        else
            node->p->right = node->right;
    }

    node->right->p = node->p;
    node->p = node->right;
    node->right = node->right->left;
    node->right->left->p = node;
    node->right->left = node;
}


void right_rotate(Node *node)
{
    if(node->p != NULL)
    {
        if(node->p->left == node)
            node->p->left = node->left;
        else
            node->p->right = node->left;
    }

    node->left->p = node->p;
    node->p = node->left;
    node->left = node->left->right;
    node->left->right->p = node;
    node->left->right = node;
}


void insert_fixup(Node *node)
{

}


void insert(Node **root, int x)
{
    Node *p = NULL, *curr = *root;
    Node *node = new Node();
    node->value = x;
    node->red = 1;
    node->p = NULL;
    node->left = NULL;
    node->right = NULL;

    if(*root == NULL)
    {
        // the tree is empty
        *root = node;
        node->red = 0;
    }
    else
    {
        while (curr != NULL)
        {
            p = curr;
            if(curr->value <= x)
                curr = curr->right;
            else
                curr = curr->left;
        }
        node->p = p;
        if(p->value <= x)
            p->right = node;
        else
            p->left = node;
    }   insert_fixup(node);
}


int main()
{

    return 0;
}
