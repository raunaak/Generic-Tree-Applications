#ifndef MORRISTRAVERSAL_H
#define MORRISTRAVERSAL_H

#include "BNode.h"

template<typename T>
BNode<T>* inorderPredecessor(BNode<T>* root){
    BNode<T>* pre = root; BNode<T>* curr = root->left;
    if(!curr)return NULL;
    while(curr!=NULL&&curr!=root){ pre=curr; curr=curr->right;}
    if(curr==root){pre->right=NULL; return curr;}
    else {pre->right=root; return pre;}
}

template<typename T>
void morrisInorder(BNode<T>* root){
    /* Idea:
     * Go to left subtree, and print every node inorder fashion
     * print the current node
     * Go to right subtree, and print every node inorder fashion
     * 
     * Why do we need recursion( which is basically stack)?
     * To get back to current node
     * When do we need to get back to the current node?
     * After we print the last inorder node of the left subtree, which is basically known as inorder predecessor
     * So, to get to current node, we create a link between inorder predecessor(if exists) and current node for every node
     * Inorder predecessor will not have a right child
     * So, make its right child as the current node to reach it again
     */
    
    /* Algorithm:
     * Step1: current node is root
     * Step2: go to predecessor
     *          if(predecessor is null) print node and and make its right child as root (current = current.right)
     *          if(predecessor is not null) make predecessor's right child as root and make root's left child as root (current = current.left)      
     * But, the trick is to think ahead
     *          Since, we are changing the structure of tree by creating right node to inorder predecessor
     *          What happens if we encounter predecessor as the same node
     *          It means we had once created this link, promising that it will only be printed once its inorder predecessor is printed
     *          Now the predecessor is printed  "print node and and make its right child as root (current = current.right)"
     *          Now we can print this node and make its right child as root (current=current.right)
     *          Step2: (continued) if(predecessor = root) print root and make root's right child as root
     *          When will the loop end
     *          root is a node I shall print now or in the future 
     *          when no such node is left, i shall stop the loop
     *          i.e. when root=NULL
     */ 
    while(root){    
    BNode<T>* predecessor = inorderPredecessor(root);
    if(predecessor!=root&&predecessor){root=root->left;}
    else{cout<<root->data<<" "; root=root->right;}
    }
}


#endif /* MORRISTRAVERSAL_H */

