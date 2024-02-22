
#include <stdlib.h>

typedef struct s_trust {
    int trust;
    struct s_trust *next;
} t_trust;

typedef struct s_people {
    int num_of_trust;
    t_trust *head;
} t_people;

t_trust *makeNode(int i)
{
    t_trust *new;
    new = malloc(sizeof(t_trust));
    if (new == NULL)
        return (NULL);
    new->trust = i;
    new->next = NULL;
    return (new);
}

bool searchNode(t_people *person, int search)
{
    t_trust *node = person->head;

    while (node != NULL)
    {
        if (node->trust == search)
            return (true);
        else
            node = node->next;
    }
    return (false);
}

void addNode(t_people *person, int trust)
{
    t_trust *new = makeNode(trust);
    t_trust *node = person->head;

    if (node == NULL)
    {
        person->head = new;
        return;
    }

    while (node->next != NULL)
        node = node->next;

    node->next = new;
}

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    t_people ppl[n];

    for (int i=0; i<n; i++)
    {
        ppl[i].num_of_trust = 0;
        ppl[i].head = NULL;
    }
    for (int i=0; i<trustSize; i++)
    {
        ppl[trust[i][0]-1].num_of_trust++;
        addNode(&ppl[trust[i][0]-1], trust[i][1]-1);
    }
    int onejudge = -1;
    for (int i=0; i<n; i++)
    {
        if (onejudge != -1 && ppl[i].num_of_trust == 0)
            return (-1);
        else if (ppl[i].num_of_trust == 0)
            onejudge = i;
    }
    if (onejudge == -1)
        return (-1);
    else
    {
        for (int i=0; i<n; i++)
        {
            if (i == onejudge)
                continue;
            else if (searchNode(&ppl[i], onejudge) == true)
                continue;
            else
                return (-1);
        }
        return (onejudge+1);
    }
    return (-1);
}
