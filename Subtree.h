#ifndef SUBTREE_H
#define SUBTREE_H
#include<iostream>
#include<cstddef>
#include "BNode.h"
#include "TraversalApplication1.h"
#include "TraversalApplication2.h"
#include "TraversalAlgo.h"
using namespace std;

template<typename T>
bool equalTree(BNode<T>* root, BNode<T>* subroot){
    if(!subroot)return true;
    else if(subroot&&root){
        return (root->data==subroot->data)&&equalTree(root->left,subroot->left)&&equalTree(root->right,subroot->right);
    }
    else return false;
}

template<typename T>
bool subtree(BNode<T>* root, BNode<T>* subroot){
    /*
     * traverse the binary tree and check at every node whether subroot.data is equal to root.data
     * if(equal)traverse according to the smaller tree and check whether they are equal
     */
    bool a = false, b = false, c = false;
    if(root&&subroot){
    if(root->data==subroot->data)a=equalTree(root, subroot);
    if(root->left)b=subtree(root->left, subroot);
    if(root->right)c=subtree(root->right, subroot);
    }
    return a||b||c;
}


#endif /* SUBTREE_H */

