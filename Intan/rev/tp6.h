#ifndef TP6_H_INCLUDED
#define TP6_H_INCLUDED
#include <iostream>
using namespace std;

struct arr_buku{
    int ID_buku;
    string judul_buku;
    string nama_pengarang;
};

struct arr_stack{
    arr_buku info[4];
    int top;
};

void createStack(arr_stack *s);
bool isEmpty(arr_stack s);
bool isFull(arr_stack s);
void push_stack(arr_buku elm, arr_stack *s);
arr_buku pop_stack(arr_stack *s);
void peek(arr_stack s);
void viewStack(arr_stack *s);
void inversStack(arr_stack *s);

#endif // TP6_H_INCLUDED
