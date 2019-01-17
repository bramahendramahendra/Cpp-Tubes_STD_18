#include <iostream>
#include "tp4.h"

using namespace std;

int main()
{
         // membuat suatu list kosong +++++++++++++++++++++++++++++++++++++++++++++++
    list L;
    list L2;
    list L3;
    address P = NIL;
    create_list(L);
    create_list(L2);
    create_list(L3);
    insert_first(L,alokasi(1));
    insert_first(L,alokasi(4));
    insert_first(L,alokasi(9));
    insert_first(L,alokasi(8));
    insert_first(L,alokasi(5));
    insert_first(L,alokasi(2));
    insert_first(L,alokasi(6));
    insert_first(L,alokasi(3));

    print_info(L);
    cout<<endl;
    membagi(L);
    return 0;
}
