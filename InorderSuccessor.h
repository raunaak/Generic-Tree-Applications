#ifndef INORDERSUCCESSOR_H
#define INORDERSUCCESSOR_H
#include"TraversalApplication1.h"
#include"BNode.h"
#include<limits>
#include<cstddef>
#include<iostream>
using namespace std;

template<typename T>
BNode<T>* inorderSuccessor(BNode<T>* root, const T& data, bool &b){
    
     /* Idea:
     * A boolean argument is added which changes its value to true when root.data is encountered
     */
    
    /*Algorithm:
     * if root is null return null
     * if left subtree returns 
     *      i. true with null, it means that the last node encountered had value = data (our key) so we return root
     *      ii. returns true with a non-null node, we have already found the inorder successor, so simply return it
     *      iii. if left subtree returns null
     *          a. if root.data = data, we have found our node, change b to true 
     * let the traversal continue using inorder
     */
    
    if(!root)return NULL;
    BNode<T>* n = inorderSuccessor(root->left, data, b);
    if(b&&n)return n;
    else if(b)return root;
    if(root->data==data)b = true;
    return inorderSuccessor(root->right, data, b);
    
}
template<typename T>
BNode<T>* inorderSuccessor(BNode<T>* root, const T& data){
    bool b = false;
    return inorderSuccessor(root, data, b);
                
}
/*const int INT_MIN = numeric_limits<int>::min();

template<typename T>
BNode<T>* searchFirstRightAncestor(BNode<T>* root, const T& data){
    bool b = false;
    return searchFirstRightAncestor(root, data, b);
}
template<typename T>
BNode<T>* searchFirstRightAncestor(BNode<T>* root, const T& data, bool &b){
    if(!root)return NULL;
    if(root->left)if(root->left->data==data)return root;
    BNode<T>* n1 = searchFirstRightAncestor(root->left, data, b);
    if(n1)return n1;
    BNode<T>* n2 = searchFirstRightAncestor(root->right, data, b);
    if(n2)return n2;
    return NULL;
}

template<typename T>
BNode<T>* inorderSuccessor(BNode<T>* root, const T& data){
    BNode<T>* node = search(root, data);
    if(node->left){
        node = node->left;
        while(node->right)node=node->right;
        return node;
    }
    return searchFirstRightAncestor(root, data);
}

template<typename T>
T& inordersuccessor(BNode<T>* root, const T& data){
    BNode<T>* node = inorderSuccessor(root, data);
    return ((node)?node->data:INT_MIN);
}*/

#endif /* INORDERSUCCESSOR_H */

