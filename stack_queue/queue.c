#include <stdio.h>
#include <stdlib.h>

struct user
{
    int password;
    struct user *next;
};

typedef struct user User;

User *queue;

void add(int password)
{
    User *user = (User *)malloc(sizeof(User));
    user->password = password;
    user->next = NULL;

    if (!queue)
    {
        queue = user;
    }
    else
    {
        User *auxQueue = queue;
        while (auxQueue->next)
        {
            auxQueue = auxQueue->next;
        }
        auxQueue->next = user;
    }
}

void del()
{
    if (!queue)
    {
        printf("Fila vazia.");
    }
    else
    {
        queue = queue->next;
    }
}

void print(User *user)
{
    if (user)
    {
        printf("Senha: %d\n", user->password);
        print(user->next);
    }
}

void main()
{
    add(1598);
    add(9632);
    add(5367);
    add(2018);
    del();

    User *auxQueue = queue;
    print(auxQueue);
}