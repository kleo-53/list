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

int value(Position* position)
{
    return position->position->value;
}

void setValue(Position* position, int value)
{
    position->position->value = value;
}

