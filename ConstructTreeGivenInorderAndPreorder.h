#ifndef CONSTRUCTTREEGIVENINORDERANDPREORDER_H
#define CONSTRUCTTREEGIVENINORDERANDPREORDER_H
#include"BNode.h"
template<typename T>
BNode<T>* createTree(T* in, int i, int j, T* pre, int x, int y){
    /*
     * First element of preorder contains root 
     * Create root using the first element
     * Find the root element in inorder array 
     * The left part consists of nodes of the left subtree and right part consists of nodes of the right subtree
     * Thus, we obtain inorder traversal of the left and right subtree
     * Thus, we have obtained the number of nodes in the left subtree (lets say l) and the number of nodes in the right subtree(lets say r)
     * After the initial element, next l nodes are basically preorder traversal of the left subtree and r nodes ahead of it are preorder traversal of the right subtree
     */
    if(i>=j)return NULL;
    BNode<T>* node = newNode(pre[x]);
    int k=i;
    while(k<j){if(in[k]==pre[x])break; k++;}
    node->left = createTree(in, i, k, pre, x+1, x+k+1);
    node->right = createTree(in, k+1, j, pre, x+k+1, y);
    return node;
}

template<typename T>
BNode<T>* createTree(T* in, T* pre, int n){
    return createTree(in, 0, n, pre, 0, n);
}


#endif /* CONSTRUCTTREEGIVENINORDERANDPREORDER_H */

