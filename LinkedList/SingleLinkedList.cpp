#include<iostream>
#define OK 1
using namespace std;

typedef int Status;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

Status InitList(LinkList &L){
    L=new LNode;
    L->next=NULL;
    return OK;
}
//前插法创建链表
void CreateList(LinkList &L,int n){
    for(int i=0;i<n;i++){
        LNode *p= new LNode;//如果只是定义为一个指针，则表示他可以指向此类结构体，但他现在没有指向任何节点
        cin>>p->data;
        p->next=L->next;
        L->next=p;
    }
}
//用尾插法创建链表
void CreateList_R(LinkList &L,int n){
    LNode *p;
    p=L;
    for(int i=0;i<n;i++){
        LNode *q=new LNode;
        cin>>q->data;
        q->next=p->next;
        p->next=q;
        p=p->next;
    }
}
//插入函数
void ListInsert(LinkList &L,int i,int e){
    LNode *s=new LNode;
    LNode *p;
    s->data=e;
    p=L;
    for(int j=0;j<i-1;j++){
        p=p->next;
    }
    s->next=p->next;
    p->next=s;
}
//删除链表的数据
void ListDelete(LinkList &L,int i){
    LNode *p;
    p=L;
    for(int j=0;j<i-1;j++){
        p=p->next;
    }
    p->next=p->next->next;

}
//输出链表里面的数据
void Traverse(LinkList L){
    LNode *p;
    p=L->next;
    while(p!=NULL){ //注意指针p的判断条件
    cout<<p->data<<" ";
    p=p->next;
    }
}

int main(){
    LinkList l;
    if(InitList(l)) cout<<"初始化正常"<<endl;
    int n,I,E;
    cin>>n;
    //CreateList(l,n);
    CreateList_R(l,n);
    /*
    cin>>I>>E;
    ListInsert(l,I,E);
    插入数据
    */
    cin>>I;
    ListDelete(l,I);
    Traverse(l);
}