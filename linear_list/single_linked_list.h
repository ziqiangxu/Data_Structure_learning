/*----------------------------------------------------------------------------
 * 名称：单链表
 * 介绍：
 * 单链表的类定义文件：通常单链表需要结点类(linknode)和链表类(list)两个类协同表示
 * 可使用符复合类、嵌套类、继承派生类或用struct定义结点类四种方法实现。本示例使用复合类
*---------------------------------------------------------------------------*/
#include <iostream>
using namespace std;
template <class T>
class List;
template <class T>
class LinkNode{    //定义结点类
     friend class List<T>;
     T data;    //结点数据域
     LinkNode<T> *link;    //结点指针域
     LinkNode<T>(LinkNode<T> *ptr=NULL){    //仅仅初始link的构造函数
         link=ptr;
     }
     LinkNode<T>(const T &item,LinkNode<T> *ptr=NULL){   //初始化data和link的构造函数
         data=item;
         link=ptr;
     }
 };

template <class T>
class List{    //定义链表类
 private:    //链表头指针
     LinkNode<T> *first;
     int length;
 public:    //链表操作
     List();    //构造函数
     List(List &L);    //复制函数
     LinkNode<T> *Locate(int i);    //返回第i个结点的地址
     bool Insert(int i,T &x);    //在第i个结点后插入
     bool Delete(int i,T &x);    //删除第i个结点
     bool setData(int i,T &x);    //修改第i个结点的值
     int Search(T &x);    //搜索,并返回位置
     T getData(int i);    //获取第i个结点的值
     void output();   //打印所有的数据
 };

template <class T>
List<T>::List(){    //构造函数
    first=new LinkNode<T>;    //带附加头结点的链表
    if(first==NULL){
        cerr<<"初始化链表错误";
        exit(1);
    }
    length=0;
}

template <class T>
List<T>::List(List &L){    //复制函数

}

template <class T>
LinkNode<T> *List<T>::Locate(int i){    //获取第i个结点的地址
    LinkNode<T> *current=first;    //附加头结点为起始结点
    if(i<0||i>length) return NULL;
    while(i!=0){
        current=current->link;    //后移一个结点
        i--;
    }
    return current;
}

template <class T>
bool List<T>::Insert(int i,T &x){
    if(i<0||i>length) return false;
    LinkNode<T> *current=Locate(i);
    LinkNode<T> *newNode=new LinkNode<T>(x);
    if(newNode==NULL){
        cerr<<"插入时存储分配失败";
        exit(1);
    }
    newNode->link=current->link;    //将新结点的地址域设为第i+1项的地址
    current->link=newNode;    //将第i项的地址域设为新结点的地址
    length++;    //链表长度加1
    return true;
}

template <class T>
bool List<T>::Delete(int i, T &x){
    if(i<1||i>length) return false;    //这保证i是合理的
    LinkNode<T> *current=Locate(i-1);    //获取第i-1项地址
    x=current->link->data;    //保存删除项的值
    delete current->link;    //从内存中清理
    current->link=current->link->link;    //把第i-1项的地址域设为第i+1的地址
    cout<<"删除了："<<x<<endl;
    length--;    //长度减1
    return true;
}

template <class T>
bool List<T>::setData(int i, T &x){
    LinkNode<T> *current=Locate(i);
    if(current==NULL) return false;    //定位失败则修改失败
    current->data=x;
    return true;
}

template <class T>
int List<T>::Search(T &x){
    LinkNode<T> *current=first;
    for(int i=0;i<=length;i++){
        if(current->data==x) return i;
        current=current->link;
    }
    return -1;    //搜索不到
}

template <class T>
T List<T>::getData(int i){
    return Locate(i)->data;
}

template <class T>
void List<T>::output(){
    LinkNode<T> *current=first->link;
    while(current->link!=NULL){
        cout<<current->data<<",";
        current=current->link;
    }
    cout<<current->data<<"。"<<endl;  //打印最后一个数据
}

