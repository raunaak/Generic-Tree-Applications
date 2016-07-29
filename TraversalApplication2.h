#ifndef TRAVERSALAPPLICATION2_H
#define TRAVERSALAPPLICATION2_H
#include<iostream>
#include<cstddef>
#include<queue>
#include "BNode.h"
#include "TraversalApplication1.h"
using namespace std;

template<typename T>
void printLeftViewRecursion(BNode<T>* root, int level, int* maxLevel){
    /*
     * if a new level is reached print the data of this node
     * update the maxLevel reached to this level
     * printLeftView of the left subtree with 1 level down and updated maxLevel
     * printLeftView of the right subtree with 1 level down and updated maxLevel
     */
    if(root==NULL)return;
    
    if(*maxLevel<level){
        cout<<root->data<<" ";
        *maxLevel = level;
    }
    printLeftViewRecursion(root->left,level+1,maxLevel);
    printLeftViewRecursion(root->right,level+1,maxLevel);
}

template<typename T>
void printLeftViewRecursion(BNode<T>* root){
    int maxLevel = 0;
    printLeftViewRecursion(root, 1, &maxLevel);
}

template<typename T>
void printLeftViewNonRecursion(BNode<T>* root){
    /*
     * maxLevel is the maximum level reached
     * aim : traverse the tree using breadth first search
     * create a queue q1 initially containing root
     * create a queue q2 initially containing level of root = 1
     * while the queue q1 is not empty
     *      pop() from q1
     *      pop() from q2
     *      if a level higher than maximum level is reached print q1->data 
     *      and update maxLevel
     *      add all children in the queue q1 from left to right
     *      add their new levels = level+1 in the queue q2    
     */
    if(root!=NULL){
    int maxLevel = 0;
    queue<BNode<T>*> q1; queue<int> q2;
    q1.push(root); q2.push(1);
    while(!q1.empty()){
        BNode<T>* temp = q1.front(); q1.pop();
        int level = q2.front(); q2.pop();
        if(level>maxLevel){cout<<temp->data<<" "; maxLevel = level;}
        if(temp->left){q1.push(temp->left); q2.push(level+1);}
        if(temp->right){q1.push(temp->right); q2.push(level+1);}        
    }
    }
}


template<typename T>
void printNodesAtDistance(BNode<T>* root, int k){
    /*simple level order traversal
     Slight variation of the above method on line 64
     void printLeftViewNonRecursion(BNode<T>* root)*/
    BNode<T>* curr = root; int level = 1;
    queue<BNode<T>*> q1; q1.push(curr);
    queue<int> q2; q2.push(1);
    while(!q1.empty()){
        curr = q1.front(); q1.pop();
        level = q2.front(); q2.pop();
        if(level>k)break;
        if(level==k)cout<<curr->data<<" ";
        else{
            if(curr->left){q1.push(curr->left); q2.push(level+1);}
            if(curr->right){q1.push(curr->right); q2.push(level+1);}
        }
    }
    cout<<endl;
}

template<typename T>
bool ancestor(BNode<T>* root, const T& data){
    if(!root)return false;
    if(root->left)if(root->left->data==data||ancestor(root->left,data))cout<<root->data<<" ";
    if(root->right)if(root->right->data==data||ancestor(root->right,data))cout<<root->data<<" ";
}

template<typename T>
void printAncestor(BNode<T>* root, const T& data ){
    /*
     * if left subtree or right subtree contains the given node, then print it otherwise dont
     */
    ancestor(root, data);
    cout<<endl;
}


#endif /* TRAVERSALAPPLICATION2_H */

