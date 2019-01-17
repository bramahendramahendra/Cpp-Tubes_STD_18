#include <iostream>
#include "tp4.h"

using namespace std;

address alokasi(infotype data){
/*  IS. terdefinisi suatu data yang akan dialokasikan di dalam memori,
    FS. mengahsilkan pointer p yang mengaju ke data baru, teralokasi kedalam memori */
    address p = new elmlist;
    info(p) = data;
    next(p) = NIL;
    return p;
}

void dealokasi(list l, address &p){
/* IS. terdefinisi suatu data yang telah dialokaikan didalam memori,
   FS. menunjuk suatu data dengan pointer p, dan menghapusnya, terdealokasi dari memori*/
    delete(p);
}
void create_list(list &l){
/*  IS. sembarang,
    FS. terbentuk list l dengan first adalah NIL */
    first(l) = NIL;
}

void print_info(list &l){
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. menampilkan isi keseluruhan dari list l */
      if (first(l) == NULL){
        cout<<"list kosong";
      }
      else{
      address p = first(l);
            while (p != NIL){
                cout<<info(p)<<" ("<<p<<"), "<<endl;
                p = next(p);
            }
            cout<<info(p)<<"("<<p<<"),"<<endl;
    }
}

void insert_first(list &l,address p){
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. data ditambahakan menjadi elemen pertama dari list l */
    address q;
    if (first(l) == NULL){
        first(l) = p;
        next(p) = first(l);
    }
    else {
        while (next(q) != first(l)) {
            q = next(q);
        }
    next(p) = first(l);
    first(l) = p;
    next(q) = p;
    }
}

void insert_last(list &l, address p) {
    address q;
    if (first(l) != NULL) {
        q = first(l);
        while (next(q) != first(l)) {
            q = next(q);
        }
    next(p) = first(l);
    next(q) = p;
    }
}

void delete_first(list &l, address p) {
    address q;
    if (next(first(l)) != first(l)) {
        q = first(l);
        while (next(q) != first(l)) {
            q = next(q);
        }
        p = first(l);
        first(l) = next(p);
        next(q) = first(l);
        next(p) = NULL;
//        delete p;
    }
    else {
        p = first(l);
        next(p) = NULL;
        first(l) = NULL;
//        delete p;
    }
}

void delete_last(list &l, address p) {
        address q;
        p = first(l);
        q = NULL;
        while (next(q) != first(l)) {
            q = p;
            p = next(p);
        }
        next(p) = NULL;
        next(q) = first(l);
//        delete p;
}

void membagi (list l){
    int i, jum;
    list l2;
    list l3;

    create_list(l2);
    create_list(l3);
    address p,q = NULL;
    p = first(l);
    jum = NULL;
    print_info(l);
    if (first(l) == NULL){
        print_info(l);
    }
    else {
        while (next(p) != first(l)) {
            if (info(p)% 2 != 0){
                p = next(p);
                delete_first(l,q);
                insert_last(l2,q);
            }
            else{
                p = next(p);
                delete_first(l,q);
                insert_first(l3,q);
            }
        }
        if (info(p)% 2 != 0){
            delete_first(l,p);
            insert_last(l2,p);
        }
        else {
            delete_first(l,p);
            insert_last(l3,p);
        }
    }
    print_info(l2);
    print_info(l3);
}

