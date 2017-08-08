/*----------------------------------------------------------------------------
 * 名称：线性表的抽象基类
 * 介绍：教材上的摘抄
 *---------------------------------------------------------------------------*/
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H
template <class T>
class LinearList{
public:
    LinearList();    //构造函数
    ～ LinearList();    //析构函数
    virtual int Size() const;    //返回表的最大长度
    virtual int Length() const;    //返回表长
    virtual int Search(T& x) const;    //搜索值为x的值，并返回它在表中的位置
    virtual int Locate(int i) const;    //定位第i个表项的位置
    virtual bool getData(int i,T& x);    //获取第i项的数据
    //遗憾的是这个抽象类似乎没用啊
};

#endif // LINEAR_LIST_H
