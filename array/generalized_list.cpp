/*
教材中给的代码无法在我所使用的编译器中正常编译：gcc version 6.3.0 20170321 (Debian 6.3.0-11)
*/
#include <iostream>
#include <assert.h>
#include <stdlib.h>
template <class T>
struct GenListNode;

template <class T>
struct Items{    //广义表返回值的结构类定义
    int utype;    //标志域：0表示附加头结点,1表示内容为元素,2表示指向表的指针
    union{    //联合
        int ref;    //utype=0，附加头结点，存储引用计数
        T value;    //utype=1，存放元素值
        GenListNode<T> * hlink;    //utype=2，存放子表指针
    }info;
    Items() : utype(0) {info.ref = 0;}    //构造函数
    //教材上给的例子无法在Linux上通过，也有可能是我所使用的编译器不支持
    //Items() : utype(0), info.ref(0) {}
    Items(Items<T>& RL){    //复制构造函数
        utype = RL.utype;
        info = RL.info;
    }
};

template <class T>
struct GenListNode{    //广义表结点类定义
public:
    GenListNode() : utype(0), tlink(NULL) {info.ref = 0;}    //构造函数
    //教材上给的例子无法在Linux上通过，也有可能是我所使用的编译器不支持
    //Items() : utype(0), tlink(NULL), info.ref(0){}
    GenListNode(GenListNode<T>& RL){    //复制构造函数
        utype = RL.utype;
        tlink = RL.tlink;
        info = RL.info;
    }
private:
    int utype;
    GenListNode<T> *tlink;
    union{
        int ref;
        T value;
        GenListNode<T> *hlink;
    }info;
};

template <class T>
class GenList{
    GenList();
    ~GenList();
    bool Head(Items& x);    //返回表头元素
};

int main(){
    GenListNode<int> n1;
    return 0;
}
