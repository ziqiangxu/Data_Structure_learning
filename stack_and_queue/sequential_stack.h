/*----------------------------------------------------------------------------
 * 名称：顺序栈
 * 介绍：用数组实现的栈，数据的逻辑顺序与物理顺序一致
 *---------------------------------------------------------------------------*/
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
class SeqStack{
public:
    SeqStack(int size = 50);    //建立一个空栈
    ~ SeqStack(){
        cout<<"执行析构函数"<<endl;
        delete[] elements;
    }    //析构函数，删除数组
    bool IsFull() const{return (top == maxSize-1) ? true : false;}    //栈满判断
    bool IsEmpty() const{return (top == -1) ? true : false;}    //栈空判断
    void Push(const T& x);    //将x压人栈顶；如果栈满，则溢出处理
    bool Pop(T& x);    //退栈；如果空栈，则返回false
    int getSize() const{return top+1;}    //获取栈内元素数目
    int makeEmpty(){top = -1;}    //清空栈，但是不修改栈的最大空间
private:
    int maxSize;
    T *elements;
    int top;
    void overflowProcess();    //栈满时溢出处理，自动增加20个空间
};
template <class T>
SeqStack<T>::SeqStack(int size){
    maxSize = size;
    top = -1;
    elements = new T[maxSize];    //创建数组
    assert(elements != NULL);    //断言，当括号内的条件满足时，继续执行
}

template <class T>
void SeqStack<T>::overflowProcess(){
    maxSize = maxSize + 20;
    T *newArray = new T[maxSize];
    if(newArray == NULL) {cerr<<"扩充栈的时候分配存储出错"<<endl;exit(1);}
    for(int i = 0;i <= top;i++) newArray[i]=elements[i];
    delete []elements;
    elements=newArray;
}

template <class T>
void SeqStack<T>::Push(const T& x){
    if(IsFull()) overflowProcess();
    elements[top+1] = x;
    top++;
}

template <class T>
bool SeqStack<T>::Pop(T &x){
    if(IsEmpty()) return false;
    else {
        x = elements[top];
        top--;
        return true;
    }
}
