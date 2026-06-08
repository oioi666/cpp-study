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
    if(!L.elem) exit(OVERFLOW);//不是特别必要，申请失败不会返回空指针，而是直接返回异常
    L.length=0;
    return OK;
}

Status Inputlist(Sqlist &L,int x){
    if(x<0||x>MAXSIZE)
        return ERROR;
    L.length=x;
    for(int i=0;i<x;i++)
        cin>>L.elem[i];
    return OK;
}
//按下标查找值
Status GetElem(Sqlist L,int i,int &e){
    if(i>L.length||i<=0)
        return ERROR;
    e=L.elem[i-1];
    return OK;
}
//按值查找下标
int LocateElem(Sqlist L,int e){
    for(int i=0;i<L.length;i++){
        if(e==L.elem[i])
            return i+1;
    }
    return 0;
}

Status ListTraverse(Sqlist L){
    for(int i=0;i<L.length;i++)
        cout<<L.elem[i]<<" ";
    return OK;
}
//删除函数
Status ListInsert(Sqlist &L,int i,int e){
    if(i<1||i>L.length) return ERROR;
    if(L.length>=MAXSIZE) return ERROR;
    for(int j=L.length;j>=i-1;j--){
        L.elem[j]=L.elem[j-1];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}

int main(){
    Sqlist list;
    InitList(list);
    int n;  cin>>n;
    if(!Inputlist(list,n)){
        cout<<"数据长度输入不合法";
        return 0;
    }
    int I,E=0,e;//I为要查询的数在线性表的位置，E为查询到的数
    /*cin>>I;
    if(!GetElem(list,I,E))
        cout<<"查询失败"<<endl;//按下标查找值
    else
        cout<<E;
    */
    cin>>I>>e;
    /*
    if(!LocateElem(list,e)){
        cout<<"没有查询到";
        return 0;
    }
    else
        cout<<LocateElem(list,e)<<endl;//按值查找下标
    */
    ListInsert(list,I,e);
    ListTraverse(list);
}
