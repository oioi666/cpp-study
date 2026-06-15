#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
using namespace std;

typedef int Status;

typedef struct 
{   int *elem;
    int length;
}List;

Status InitList(List &L){
    L.elem=new int[MAXSIZE];
    L.length=0;
    return OK;
}

Status CreateList(List &L,int m){
    if(m<0||m>MAXSIZE) return ERROR;
    for(int i=0;i<m;i++){
        cin>>L.elem[i];
    }
    L.length=m;
    return OK;
}

Status TraverseList(List L){
    for(int i=0;i<L.length;i++){
        cout<<L.elem[i]<<" ";
    }
    return OK;
}

void CaculateList(List l1,List l2){
    for(int i=0;i<l2.length;i++){
        l1.elem[i]=l1.elem[i]+l2.elem[i];
    }
}

void AddList(List l1,List l2){
    if(l1.length>l2.length) {
        CaculateList(l1,l2);
        TraverseList(l1);
    }
    else {
        CaculateList(l2,l1);
        TraverseList(l2);
    }
    
        
}

int main(){
    List L1,L2;
    InitList(L1);
    InitList(L2);
    int n1,n2;
    cin>>n1>>n2;
    CreateList(L1,n1);
    CreateList(L2,n2);
    AddList(L1,L2);
}