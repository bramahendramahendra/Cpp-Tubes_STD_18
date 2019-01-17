#include "tp6_queue.h"

void createQueue(arr_queue *q){
    q->head = -1;
    q->tail = -1;
}
bool isEmpty(arr_queue q){
    if (q.head==-1)
        return true;
    else
        return false;
}
bool isFull(arr_queue q){
    if (q.tail==3)//fatal
        return true;
    else
        return false;
}
void enqueue(int elm, arr_queue *q){
    if (isFull(*q)){
        cout<<"FULL"<<endl;}
    else{
            if (isEmpty(*q)){
                    q->head=0;
                    q->tail++;
                    q->info_q[q->tail] = elm;
            }
            else{
                    q->tail = q->tail+1;
                    q->info_q[q->tail] = elm;
            }
    }
}
int dequeue(arr_queue *q){
    if (isEmpty(*q)){
        cout<<"EMPTY"<<endl;}
    else{
        if (q->head!=q->tail){
                int p = q->info_q[q->head];
                int i = q->head+1;
                while(i<=q->tail){
                    q->info_q[i-1] = q->info_q[i];
                    i++;}
                q->tail--;
                return p;}
        else{
                int p = q->info_q[q->head];
                q->head--;
                q->tail--;
                return p;}
    }
}
void viewQueue(arr_queue *q){
    if (isEmpty(*q)){
        cout<<"EMPTY"<<endl;}
    else{
        for(int i=0; i <= q->tail; i++)
            {
                cout<<q->info_q[i]<<endl;
            }
    }
}
void splitQueue(arr_queue *q,arr_queue *r,arr_queue *s){
    int p;
    while(not isEmpty(*q)){
            p = dequeue(q);
                if (p%2 == 0)
                    {
                        enqueue(p,s);
                    }
                else
                    enqueue(p,r);}
}
