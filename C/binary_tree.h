#pragma once 
#ifndef binary_tree_h
#define binary_tree_h
#include <stdio.h>
#include <stdlib.h>
#define ElementType int
typedef struct TreeNode* BinaryTree;
typedef struct TreeNode* NodePointer;
typedef struct TreeNode TreeNode;
typedef enum InsertStatus STATUS;
struct TreeNode{
    ElementType element;
    BinaryTree left;
    BinaryTree right;
};
enum InsertStatus{
    NOTREE=-1,
    SUCCESS,
    EXITS
};
void PreOder(BinaryTree T, int Deep);
STATUS InsertNodeToBTree(BinaryTree T, NodePointer N);
NodePointer FindBTree(BinaryTree T,  ElementType N);
BinaryTree DestroyBTree(BinaryTree T);
NodePointer FindMinNode(BinaryTree T);
#endif
