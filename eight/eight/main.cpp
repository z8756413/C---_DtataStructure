#include <iostream>
#include "BinarytreeNode.h"
#include "Binarytree.h"

using namespace std;

int count=0;
BinaryTree<int> a,x,y,z;

template<class T>
void ct(BinaryTreeNode<T> *root) {count++;}


int main()
{
    y.MakeTree(1,a,a);
    z.MakeTree(2,a,a);
    x.MakeTree(3,y,z);
    y.MakeTree(4,x,a);
    y.PreOrder(ct);

    cout << count << endl;
    return 0;
}
