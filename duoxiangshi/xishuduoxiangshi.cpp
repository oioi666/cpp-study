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

void TraverseSqList(LinkList L){
    LNode *p;
    p=L->next;
    cout<<"所得结果的指数和系数分别是"<<endl;
    while(p){
        cout<<p->a<<" "<<p->b<<endl;
        p=p->next;
    }
}

void AddSqList(LinkList &l1,LinkList &l2){
    LNode *p,*q,*l;
    p=l1->next;
    q=l2->next;
    InitSqList(l);
    while(p&&q){
        LNode *r=new LNode;
        LNode *I;
        I=l;
        if(p->a==q->a){
            if(p->b+q->b==0){
                p=p->next;
                q=q->next;
            }
            else{
                r->a=p->a;
                r->b=p->b+q->b;
                r->next=I->next;
                I->next=r;
                I=I->next;
                p=p->next;
                q=q->next;
            }
        }
        else{
            if(p->a<q->a){
                r->a=p->a;
                r->b=p->b;
                r->next=I->next;
                I->next=r;
                I=I->next;
                p=p->next;
            }
            else{
                r->a=q->a;
                r->b=q->b;
                r->next=I->next;
                I->next=r;
                I=I->next;
                q=q->next;
            }
        }
    }
    if(p){
        LNode *i;
        i=l;
        while(i->next)
            i=i->next;
        i->next=p;
    }
    if(q){
        LNode *i;
        i=l;
        while(i->next)
            i=i->next;
        i->next=q;
    }
    TraverseSqList(l);
}


int main(){
    LinkList L1,L2;
    InitSqList(L1);
    InitSqList(L2);
    int n1,n2;
    cin>>n1>>n2;
    cout<<"第一个多项式的指数和系数"<<endl;
    CreateSqList(L1,n1);
    cout<<"第二个多项式的指数和系数"<<endl;
    CreateSqList(L2,n2);
    AddSqList(L1,L2);
}