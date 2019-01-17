#include "tubesintan.h"

void create_list_dll(list_orang &LO){
    LO.first = NULL;
    LO.last = NULL;
}

address_orang alokasi_dll(infotype_orang data){
    address_orang AO = new elmlist_orang;
    AO->info.id = data.id;
    AO->info.nama = data.nama;
    AO->info.tanggallahir.tanggal = data.tanggallahir.tanggal;
    AO->info.tanggallahir.bulan = data.tanggallahir.bulan;
    AO->info.tanggallahir.tahun = data.tanggallahir.tahun;
    AO->next = NULL;
    AO->prev = NULL;

}

void dealokasi_dll(address_orang AO){
    delete AO;
    AO = NULL;
}

void insert_first_dll(list_orang &LO, address_orang AO){

    if(LO.first == NULL){

        cout<<"Brama";
        system("PAUSE");


        LO.first = AO;
        LO.last = AO;
    }else {
        LO.first->prev = AO;
        AO->next = LO.first;
        LO.first = AO;
    }

}

/*void delete_after_dll(list_orang LO, address_orang prec, address_orang AO){
    if (LO.first!=LO.last){
        AO = next(prec);
        next(prec) = next(AO);
        prev(next(AO)) = prec;
        next(AO) = NIL;
        prev(AO) = NIL;
    }
    else{
        LO.first = NIL;
        LO.last = NIL;
    }
}*/

void view_list_dll(list_orang LO){
    list_orang LO1 = LO;
    //if(LO1.first == NIL){
     //   cout << "List Kosong";
    //} else {
        while(LO1.first->next != NULL){
            cout<<"Intan"<<endl;
            cout <<LO1.first->info.id<< endl;
            cout <<LO1.first->info.nama<< endl;
            cout <<LO1.first->info.tanggallahir.tanggal<< endl;
            cout <<LO1.first->info.tanggallahir.bulan<< endl;
            cout <<LO1.first->info.tanggallahir.tahun<< endl;
            LO1.first = LO1.first->next;
            system("PAUSE");
        }
            cout<<"Tante Intan"<<endl;
            cout <<LO1.first->info.id<< endl;
            cout <<LO1.first->info.nama<< endl;
            cout <<LO1.first->info.tanggallahir.tanggal<< endl;
            cout <<LO1.first->info.tanggallahir.bulan<< endl;
            cout <<LO1.first->info.tanggallahir.tahun<< endl;

    system("PAUSE");
    //}
}
