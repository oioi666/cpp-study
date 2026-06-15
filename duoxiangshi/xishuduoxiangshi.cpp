#include<iostream>
using namespace std;

typedef struct SqList{
    float a;
    int b;
    struct SqList *next;
}LNode,*LinkList;

void InitSqList(LinkList &L){
    L=new LNode;
    L->next=NULL;
}

void CreateSqList(LinkList &L,int m){
    LNode *p;
    p=L;
    for(int i=0;i<m;i++){
        LNode *q;
        q=new LNode;
        cin>>q->a>>q->b;
        q->next=p->next;
        p->next=q;
        p=p->next;
    }
}

void AddSqList(LinkList &l1,LinkList &l2){

}

void TraverseSqList(LinkList L){
    LNode *p;
    p=L->next;
    while(p){
        cout<<p->a<<" "<<p->b<<endl;
        p=p->next;
    }
}

int main(){
    LinkList L1,L2;
    InitSqList(L1);
    //InitSqList(L2);
    int n1,n2;
    cin>>n1;//>>n2;
    CreateSqList(L1,n1);
    //CreateSqList(L2,n2);
    TraverseSqList(L1);
}