//
//  main.cpp
//  BinaryTreeHeight
//
//  Created by chenyufeng on 10/2/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 *  求二叉树的高度
 */

typedef struct TreeNode{
    int data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
}Node;

void CreateBinaryNode(Node **node)
{
    int num;
    cin >> num;

    if (num == -1)
    {
        return;
    }

    *node = new Node;
    (*node)->data = num;
    (*node)->lChild = NULL;
    (*node)->rChild = NULL;

    cout << "请输入"<< num << "的左孩子节点：";
    CreateBinaryNode(&((*node)->lChild));
    cout << "请输入"<< num << "的右孩子节点：";
    CreateBinaryNode(&((*node)->rChild));
}

// 树的高度
int BinaryTreeHeight(Node *node)
{
    int treeHeight = 0;
    if (node != NULL)
    {
        int leftHeight = BinaryTreeHeight(node->lChild);
        int rightHeight = BinaryTreeHeight(node->rChild);
        treeHeight = leftHeight >= rightHeight? leftHeight + 1:rightHeight + 1;
    }

    return treeHeight;
}

int main(int argc, const char * argv[])
{
    cout << "请输入节点，输入-1结束:"<< endl;
    Node *node;
    CreateBinaryNode(&node);

    int treeHeight = BinaryTreeHeight(node);
    cout << treeHeight << endl;

    return 0;
}
