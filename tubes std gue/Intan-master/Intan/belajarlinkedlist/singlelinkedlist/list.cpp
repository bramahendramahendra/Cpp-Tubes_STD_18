#include <iostream>
#include "list1.h"

using namespace std;

address alokasi(infotype data){
/*  IS. terdefinisi suatu data yang akan dialokasikan di dalam memori,
    FS. mengahsilkan pointer p yang mengaju ke data baru, teralokasi kedalam memori */
    address p = new node;
    info(p) = data;
    next(p) = NIL;
    return p;
}

void create_list(list &l){
/*  IS. sembarang,
    FS. terbentuk list l dengan first adalah NIL */
    first(l) = NIL;
}

void insert_first(list &l,infotype data){
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. data ditambahakan menjadi elemen pertama dari list l */
    address p = alokasi(data);
    next(p) = first(l);
    first(l) = p;
}

void insert_last(list &l,infotype data){
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. data ditambahakan menjadi elemen terakhir dari list l*/
    if (first(l) != NIL)
        {
        address p = alokasi(data);
        address q = first(l);
        while (next(q) != NIL)
            {
            q = next(q);
        }
        next(q) = p;
    }
}

void view_list(list l){
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. menampilkan isi keseluruhan dari list l */
    address p = first(l);
    while (p != NIL)
        {
        cout<<info(p)<<endl;
        p = next(p);
    }
}

void delete_first(list &l){
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. elemen pertama dari list l di hapus dari list l, dealokasi data yang dihapus*/
    if (first(l) != NIL)
        {
        address p = first(l);
        first(l) = next(p);
        next(p) = NIL;
        delete(p);
    }
}

void delete_last(list &l){
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. elemen terakhir dari list l di hapus dari list l, dealokasi data yang dihapus*/
    if (first(l) != NIL)
        {
        address q = first(l);
        address p = next(q);
        while (next(p) != NIL)
            {
            p = next(p);
            q = next(q);
        }
        next(q) = NIL;
        delete(p);
    }
    else
        {
        delete_first(l);
    }
}
bool search_node(list l,infotype data) {
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. True jika data ada didalam list l, dan False untuk sebaliknya*/
    address p = first(l);
    while (next(p) != NIL && info(p) != data)
        {
        p = next(p);
    }
    return info(p) == data;
}
