#include<iostream>
#include<cstdlib>
#define ERROR 0
#define OK 1
#define MAXSIZA 100

using namespace std;

typedef int Status;

typedef struct{
    int *elem;
    int length;
}Sqlist;

Status InitList(Sqlist &L){
    L.elem=new int[MAXSIZA];
    L.length=0;
    return OK;
}

Status InputList(Sqlist &L,int m){
    if(m<0||m>MAXSIZA) return ERROR;
    for(int i=0;i<m;i++)
        cin>>L.elem[i];
    L.length=m;
    return OK;
}

Status LocateElem(Sqlist L,int e){
    for(int i=0;i<L.length;i++)
        if(L.elem[i]==e)  return 1;
    return 0;
}

Status InserList(Sqlist &L,int i,int e){
    if(i<1||i>L.length) return ERROR;
    if(L.length>=MAXSIZA) return ERROR;
    for(int j=L.length-1;j>=i-1;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}
Status Mergelist(Sqlist &L,Sqlist &K){
    for(int i=0;i<K.length;i++){
        if(!LocateElem(L,K.elem[i]))
            InserList(L,L.length,K.elem[i]);
    }
    return OK;
}

Status ListTraverse(Sqlist L){
    for(int i=0;i<L.length;i++)
        cout<<L.elem[i]<<" ";
    return OK;
}

int main(){
    Sqlist A,B;
    int a,b;
    InitList(A);
    InitList(B);
    cin>>a;
    InputList(A,a);
    cin>>b;
    InputList(B,b);
    Mergelist(A,B);
    ListTraverse(A);

}