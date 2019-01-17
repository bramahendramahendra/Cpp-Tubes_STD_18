#include "coba.h"


address alokasi(infotype data)
    {
        address p = new node;
        info(p) = data;
        next(p) = null;
        return p;
    }
address get_last(list l)
    {
        address p = first(l);
            do
                {
                    p = next(p);
                }
            while(next(p)!=first(l));
            return p;
    }

void dealokasi(address &p)
    {
        delete p;
        p = null;
    }

void create_list(list &l)
    {
        first(l) = null;
    }
void show_list(list l)
    {
       if (first(l)!=null)
       {
        address p = first(l);
            do
                {
                    cout<<"ID    = "<<info(p).id<<endl;
                    cout<<"Name  = "<<info(p).name<<endl;
                    cout<<"Group = "<<info(p).group<<endl;
                    cout<<"Age   = "<<info(p).age<<endl;
                    cout<<"Score = "<<info(p).score<<endl;
                    cout<<endl;
                    p = next(p);
                }
            while(p!=first(l));
       }
       else
            cout<<"[ kosong ]"<<endl;
    }
address search_node(list l,int x)
        {
            if (first(l)!=null)
                {
                    address p = first(l);

                        do
                            {
                            if (info(p).score==x)
                                return p;
                            else
                                p = next(p);
                            }
                        while (p!=first(l));
                    return null;
                }
        }

void insert_first(list &l, address p)
    {
        if (first(l)!=null)
            {
                address q = first(l);
                while (next(q)!=first(l))
                    {
                        q = next(q);
                    }
                next(p) = first(l);
                next(q) = p;
                first(l) = p;
            }
        else
            {
                first(l) = p;
                next(p) = first(l);
            }
    }
void insert_last(list &l, address p)
    {
        if (first(l)!=null)
            {
                address q = first(l);
                while (next(q)!=first(l))
                    {
                        q = next(q);
                    }
                next(p) = first(l);
                next(q) = p;
            }
        else
            insert_first(l,p);
    }

void insert_after(list &l, address prec, address p)
    {
        if (prec!=null)
            {
                if (first(l)!=null)
                    {
                        if(prec==get_last(l))
                            insert_last(l,p);
                        else
                            {
                                next(p)=next(prec);
                                next(prec)=p;
                            }
                    }
            }

    }

void insert_sort(list &l)
    {
    mhs x;
    cout<<"ID    = ";cin>>x.id;
    if(first(l)!=null)
       {

            bool chk = false;
                address fnd = first(l);
                do
                    {
                        if(info(fnd).id==x.id)
                            chk = true;
                        else
                        fnd = next(fnd);
                    }
                while(fnd!=first(l)&& chk==false);
                if (chk==false)
                    {
                        cout<<"Name  = "; cin.ignore(); getline(cin,x.name);
                        cout<<"Group = "; cin>>x.group;
                        cout<<"Age   = "; cin>>x.age;
                        cout<<"Score = "; cin>>x.score;
                        if(x.score<=info(first(l)).score)
                            insert_first(l,alokasi(x));
                        else if (x.score>=info(get_last(l)).score)
                            insert_last(l,alokasi(x));
                        else
                            {
                                address q = first(l);
                                while(info(next(q)).score<=x.score)
                                    {
                                        q = next(q);
                                    }
                                insert_after(l,q,alokasi(x));


                            }

                    }
                else
                    cout<<"There is a similiar ID !"<<endl;
                    cout<<endl;
       }
    else
        {
            cout<<"Name  = "; cin.ignore(); getline(cin,x.name);
            cout<<"Group = "; cin>>x.group;
            cout<<"Age   = "; cin>>x.age;
            cout<<"Score = "; cin>>x.score;
            cout<<endl;
            insert_first(l,alokasi(x));
        }

    }

address find_old(list l)
    {
        int old = 0;
        address q;
        address p = first(l);
        do
            {
                if(info(p).age>old)
                    {
                        old = info(p).age;
                        q = p;
                    }
                p = next(p);
            }
        while(p!= first(l));
        if (q!=null)
            return q;
        else
            return null;
    }

void group_average(list l)
    {
        float a=0,a1=0,b=0,b1=0,c=0,c1=0;
        address p = first(l);
        do
            {
                if (info(p).group=='A')
                    {
                        a = a + info(p).score;
                        a1= a1+1;
                    }
                else if (info(p).group=='B')
                    {
                        b = b + info(p).score;
                        b1= b1+1;
                    }
                else if (info(p).group=='C')
                    {
                        c = c + info(p).score;
                        c1= c1+1;
                    }
                p = next(p);
            }
        while(p!=first(l));
        cout<<"Average A = "<<a/a1<<endl;
        cout<<"Average B = "<<b/b1<<endl;
        cout<<"Average C = "<<c/c1<<endl;

    }

void delete_first(list &l,address &p)
    {
        if (first(l)!=null)
            {


                if (next(first(l))!=null)
                    {
                        p = first(l);
                        first(l) = next(p);
                        next(p) = null;
                    }
                else
                    {
                        p = first(l);
                        first(l) = null;
                    }
            }
    }
