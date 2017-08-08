#include "single_linked_list.h"
#include <string>
int main(){
    List<string> l;
    string in="one",in2="two";
    l.Insert(0,in);l.Insert(1,in);l.Insert(1,in);l.Insert(1,in);
    l.Insert(0,in);l.Insert(1,in);l.Insert(5,in2);l.Insert(7,in2);
    cout<<"写入8个值"<<endl;
    l.output();
    string del;
    l.Delete(7,del);    //删除
    l.output();
    cout<<"change the 1st one to two"<<endl;
    l.setData(1,in2);
    l.output();
    cout<<"search for one"<<endl;
    int loc=l.Search(in);
    cout<<loc<<endl;
    cout<<"address of the 3rd one is:";
    LinkNode<string> *ptr=l.Locate(1);
    cout<<ptr<<endl;
    //cout<<ptr->data<<endl;
    //LinkNode的成员默认私有,修改成public则可以运行上一行代码，但是不安全
    return 0;
}
