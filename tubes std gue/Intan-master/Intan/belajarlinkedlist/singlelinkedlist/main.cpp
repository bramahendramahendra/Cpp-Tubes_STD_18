#include <iostream>
#include "list1.h"

using namespace std;

int main()
{
    // membuat suatu list kosong +++++++++++++++++++++++++++++++++++++++++++++++
    list L;
    create_list(L);
    insert_first(L,5);
    insert_first(L,10);
    insert_last(L,7);
    insert_last(L,2);
    insert_last(L,4);
    insert_last(L,1);
    insert_first(L,18);
    cout<<"urutan seharusnya: 18 10 5 7 2 4 1"<<endl;
    view_list(L);
    delete_first(L);
    delete_last(L);
    cout<<"urutan seharusnya: 10 5 7 2 4"<<endl;
    view_list(L);

    return 0;
}
