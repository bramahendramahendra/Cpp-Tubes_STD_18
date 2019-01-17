#include "tubesintan.h"

void create_list_cdll(list_ambil &LA){
    LA.first = NULL;
    LA.last = NULL;
}

address_ambil alokasi_cdll(infotype_ambil data){
    address_ambil AA = new elmlist_ambil;
    AA->info = data;
    AA->next = NULL;
    AA->prev = NULL;
    return AA;
}

void dealokasi_cdll(list_ambil LA, address_ambil AA){
    delete(AA);
    AA = NULL;
}


void insert_after_cdll(list_ambil &LA, address_ambil AA){
    if ((LA.first == NULL) && (LA.last == NULL)){
        LA.first = AA;
        LA.last = AA;
    }
    else{
        if ((LA.first->next == NULL) && (LA.first->prev == NULL)){
            if (LA.first->info.id_orang > AA->info.id_orang){
                LA.first->prev = AA;
                AA->next = LA.first;
                LA.first = AA;
            }
            else if (LA.first->info.id_orang < AA->info.id_orang){
                LA.last->next = AA;
                AA->prev = LA.last;
                LA.last = AA;
            }
            else{
                if (LA.first->info.id_pendidikan > AA->info.id_pendidikan){
                    LA.first->prev = AA;
                    AA->next = LA.first;
                    LA.first = AA;
                }
                else{
                    LA.last->next = AA;
                    AA->prev = LA.last;
                    LA.last = AA;
                }
            }
        }
        else if (LA.first->info.id_orang > AA->info.id_orang) {
            LA.first->prev = AA;
            AA->next = LA.first;
            LA.first = AA;
        }
        else if (LA.first->info.id_orang < AA->info.id_orang){
            LA.last->next = AA;
            AA->prev = LA.last;
            LA.last = AA;
        }
        else{
            if ((LA.first->info.id_pendidikan > AA->info.id_pendidikan) && (LA.first->info.id_orang == AA->info.id_orang)){
                LA.first->prev = AA;
                AA->next = LA.first;
                LA.first = AA;
            }
            else if ((LA.first->info.id_pendidikan < AA->info.id_pendidikan)&& (LA.first->info.id_orang == AA->info.id_orang)){
                LA.last->next = AA;
                AA->prev = LA.last;
                LA.last = AA;
            }
            else{
                address_ambil AA2 = LA.first;
                while (AA->info.id_orang > AA2->info.id_orang){
                    AA2 = AA2->next;
                }
                if (AA->info.id_orang == AA2->info.id_orang){
                    while(AA->info.id_pendidikan == AA2->info.id_pendidikan)
                    {
                        AA2 = AA2->next;
                    }
                    AA->prev = AA2->prev;
                    AA->next = AA2;
                    AA2->prev->next = AA;
                    AA2->prev = AA;
                }
                else
                {
                    AA->prev = AA2->prev;
                    AA->next = AA2;
                    AA2->prev->next = AA;
                    AA2->prev = AA;
                }
            }
        }
    }
}

void delete_first_cdll(list_ambil LA, address_ambil AA){
    if (LA.first!=LA.last){
        AA = LA.first;
        LA.first = AA->next;
        LA.last->next = LA.first;
        LA.first->prev = LA.last;
        AA->next = NULL;
        AA->prev = NULL;
    }
    else{
        AA = LA.first;
        AA->next = NULL;
        AA->prev = NULL;
        LA.first = NULL;
        LA.last = NULL;
    }
}

void delete_last_cdll(list_ambil LA, address_ambil AA){
    if (LA.first!=LA.last){
        AA = LA.last;
        LA.last = AA->prev;
        LA.last->next = LA.first;
        LA.first->prev = LA.last;
        AA->next = NULL;
        AA->prev = NULL;
    }
    else{
        AA = LA.first;
        AA->next = NULL;
        AA->prev = NULL;
        LA.first = NULL;
        LA.last = NULL;
    }
}

/*void delete_after_cdll(list_ambil LA, address_ambil AA, address_ambil prec){
    if (LA.first!=NIL && LA.last!=NIL){
        if (LA.first!=LA.last){
            AA = prec->next;
            if (AA == LA.first){
                delete_first_cdll(LA,AA);
            }
            else if (AA == LA.last){
                delete_last_cdll(LA,AA);
            }
            else{
                AA = next(prec);
                next(prec)= next(AA);
                prev(next(AA)) = prec;
                next(AA) = NIL;
                prev(AA) = NIL;
            }
        }
        else{
            delete_first_cdll(LA,AA);
        }
    }
}*/

void view_list_cdll(list_ambil LA){
      if (LA.first == NULL){
        cout<<"list kosong";
      }
      else{
      address_ambil AA = LA.first;
            while (AA != NULL){
                cout<<AA->info.id_orang<<endl;
                cout<<AA->info.id_pendidikan<<endl;
                AA = AA->next;
            }
            cout<<AA->info.id_orang<<endl;
            cout<<AA->info.id_pendidikan<<endl;
    }
}
