#ifndef COBA_H_INCLUDED
#define COBA_H_INCLUDED

using namespace std;
#include <iostream>

#define first(A) A.first
#define next(A) A->next
#define info(A) A->info
#define null NULL

struct mhs{
    int id,age;
    string name;
    char group;
    float score;
};

typedef mhs infotype;
typedef struct node *address;

struct node{
    infotype info;
    address next;
};


struct list{
    address first;
};


address alokasi(infotype data);
void create_list(list &l);
void dealokasi(address &p);
void show_list(list l);
address get_last(list l);
address search_node(list l,int x); //cari score
address find_old(list l);
void insert_first(list &l, address p);
void insert_after(list &l, address prec, address p);//kerjain
void insert_last(list &l, address p);//kerjain

void insert_sort(list &l);//kerjain
void group_average(list l);

void delete_first(list &l,address &p);
#endif // COBA_H_INCLUDED
