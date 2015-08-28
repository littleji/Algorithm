#include "binary_tree.h" 
void Error(const char * string){
    printf("%s\n", string);
    exit(-1);
}

BinaryTree BuildBTree( ElementType element){
     NodePointer btree = NULL;
     btree = malloc(sizeof(TreeNode));
     if(btree == NULL)
         Error("cant malloc for btree!");
     btree->left = NULL;
     btree->right = NULL;
     btree->element = element;
     return btree;

}
BinaryTree DestroyBTree(BinaryTree T){
    if (T == NULL) {
        return NULL;
    } else {
        DestroyBTree(T->left);
        DestroyBTree(T->right);
        free(T);
        T = NULL;
    }
    return NULL;
}
NodePointer FindBTree(BinaryTree T,  ElementType N){
    if ( T == NULL) {
        return NULL;
    } else {
        if (T->element == N)
            return T;
        if(N < T->element)
            return FindBTree(T->left, N);
        if(N > T->element)
            return FindBTree(T->right, N);
    }
}
STATUS InsertNodeToBTree(BinaryTree T, NodePointer N){
    if ( T == NULL) {
        return NOTREE;
    } else {
        if (T->element == N->element)
            return EXITS;
        if (N->element < T->element ){
            if( T->left != NULL){
                return InsertNodeToBTree(T->left, N);
            }
            else {
                T->left = N;
                return SUCCESS;
            }
        }
        if(N->element > T->element ){
            if(T->right != NULL)
                return InsertNodeToBTree(T->right, N);
            else {
                T->right = N;
                return SUCCESS;
            }
        }
    }
}
void PreOder(BinaryTree T, int Deep){
    if(T == NULL)
        return;
    int i;
    for(i = 0; i<Deep; i++)
        printf("%s", "\t");
    printf("%d\n", T->element);
    PreOder(T->left, Deep + 1);
    PreOder(T->right, Deep + 1);
}
void PostOder(BinaryTree T, int Deep){
    if(T == NULL)
        return;
    int i;
    PostOder(T->left, Deep + 1);
    PostOder(T->right, Deep + 1);
    for(i = 0; i < Deep; i++)
        printf("%s", "\t");
    printf("%d\n", T->element);

}
BinaryTree DeleteNode(BinaryTree T, ElementType element){
    if (T == NULL)
        Error("cant find the BinaryTree!");
    if(element < T->element)
        DeleteNode(T->left, element);
    else if(element > T->element)
            DeleteNode(T->right, element);
    else if(T->left && T->right){
            NodePointer tmp = FindMinNode(T->right);
            T->element = tmp->element;
            DeleteNode(T->right, tmp->element);
        }
    else{//zero or one child 
        NodePointer tmp = T;
       if (T->left ){
           T = T->left;
           free(tmp);
           tmp = NULL;
       }
       if (T->right){
           T = T->right;
           free(tmp);
           tmp = NULL;
       }
       else {
           free(T);
           T = NULL;
       }
    }
    return T;
}
NodePointer FindMinNode(BinaryTree T){
   if(T == NULL)
       return NULL;
   NodePointer tmp = T;
   while(tmp->left)
       tmp = tmp->left;
   return tmp;
}

int main(int argc, char const* argv[])
{
    BinaryTree btree = NULL;
    btree = BuildBTree(5);
    NodePointer  a,b,c,d,e,f,g;
    a = BuildBTree(4);
    b = BuildBTree(2);
    c = BuildBTree(3);
    f = BuildBTree(7);
    d = BuildBTree(1);
    e = BuildBTree(6);
    g = BuildBTree(8);

    InsertNodeToBTree(btree,a);
    InsertNodeToBTree(btree,b);
    InsertNodeToBTree(btree,c);
    InsertNodeToBTree(btree,d);
    InsertNodeToBTree(btree,f);
    InsertNodeToBTree(btree,e);
    InsertNodeToBTree(btree,g);


    printf("PreOder______________\n");
   // PreOder(btree, 0);
    //printf("PostOder______________\n");
   // PostOder(btree, 0);
    DeleteNode(btree, 7);
   // PreOder(btree, 0);
    DestroyBTree(btree);
    return 0;
}
