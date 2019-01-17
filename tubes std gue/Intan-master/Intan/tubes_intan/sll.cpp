#include "tubesintan.h"

address_pendidikan alokasi_sll(infotype_pendidikan data){
    address_pendidikan AP = new elmlist_pendidikan;
    AP->info.id = data.id;
    AP->info.kepanjangan = data.kepanjangan;
    AP->info.singkatan = data.singkatan;
    AP->next = NULL;
    return AP;
}

void create_list_sll(list_pendidikan &LP){
    LP.first = NULL;
}

void insert_last_sll(list_pendidikan &LP,address_pendidikan AP){
    if(LP.first == NULL){
        LP.first = AP;
    }
    else
        {
        address_pendidikan q = LP.first;
        while (q->next != NULL)
            {
            q = q->next;
        }
        q->next = AP;
    }
}

/*void delete_after_sll(list_pendidikan LP, address_pendidikan AP){
    address_pendidikan q = LP.first;
    while (q->info!=b){
        q = q->next;
    }
    AP = q->next;
    q->next = AP->next;
    AP->next = NIL;
}*/

void view_list_sll(list_pendidikan LP){
    list_pendidikan LP1 = LP;


    while (LP1.first!= NULL)
        {
        cout<<LP1.first->info.id<<endl;
        cout<<LP1.first->info.kepanjangan<<endl;
        cout<<LP1.first->info.singkatan<<endl;
        LP1.first = LP1.first->next;
    }
    cout<<"Brama";
    system("PAUSE");

}
