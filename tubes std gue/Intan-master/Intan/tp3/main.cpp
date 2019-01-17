#include <iostream>
#include "doublelist.h"

using namespace std;

int main()
{
    List L;
    List L2;

    create_list(L);
    create_list(L2);

    address p = Nil;

    insertFirst(L,alokasi(1));
    insertFirst(L,alokasi(4));
    insertFirst(L,alokasi(9));
    insertFirst(L,alokasi(8));
    insertFirst(L,alokasi(5));
    insertFirst(L,alokasi(2));
    insertFirst(L,alokasi(6));
    insertFirst(L,alokasi(3));
    printInfo(L);

   /* insertFirst(L2,alokasi(6));
    insertFirst(L2,alokasi(7));
    insertFirst(L2,alokasi(2));
    insertFirst(L2,alokasi(3));
    insertFirst(L2,alokasi(1));
    insertFirst(L2,alokasi(3));
    insertFirst(L2,alokasi(5));
    printInfo(L2);*/


   // angkaTerbesar(L,L2);

    sorting(L);
//    membagi(L);

return 0;
}
