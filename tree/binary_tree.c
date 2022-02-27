#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *create(int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void add(Node *node, int value)
{
    if (value < node->value)
    {
        if (!node->left)
        {
            node->left = create(value);
        }
        else
        {
            add(node->left, value);
        }
    }
    else
    {
        if (!node->right)
        {
            node->right = create(value);
        }
        else
        {
            add(node->right, value);
        }
    }
}

void del(Node *node, int value)
{
    Node *child = node;
    Node *parent;

    do
    {
        parent = child;
        if (value < child->value)
        {
            child = child->left;
        }
        else if (value > child->value)
        {
            child = child->right;
        }
    } while (child && child->value != value);

    if (child)
    {
        if (!child->left && !child->right) // not childrens
        {
            if (parent->left == child)
                parent->left = NULL;
            if (parent->right == child)
                parent->right = NULL;
        }

        if (child->left && !child->right) // left children
        {
            if (parent->left == child)
                parent->left = child->left;
            if (parent->right == child)
                parent->right = child->left;
        }

        if (!child->left && child->right) // right children
        {
            if (parent->left == child)
                parent->left = child->right;
            if (parent->right == child)
                parent->right = child->right;
        }

        if (child->left && child->right) // two childrens
            if (!child->left->right)
            {
                child->value = child->left->value;
                child->left = NULL;
            }
            else
            {
                Node *current = child->left;
                Node *aux = current;

                while (current->right)
                {
                    aux = current;
                    current = current->right;
                }
                aux->right = NULL;
                child->value = current->value;
            }
    }
}

void print(Node *node)
{
    if (!node)
    {
        return;
    }
    print(node->left);
    printf("%d\n", node->value);
    print(node->right);
}

void main()
{
    Node *root = create(5);
    add(root, 3);
    add(root, 1);
    add(root, 4);
    add(root, 2);
    add(root, 8);

    del(root, 3);

    print(root);
}