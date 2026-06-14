#include<iostream>
#define OK 1
using namespace std;

typedef int Status;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//初始化
Status InitList(LinkList &L){
    L=new LNode;
    L->next=NULL;
    return OK;
}
//创建
void CreateList(LinkList &L,int m){
    LNode *p=new LNode;
    p=L;
    int j=0;
    while(j<=m-1){
       LNode *q=new LNode;
        cin>>q->data;
        q->next=p->next;
        p->next=q;
        p=p->next;
        ++j;
    }
}
//遍历
void TraverseList(LinkList L){
    LNode *p;
    p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    LinkList l;
    InitList(l);
    int n;
    cin>>n;
    CreateList(l,n);
    TraverseList(l);
}


