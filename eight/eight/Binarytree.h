
#ifndef BinaryTree_
#define BinaryTree_

#include "BinarytreeNode.h"

template<class T>
class BinaryTree
{
public:
    BinaryTree(){root =0;}                                                    //空构造函数
    ~BinaryTree();
    bool IsEmpty() const {return ((root)? false : true);}
    bool Root(T &x) const;
    void MakeTree(const T& element,BinaryTree<T> &left,BinaryTree<T> &right);  //递归构造树的函数
    void BreakTree(T& element, BinaryTree<T> &left, BinaryTree<T> &right);
    void PreOrder(void (*visit) (BinaryTreeNode<T> *u)) {PreOrder(visit,root);}  //这个形参的
    void Inorder(void (*visit) (BinaryTreeNode<T> *u))  {Inorder(visit,root);}
    void PostOrder(void (*visit) (BinaryTreeNode<T> *u)) {PostOrder(visit,root);}

private:
    BinaryTreeNode<T> *root;
    void PreOrder(void (* visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);   //这个函数的形参有两个，一个是visit函数，另外一个是
                                                                                //二叉树的节点类型的指针。因此要使用这个函数必须要有
                                                                                //visit函数的实现，第二个元素一般是root节点。

    void InOrder(void (* visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
    void PostOrder(void (* visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
};

template<class T>
bool BinaryTree<T>::Root(T& x) const
{
    if(root) {x=root->data; return true;}
    else
        return false;
}


template<class T>
void BinaryTree<T>::MakeTree(const T& element,BinaryTree<T>& left,BinaryTree<T>& right)  //用element和left，right生成一个新的树
{
    root=new BinaryTreeNode<T>
            (element,left.root,right.root);
}


template<class T>
void BinaryTree<T>::BreakTree(T& element,BinaryTree<T>& left,BinaryTree<T>& right)  //分解一棵树
{
    //throw暂时不加上去
    element=root->data;
    left.root=root->leftNode;
    right.root=root->rightNode;

    delete root;
}

template<class T>
void BinaryTree<T>::PreOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *node) //先实现前序遍历
{
    if(node)
    {
        visit(node);
        PreOrder(visit,node->leftNode);
        PreOrder(visit,node->rightNode);
    }
}





#endif // BinaryTree_
