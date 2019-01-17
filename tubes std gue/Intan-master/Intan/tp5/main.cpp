#include <iostream>
#include "coba.h"
using namespace std;

int main()
{
    address tnn;
    int i = 6;
    mhs a;
    list gg;
    create_list(gg);
    while(i>0)
    {
        insert_sort(gg);
    i--;
    }

    cout<<"------------PRINT---------"<<endl;
    show_list(gg);
    tnn = find_old(gg);
    cout<<endl;
    cout<<info(tnn).name<<" paling tua";
    cout<<endl;
    group_average(gg);
    return 0;
}
