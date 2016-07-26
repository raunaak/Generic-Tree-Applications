#ifndef TRAVERSALAPPLICATION_H
#define TRAVERSALAPPLICATION_H
#include<cstddef>
#include<limits>
#include<algorithm>
#include<queue>
#include"BNode.h"
int INT_MAX = numeric_limits<int>::max();
int INT_MIN = numeric_limits<int>::min();
using namespace std;
template<typename T>
int totalNodes(BNode<T>* node){
    /*
     * 1. If current node is null, return 0
     * 2. else return size of left subtree + size of right subtree + 1
     */
    if(node==NULL)return 0;
    return totalNodes(node->left)+totalNodes(node->right)+1;
}

int maxElement(BNode<int>* root){
    /*
     * if current element is null return INT_MIN
     * return maximum of maxElement in left subtree, right subtree and current element
     */
    if(root==NULL)return INT_MIN;
    else return max(max(maxElement(root->left),maxElement(root->right)),root->data);
}

int minElement(BNode<int>* root){
    /*
     * if current element is null return INT_MAX
     * return minimum of minElement in left subtree, right subtree and current element
     */
    if(root==NULL)return INT_MAX;
    else return min(min(minElement(root->left),minElement(root->right)),root->data);
}

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
int height(BNode<T>* root){
    /*         
     * if current root is empty return 0
     * maximum of height of left subtree and height of right subtree + 1
     * EXAMPLE  height of tree = 2
     *                         2
     *                        /  \
     *                      1      3     
     */
    if(root==NULL)return 0;
    return max(height(root->left),height(root->right))+1;
}

template<typename T>
int diameter(BNode<T>* root, int height){
    /*
     * BASE CASE: if root is NULL diameter is null
     * diameter is maximum of 
     *      diameter of left subtree
     *      diameter of right subtree
     *      height of left subtree + height of right subtree + 1
     *      to obtain height, we have added another parameter as height argument
     */
    if(root==NULL){height = 0; return 0;}
    int h1 = 0; int h2 = 0;
    int d1 = diameter(root->left,h1);
    int d2 = diameter(root->right,h2);
    height = max(h1,h2)+1;
    return max(max(d1,d2),h1+h2+1);
}

template<typename T>
int diameter(BNode<T>* root){
    int h=0;
    diameter(root, h);
}
#endif /* TRAVERSALAPPLICATION_H */