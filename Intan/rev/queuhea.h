#ifndef QUEUHEA_H_INCLUDED
#define QUEUHEA_H_INCLUDED

#include <iostream>
using namespace std;

struct arr_queue{
    int info[4];
    int head,tail;
};

void createQueue(arr_queue *q);
bool isEmpty(arr_queue q);
bool isFull(arr_queue q);
void enqueue(int elm, arr_queue *q);
int dequeue(arr_queue *q);
void viewQueue(arr_queue *q);
void splitQueue(arr_queue *q,arr_queue *r,arr_queue *s)

#endif // QUEUHEA_H_INCLUDED
