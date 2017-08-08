/*----------------------------------------------------------------------------
 * 名称：顺序表
 * 介绍：用数组实现的线性表，数据的逻辑顺序与物理顺序一致
 *---------------------------------------------------------------------------*/
//#ifndef SEQUENTIALLIST_H//QT自动添加的代码
//#define SEQUENTIALLIST_H//QT自动添加的代码
#include <iostream>
#include <string>
using namespace std;
const int defaultSize=100;
template <class T>
class SeqList
{
protected:
    T * data;
    int maxSize;
    int last;
public:
    SeqList(int sz=defaultSize);    //构造函数
    SeqList(SeqList<T> &L);    //复制构造函数
    ~SeqList(){delete[] data;}    //析构函数
    int Size() const{return maxSize;}    //返回表最大长度
    int Length() const{return last+1;}    //返回表长度
    bool Insert(int i,T& x);    //在第i项后面插入x的值_增
    bool Remove(int i,T& x);    //删除第i项,并把值给x_删
    bool setData(int i,T& x);    //把x的值传给第i项_改
    int Search(T& x);    //搜索值为x的表项，并返回表项序号，返回0表示没有此项_查
    bool getData(int i,T& x);    //获取第i项的值,并传给x_查
    bool IsEmpty(){return (last==-1)?true:false;}
    bool IsFull(){return (last==maxSize-1)?true:false;}
    void input();
    void output();
};
template <class T>
SeqList<T>::SeqList(int sz){
    maxSize=sz;
    data=new T[maxSize];
    last=-1;    //此时表示表空
    if(data==NULL){
        cerr<<"初始化时存储分配错误"<<endl;
        exit(1);
    }
}

template <class T>
SeqList<T>::SeqList(SeqList<T> &L){
    maxSize=L.Size();    //需要通过Size函数获得L对象的maxSize(受保护的数据成员)
    last=L.Length();
    data=new T[maxSize];    //创建数组
    if(data==NULL){
        cerr<<"复制时存储分配错误"<<endl;
        exit(-1);
    }
    T value;
    for(int i=1;i<=last;i++){
        L.getData(i,value);
        data[i-1]=value;
    }
}

template <class T>
bool SeqList<T>::Insert(int i,T &x){    //先判断是否表满,后移i+1之后的所有项
    if(last==maxSize-1) return false;    //表满
    if(i<0||i>last+1) return false;    //插入位置不合理
    for(int j=last;j>=i;j--){
        data[j+1]=data[j];    //依次后移,空出第i项后面的空间.最后移动的是角标为i的那一项
    }
    data[i]=x;
    last++;    //last加1
    return true;
}

template <class T>
bool SeqList<T>::Remove(int i, T &x){    //从第i+1项开始逐个往前移动
    if(last==-1) return false;    //空表
    if(i<1||i>last+1) return false;    //参数不合理
    x=data[i-1];    //保存被删项
    for(i;i<=last;i++){
        data[i-1]=data[i];    //依次前移
    }
    last--;
    return true;
}

template <class T>
bool SeqList<T>::setData(int i, T &x){    //将第i项的数据设置为x
    if(last==-1) return false;    //空表
    if(i<1||i>last+1) return false;    //参数不合理
    data[i-1]=x;
    return true;
}

template <class T>
int SeqList<T>::Search(T &x){    //搜索值为x的项,并返回其序号
    for(int i=1;i<=last+1;i++){
        if(data[i-1]==x) return i;
    }
    return 0;    //表项序号大于等于1,返回零表示搜索失败
}
template <class T>
bool SeqList<T>::getData(int i, T &x){    //获取第i项的数据,传给x
    if(last==-1) return false;    //空表
    if(i<1||i>last+1) return false;    //参数不合理
    x=data[i-1];
    return true;
}

template <class T>
void SeqList<T>::input(){    //从键盘读取数据
    cout<<"请输入要输入数据的数目:"<<endl;
    while(1){
        cin>>last;
        last--;
        if(last>maxSize-1||last<0) {
            cout<<"请重新输入一个合理的数目"<<endl;
            continue;
        }
        else break;
    }
    int i=0;
    while (i<=last) {
        cin>>data[i];
        i++;
    }
}

template <class T>
void SeqList<T>::output(){
    cout<<"[";
    for(int i=0;i<last;i++){
        cout<<data[i]<<",";
    }
    cout<<data[last]<<"]"<<endl;
}

//#endif SEQUENTIALLIST_H
//QT自动添加的代码
