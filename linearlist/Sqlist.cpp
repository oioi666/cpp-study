#include<iostream>
#include<cstdlib>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int Status;//表示函数返回的不是普通的整数，而是是否成功的状态
typedef struct {
    int *elem;
    int length;
}Sqlist;

Status InitList(Sqlist &L){
    L.elem=new int[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    return OK;
}

Status Inputlist(Sqlist &L,int x){
    if(x<0||x>MAXSIZE)
        exit(OVERFLOW);
    L.length=x;
    for(int i=0;i<x;i++)
        cin>>L.elem[i];
    return OK;
}

Status GetElem(Sqlist L,int i,int &e){
    if(i>L.length||i<=0)
        return ERROR;
    e=L.elem[i-1];
    return OK;
}

int main(){
    Sqlist list;
    InitList(list);//初始化
    int n;  cin>>n;
    Inputlist(list,n);
    
    int I,E=0;//I为要查询的数在线性表的位置，E为查询到的数
    cin>>I;
    if(!GetElem(list,I,E))
        cout<<"查询失败"<<endl;
    else
        cout<<E;
}
