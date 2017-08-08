#include "sequential_stack.h"
int main(){
    SeqStack<int> stack1(3);
    int x = 1;
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    stack1.Push(x);
    x = 100;
    stack1.Push(x);
    int pop;
    stack1.Pop(pop);
    cout<<pop<<endl<<stack1.getSize()<<endl;
    //字符栈
    SeqStack<char> stack2(3);
    char ch1='c';
    stack2.Push(ch1);
    stack2.Push(ch1);
    stack2.Push(ch1);
    stack2.Push(ch1);
    ch1='t';
    stack2.Push(ch1);
    char ch2;
    stack2.Pop(ch2);
    cout<<ch2<<endl<<stack2.getSize()<<endl;
    return 0;
}
