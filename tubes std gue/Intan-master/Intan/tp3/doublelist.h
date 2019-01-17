#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED

#include <cstddef>

#define Nil NULL

#define info(A) A->info
#define next(A) A->next
#define prev(A) A->prev
#define first(A) A.first
#define last(A) A.last

typedef int infotype;
typedef struct elmlist *address;

struct elmlist{
        infotype info;
        address next;
        address prev;
};

struct List{
    address first;
    address last;
};

void create_list(List &L);
address alokasi(infotype data);
void dealokasi(address &p);
void insertFirst(List &L, address p);
void insertLast(List &L, address p);
void deleteFirst(List &L, address &p);
void deleteLast(List &L, address &p);
void printInfo(List L);
void angkaTerbesar(List L, List L2);
void sorting(List L);
void membagi(List L);

#endif // DOUBLELIST_H_INCLUDED
