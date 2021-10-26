#pragma once

typedef struct List;

typedef struct Position;

List* createList();


void deleteList(List* list);


Position* first(List* list);


Position* next(Position* position);


Position* previous(Position* position);


bool isEnd(Position* position);


void deletePosition(Position* position);


void addBefore(List* list, Position* position);


void addAfter(List* list, Position* position);


void remove(Position* position); //принимает позицию, удаляет элемент, на который она указывает, может удалять и саму позицию тоже


int value(Position* position);


void setValue(Position* position);