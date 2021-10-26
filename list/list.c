#include <stdio.h>
#include <stdbool.h>
#include "list.h"

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


List* createList()
{
    return calloc(1, sizeof(List));
}

void deleteList(List* list)
{
    ListElement* position = list->head;
    while (position != NULL)
    {
        list->head = list->head->next;
        free(position);
        position = list->head;
    }
    free(list);
}

Position* last(List* list)
{
    Position* currentPosition = first(&list);
    while (currentPosition->position->next != NULL)
    {
        currentPosition->position = currentPosition->position->next;
    }
    return currentPosition;
}

bool isEnd(Position* position)
{
    return position->position == NULL || position->position->next == NULL || position->position->previous == NULL;
}


void addAfter(List* list, Position* position, int value) // not ready 
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->value = value;
    if (first(&list) == NULL)
    {
        list->head = newElement;
        return;
    }
    newElement->next = position->position->next;
    position->position->next = newElement;
}