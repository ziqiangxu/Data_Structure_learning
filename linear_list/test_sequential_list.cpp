#include "sequential_list.h"
#include <string>
using namespace std;
int main(){
    SeqList<string> s1;
    s1.input();
    s1.output();

    cout<<"insert"<<endl;
    string in="insert";
    s1.Insert(1,in);
    s1.output();
    cout<<"remove the first one"<<endl;
    string re;
    s1.Remove(1,re);
    s1.output();
    cout<<"change the second item to setdata"<<endl;
    string se="setdata";
    s1.setData(2,se);
    s1.output();
    cout<<"search for setdata"<<endl;
    cout<<"location is:"<<s1.Search(se)<<endl;
    return 0;
}
