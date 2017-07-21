/*----------------------------------------------------------------------------
 * 1.为数组中每一个元素添加一个链接指针，就形成了静态链表结构。这样允许我们不改变各元素的物理位置，只
 * 要重新链接就可以改变这些数据的逻辑顺序。
 * 2.静态链表的每个结点都由两个数据组成：data域存储数据，link域存储链接指针。所有的结点形成一个结点
 * 数组，也可以带有附加头结点。
 *---------------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

const int maxSize=100;
template <class T>
struct SLinkNode{
    T data;    //Node data
    int link;    //Node link indicator
};
template <class T>
class StaticList{
    SLinkNode<T> elem[maxSize];    //Creat the array
    int avil;    //Head address of the avilable space
public:
    void InitList();    //Init the List
    int Length();    //Caculate the length of the List
    int Search(T x);    //Search where is the Node whose value equal to x
    int Locate(int i);    //Find the ith node and return it's index
    bool Append(T x);    //Append x to the List
    bool Insert(int i,T x);    //Insert a new node behind the ith node
    bool Remove(int i);    //Remove the ith node in the List
    bool IsEmpty();    //Test the List whether empty or not
    void display();    //Display all the data on the screen
};
template <class T>
void StaticList<T>::InitList(){    //将链表空间初始化
    elem[0].link=-1;    //初始化第一个数组元素的link
    avil=1;    //当前可分配空间从1开始
    for(int i=1;i<maxSize-1;i++)
        elem[i].link=i+1;    //构成空闲链表
    elem[maxSize].link=-1;    //初始化最后一个数组元素的link,链表收尾
}
template <class T>
int StaticList<T>::Length(){    //计算链表的长度
    int p=elem[0].link;
    int i=0;
    while(p!=-1){    //当结点的地址指向-1时表示链表末尾
        p=elem[p].link;
        i++;    //用i数据结构（用面向对象方法与C++语言描述计数
    }
    return i;
}
template <class T>
int StaticList<T>::Search(T x){    //搜索x,返回地址
    int p=elem[0].link;    //从第一个结点开始,逐个比较
    while(p!=-1){
        if(elem[p].data==x)break;
        else p=elem[p].link;
    }
    return p;
}
template <class T>
int StaticList<T>::Locate(int i){    //找到第i个值并返回它的地址
    if(i<0||i>maxSize-1) return -1;    //参数不合理
    if(i==0) return 0;    //附加头结点作为第零个节点
    int p=elem[0].link;
    /*for(int j=1;j<i;j++)
        p=elem[p].link;*/
    int j=1;    //p的初始值指向第一个结点
    while(p!=-1 && j<i){
        p=elem[p].link;
        j++;
    }
    return p;
}数据结构（用面向对象方法与C++语言描述
template <class T>
bool StaticList<T>::Append(T x){    //在链表尾部追加新结点
    if(avil==-1) return false;    //如果可用空间的首地址为-1表示数组空间已经用完
    elem[avil].data=x;    //把x数据写入可用空间的最前面
    int q=avil;    //把avil值暂存于q中,这是新增数据的地址
    avil=elem[avil].link;    //可用空间减一,修改可用空间的首地址
    //如果avil值更新之后变成了-1,则说明结点数组的所有空间分配完毕
    elem[q].link=-1;    //新数据将作为链表末尾,将其link值改为-1作为标记
    int p=0;    //找到原来链表的尾巴,并将其link(值为-1)修改为新增的结点地址q
    while(elem[p].link!=-1)
        p=elem[p].link;
    elem[p].link=q;
    return true;
}
template<class T>
bool StaticList<T>::Insert(int i,T x){    //在第i个结点后面增加结点x
    int p=Locate(i);    //使用先前定义的定位函数,返回第i结点的地址
    if(p==-1) return false;    //-1表示定位失败,i值不合理
    if(avil==-1) return false;    //数组空间用完
    elem[avil].data=x;
    int q=avil;    //保存新增结点的地址
    avil=elem[avil].link;    //更新可用空间的首地址
    elem[q].link=elem[p].link;    //使新增结点的link指向原来第i+1个结点
    elem[p].link=q;   //使第i结点的link指向新增结点
    return true;
}
template<class T>
bool StaticList<T>::Remove(int i){    //删除第i个结点并回收其空间
    int p=Locate(i-1);    //找到第i-1个结点
    if(p==-1) return false;    //i值不合理
    int q=elem[p].link;    //保存删除结点的地址,即将作为可用存储的首地址
    elem[p].link=elem[q].link;    //使第i-1个结点的link指向第i+1个结点,删除操作完毕
    elem[q].link=avil;    //使删除结点的link指向之前的可用存储首地址
    avil=q;    //回收空间
    return true;
}
template<class T>
bool StaticList<T>::IsEmpty(){    //判断链表是否为空
    if(elem[0].link=-1) return true;
    else return false;
}
template<class T>
void StaticList<T>::display(){    //输出结点数据，仅T为标准数据类型的时候直接可用。其他类型可用运算符重载使用
    int p=elem[0].link;
    while(p!=-1){
        cout<<elem[p].data<<endl;
        p=elem[p].link;
    }
}

int main(){
    StaticList<string> list2;    //存储字符串
    list2.InitList();
    list2.Append("append1");
    list2.Append("append2");
    list2.Insert(1,"insert behind 1");
    list2.display();
    list2.Remove(3);
    cout<<"删除第3个结点"<<endl;
    list2.display();
    cout<<"链表长度:"<<list2.Length()<<endl;
    cout<<"搜索append2:"<<list2.Search("append2")<<endl;
    cout<<"搜索append1:"<<list2.Search("append1")<<endl;
    cout<<"第2个结点数据的地址"<<list2.Locate(2)<<endl;

    StaticList<int> list1;    //存储整数
    list1.InitList();    //初始化
    list1.Append(1);
    list1.Append(2);
    list1.Insert(11,3);
    list1.display();
    cout<<sizeof(list1)<<endl;
    cout<<list1.IsEmpty()<<endl;
    return 0;
}
