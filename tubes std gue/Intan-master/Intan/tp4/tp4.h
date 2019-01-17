#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

#include <cstddef>

#define first(A) A.first
#define next(A) A->next
#define info(A) A->info

#define NIL NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
};

struct list{
    address first;
};

address alokasi(infotype data);
/*  IS. terdefinisi suatu data yang akan dialokasikan di dalam memori,
    FS. mengahsilkan pointer p yang mengaju ke data baru, teralokasi kedalam memori */

void dealokasi(list l, address &p);
/* IS. terdefinisi suatu data yang telah dialokaikan didalam memori,
   FS. menunjuk suatu data dengan pointer p, dan menghapusnya, terdealokasi dari memori*/

void create_list(list &l);
/*  IS. sembarang,
    FS. terbentuk list l dengan first adalah NIL */

void print_info(list &l);
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. menampilkan isi keseluruhan dari list l */

void insert_first(list &l,address p);
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. data ditambahakan menjadi elemen pertama dari list l */

void membagi (list l);

void insert_last(list &l,address p);
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. data ditambahakan menjadi elemen terakhir dari list l*/

void delete_first(list &l, address p);
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. elemen pertama dari list l di hapus dari list l, dealokasi data yang dihapus*/

void delete_last(list &l, address p);
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. elemen terakhir dari list l di hapus dari list l, dealokasi data yang dihapus*/

bool search_node(list l,infotype data) ;
/*  IS. l sembarang, bisa masih kosong dan bisa sudah terisi beberapa elemen,
    FS. True jika data ada didalam list l, dan False untuk sebaliknya*/

#endif // TP4_H_INCLUDED
