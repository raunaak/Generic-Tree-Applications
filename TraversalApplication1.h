#ifndef TRAVERSALAPPLICATION1_H
#define TRAVERSALAPPLICATION1_H
#include<cstddef>
#include<limits>
#include<algorithm>
#include<queue>
#include <vector>
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
int diameter(BNode<T>* root, int* height){
    /*
     * BASE CASE: if root is NULL diameter is null
     * diameter is maximum of 
     *      diameter of left subtree
     *      diameter of right subtree
     *      height of left subtree + height of right subtree + 1
     *      to obtain height, we have added another parameter as height pointer
     *      BASE CASE: it returns height of null tree = 0
     *      it returns max(height of left subtree, height of right subtree) + 1
     */
    if(root==NULL){*height = 0; return 0;}
    int h1 = 0; int h2 = 0;
    int d1 = diameter(root->left,&h1);
    int d2 = diameter(root->right,&h2);
    *height = max(h1,h2)+1;
    return max(max(d1,d2),h1+h2+1);
}

template<typename T>
int diameter(BNode<T>* root){
    int h=0;
    diameter(root, &h);
}

template<typename T>
int maxWidth(BNode<T>* root){
    /*simple level order traversal
     Slight variation of the above method on line 64
     void printLeftViewNonRecursion(BNode<T>* root)*/
    BNode<T>* curr = root; int currSum = 0; int maxSum = 0; int preLevel = 0; int currLevel = 1;
    queue<BNode<T>*> q1; q1.push(curr);
    queue<int> q2; q2.push(1);
    while(!q1.empty()){
        curr = q1.front(); q1.pop();
        currLevel = q2.front(); q2.pop();
        if(curr->left){q1.push(curr->left); q2.push(currLevel+1);}
        if(curr->right){q1.push(curr->right); q2.push(currLevel+1);}
        if(preLevel<currLevel)currSum=1;
        else currSum++;
        preLevel = currLevel;
        if(maxSum<currSum)maxSum = currSum;
    }
    return maxSum;
}

#endif /* TRAVERSALAPPLICATION1_H */