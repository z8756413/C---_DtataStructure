

#ifndef BinaryTreeNode_
#define BinaryTreeNode_

#include<iostream>
using namespace std;

template <class T>
class BinaryTreeNode{
    friend void visit(BinaryTreeNode<T> *);      //友元函数
    friend void InOrder(BinaryTreeNode<T> *);
    friend void PreOrder(BinaryTreeNode<T> *);
    friend void PostOrder(BinaryTreeNode<T> *);
public:
    BinaryTreeNode(){leftNode=rightNode=0;}                                 //构造函数
    BinaryTreeNode(const T& e)
    {
        data=e;
        leftNode=rightNode=0;
    }
    BinaryTreeNode(const T& e,BinaryTreeNode *left,BinaryTreeNode *right)   //复制构造函数
    {
        data=e;
        leftNode=left;
        rightNode=right;
    }
//private:
    T data;
    BinaryTreeNode<T> *leftNode,
                        *rightNode;
};


template<class T>
void visit(BinaryTreeNode<T> *node)
{
    cout<<node->data <<'  '<< endl;
}

template<class T>                               //中序遍历
void InOrder(BinaryTreeNode<T> *node)
{
    if(node)
    {
        InOrder(node->leftNode);
        visit(node);
        InOrder(node->rightNode);
    }
}

template<class T>                                 //前序遍历
void PreOrder(BinaryTreeNode<T> *node)
{
    if(node)
    {
        visit(node);
        PreOrder(node->leftNode);
        PreOrder(node->rightNode);
    }
}

#endif
