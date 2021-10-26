#include "list.h"
#include <stdio.h>

typedef struct ListElement
{
    int value;
    struct ListElement* next;
    struct ListElement* previous;
} ListElement;

typedef struct List
{
    ListElement* head;
} List;

typedef struct Position
{
    ListElement* position;
} Position;

Position* first(List* list)
{
    Position* positionFirst = malloc(sizeof(Position));
    positionFirst->position = list->head;
    return positionFirst;
}

Position* next(Position* position)
{
    Position* newPosition = malloc(sizeof(Position));
    newPosition->position = position->position->next;
    return newPosition;
}

Position* previous(Position* position)
{
    Position* newPosition = malloc(sizeof(Position));
    newPosition->position = position->position->previous;
    return newPosition;
}

void remove(Position* position)
{
    position->position->previous->next = position->position->next;
    position->position->next->previous = position->position->previous;
    free(position);
}

// Not ready
void addBefore(List* list, Position* position, int value)
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->value = value;
    if (first(list) == NULL)
    {
        list->head = newElement;
        return;
    }
    newElement->next = position->position->next;
    position->position->next = newElement;
}