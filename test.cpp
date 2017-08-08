/*----------------------------------------------------------------------------
这个文件只是我用来测试一些语法的，因为经常会忘记一些语法
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

    //NULL值检测
    if(NULL==0){
    cerr<<"错误测试"<<endl;
    exit(1);//此处执行后后面的代码一律不执行
    }

    //数组元素地址测试
    int i[2];
    i[0]=1;i[1]=2;i[2]=3;
    int(*p)=i;
    int* p2=&i[2];
    cout<<p<<endl;
    cout<<p2<<endl;

    return 0;
}
