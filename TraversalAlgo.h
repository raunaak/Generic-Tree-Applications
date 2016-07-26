#ifndef TRAVERSALALGO_H
#define TRAVERSALALGO_H
#include<cstddef>
#include<iostream>
#include "BNode.h"
using namespace std;
template<typename T> 
void inorder(BNode<T>* root){
    /*Algorithm:
     * 1. if current node is not null
     *      i. Print the left subtree in inorder form
     *      ii. Print the data of current node
     *      iii. Travel the right subtree in inorder form
     */
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }            
}

template<typename T>void preorder(BNode<T>* root){
    /*Algorithm:
     * if current node is not null
     * 1. Print the current node
     *      i. Print the data of current node
     *      ii. Print the left subtree in preorder form
     *      iii. Print the right subtree in preorder form
     */
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

template<typename T>void postorder(BNode<T>* root){
    /*Algorithm:
     1. if current node is not null
     *      i. Print the left subtree in postorder form
     *      ii. Print the right subtree in postorder form
     *      iii. Print the data of current node
     */
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
#endif /* TRAVERSALALGO_H */

