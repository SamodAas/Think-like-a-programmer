#include <iostream>
using std::cout;


class binaryTree{
    public countLeaves();
private:
    struct binaryTreeNode{
    int data;
    binaryTreeNode *leftNode;
    binaryTreeNode *rightNode;
    };
    typedef binaryTreeNode *treePtr;
    treePtr _root;
    int privateCountLeaves(treePtr root)
};

int binaryTree::privateCountLeaves(treePtr root){
    if (head == NULL) return 0;
    if (head->rightNode == NULL && head->leftNode == NULL) return 1;
    int leftCount = countLeaves(head->leftNode);
    int rightCount = countLeaves(head->rightNode);
    return leftCount + rightCount;
}

int binaryTree::countLeaves(){
    return privateCountLeaves(_root);
}
