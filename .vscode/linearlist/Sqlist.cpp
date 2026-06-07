#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROE 0
#define OVERFLOW -2

using namespace std;

typedef struct {
    int *elem;
    int length;
} Sqlist;

int InitList(Sqlist &L){
    L.elem=(int*)malloc(MAXSIZE*4);
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    return OK;
}

int GetElem(Sqlist L,int i,int &e){
    if(i>=L.length||i<0)
        exit(OVERFLOW);
    else
        e=L.elem[i];
}

int main(){
    Sqlist list;
    int n;
    for(int i=0;i<n;i++)
        cin>>list.elem[i];
    int I,E=0;//I为要查询的数在线性表的位置，E为查询到的数
    cin>>I;
    if(GetElem(list,I,E)==2)
        cout<<"查询失败";
    else
        cout<<E;
}
