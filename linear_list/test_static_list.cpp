/*----------------------------------------------------------------------------
 * 1.为数组中每一个元素添加一个链接指针，就形成了静态链表结构。这样允许我们不改变各元素的物理位置，只
 * 要重新链接就可以改变这些数据的逻辑顺序。
 * 2.静态链表的每个结点都由两个数据组成：data域存储数据，link域存储链接指针。所有的结点形成一个结点
 * 数组，也可以带有附加头结点。
 *---------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "static_list.h"
using namespace std;

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
