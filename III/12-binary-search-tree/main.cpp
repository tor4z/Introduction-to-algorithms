#include <iostream>

typedef struct node {
    int key;
    struct node *right, *left, *p;
} Node;


void bstree_insert(Node **root, int x)
{
    if ((*root) == NULL)
    {
        *root = new Node{x, NULL, NULL, NULL};
    } else {
        Node *tmp = *root;

        while (tmp != NULL)
        {
            if(tmp->key > x)
                if(tmp->left == NULL)
                {
                    tmp->left = new Node{x, NULL, NULL, tmp};
                    break;
                }
                else
                    tmp = tmp->left;
            else
                if(tmp->right == NULL)
                {
                    tmp->right = new Node{x, NULL, NULL, tmp};
                    break;
                }
                else
                    tmp = tmp->right;
        }
    }
}


Node *bstree_iterative_search(Node *root, int x)
{
    while (root != NULL)
    {
        if(root->key == x)
            return root;
        else if (root->key > x)
            root = root-> left;
        else
            root = root->right;
    }
    // not found
    return NULL;
}


Node *bstree_search(Node *root, int x)
{
    if(root == NULL)
        return NULL;
    else if (root->key > x)
        return bstree_search(root->left, x);
    else if (root->key == x)
        return root;
    else
        return bstree_search(root->right, x);
}


void bstree_inorder_walk(Node *root)
{
    if(root != NULL)
    {
        if (root->left != NULL)
            bstree_inorder_walk(root->left);
            std::cout << root->key << " ";
            bstree_inorder_walk(root->right);
    }
}


Node *bstree_max(Node* root)
{
    if(root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

Node *bstree_min(Node *root)
{
    if(root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}


Node *bstree_predecessor(Node *node)
{
    if(node == NULL)
        return NULL;
    if(node -> left != NULL)
    {
        node = node->left;
        while (node->right != NULL)
            node = node->right;
        return node;
    } else {
        Node *p = node->p;
        if(p->left == node)
            return p;
        else
            return NULL;
    }
}


Node *bstree_successor(Node *node)
{
    if(node == NULL)
        return NULL;
    if (node->right != NULL)
    {
        node = node->right;
        while (node->left != NULL)
            node = node->left;
        return node;
    } else {
        Node *p = node->p;
        while (p != NULL && p->right == node)
        {
            node = p;
            p = node->p;
        }
        return p;
    }
}


void bstree_delete(Node *root, Node *node)
{

}


int main()
{
    Node *root = NULL;
    int n = 8;
    int array [] = {
        1, 2, 5, 6, 8, 7, 4, 3
    };
    
    // insert array into tree
    for (size_t i = 0; i < n; i++)
    {
        bstree_insert(&root, array[i]);
    }
    
    // walk tree
    bstree_inorder_walk(root);
    std::cout << std::endl;
    
    // search tree
    Node *result;

    result = bstree_search(root, 6);
    if(result == NULL)
        std::cout << "Node not found." << std::endl;
    else
        std::cout << "search result for 6: " << result->key << std::endl;

    result = bstree_iterative_search(root, 6);
    if(result == NULL)
        std::cout << "Node not found." << std::endl;
    else
        std::cout << "search result for 6: " << result->key << std::endl;

    // max node
    Node *max_node = bstree_max(root);
    if(max_node == NULL)
        std::cout << "Empty tree." << std::endl;
    else
        std::cout << "Max node: " << max_node->key << std::endl;


    // min node
    Node *min_node = bstree_min(root);
    if(min_node == NULL)
        std::cout << "Empty tree." << std::endl;
    else
        std::cout << "Min node: " << min_node->key << std::endl;

    // find predecessor and successor
    Node *predecessor;
    Node *successor;
    Node *target = bstree_search(root, 5);
    predecessor = bstree_predecessor(target);
    successor = bstree_successor(target);
    std::cout << "predecessor of target(5): " << predecessor-> key << std::endl;
    std::cout << "successor of target(5): " << successor-> key << std::endl;
    return 0;
}
