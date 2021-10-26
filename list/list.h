#pragma once

#include <stdbool.h>

typedef struct List;

typedef struct Position;

List* createList();


void deleteList(List* list);


Position* first(List* list);


Position* next(Position* position);


Position* previous(Position* position);


Position* last(Position* position);


bool isEnd(Position* position);


void deletePosition(Position* position);


void addBefore(List* list, Position* position, int value);


void addAfter(List* list, Position* position, int value);


void remove(Position* position); //принимает позицию, удаляет элемент, на который она указывает, может удалять и саму позицию тоже


int value(Position* position);


void setValue(Position* position, int value);