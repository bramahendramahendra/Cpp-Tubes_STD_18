#include <iostream>
#include "doublelist.h"

using namespace std;

void create_list(List &L){
    first(L) = Nil;
    last(L) = Nil;
}

address alokasi(infotype data){
    address p = new elmlist;
    info(p) = data;
    next(p) = Nil;
    prev(p) = Nil;

    return p;
}

void dealokasi(address &p){
    delete p;
    p = NULL;
}

void insertFirst(List &L, address p){
    if(first(L) == Nil){
        first(L) = p;
        last(L) = p;
    }else {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }

}

void insertLast(List &L, address p){
    if(first(L) == Nil){
        insertFirst(L,p);
    }else{
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

void deleteFirst(List &L, address &p){

    p = first(L);
    if(first(L) != Nil){
        if(next(first(L)) == Nil){
            first(L) = Nil;
            last(L) = Nil;

        }else {
            first(L) = next(p);
            next(p) = Nil;
            prev(first(L)) = Nil;
        }
    }else {
        first(L) = Nil;
        last(L) = Nil;
    }
}

void deleteLast(List &L, address &p){
    if(first(L) != Nil){
        if(first(L) == last(L)){
            deleteFirst(L,p);
        }else {
            p = last(L);
            last(L) = prev(p);
            next(last(L)) = Nil;
            prev(p) = Nil;
        }
    }else {
        deleteFirst(L,p);
    }

}

void printInfo(List L){
    if(first(L) == Nil){
        cout << "List Kosong";
    } else {
        address P = first(L);
        while(P != Nil){
            cout << info(P) << " (" << P << "), "<< endl;
            P = next(P);
        }
    }
    cout << endl;
}

void angkaTerbesar(List L, List L2){
    address p = first(L);
    address q = first(L2);
    infotype s=0;

    while(p != last(L)){
        while(q != last(L2)){
            if(info(p) == info(q)){
                    if(info(q)>s){
                        s = info(q);
                    }
            }

            q = next(q);
        }

            q = first(L2);
            p = next(p);
    }
        if(s==0){
            cout<<"Kosong";
        }else{
            cout << s<<endl;
        }
}

void sorting(List L){
    List L2;
    create_list(L2);
    address p,q = NULL;
    printInfo(L);
    while(first(L) != NULL){
            deleteFirst(L,p);
            if (first(L2) == NULL){
                first(L2) = p;
                last(L2) = p;
            }else if (info(p)<= info(first(L2))){
                insertFirst(L2,p);
                p = NULL;
            }else if (info(p)>= info(last(L2))){
                insertLast(L2,p);
                p = NULL;
            }else{
                q = first(L2);
                while (info(p) > info(next(q))){
                    q = next(q);
                }
                next(p) = next(q);
                prev(p) = q;
                prev(next(q)) = p;
                next(q) = p;
                p = NULL;
            }

    }
    first(L) = first(L2);
    last(L) = first(L2);
    printInfo(L);

}

void membagi(List L){
    int i,j;
    address p,q = NULL;

    i = 0;
    p = first(L);
    while (p != NULL){
        i = i + 1;
        p = next(p);
    }
    q = first(L);
    for (j = 1 ; j<= i/2;j++){
       deleteFirst(L,q);
       insertLast(L,q);
        //printInfo(L);
    }


    printInfo(L);


}
