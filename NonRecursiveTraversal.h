#ifndef NONRECURSIVETRAVERSAL_H
#define NONRECURSIVETRAVERSAL_H
#include<iostream>
#include"BNode.h"
#include <cstddef>
#include<stack>
using namespace std;
template<typename T>
void inorderWithoutRecursion(BNode<T>* root){
    /*
     * Recursion is basically using stack to store function calls
     * A standard technique to remove recursion is to stacks and a loop
     * Lets focus on 3 questions
     *  i.  How is stack built?
     *      first root is added
     *      if root is not null, left is put on end of the stack
     *      if left is not null, above process is followed
     *      else last element is popped out of the stack, it is printed and right node to it is added in the stack
     *      This is how we shall build our loop
     *      Step 1. Root is added to an empty stack, root is our current element
     *      Step 2. Move to the left until null is found
     *      Step 3. Pop an element from stack, print it and add its right element to it. 
     *      This right element becomes our current element
     *  ii. When does function stop
     *      Initial guess is when the stack is empty but the stack at the beginning also
     *      In the beginning, our current element is the element which is reached when we traverse left and left and left.... of the root element
     *      Also, in this tree       1
     *                              / \
     *                             2   3
     *      when 1 is popped, stack is empty
     *      There is another entity, current element, which says from this element onwards, you have left the tree to print
     *      so, this must also be null
     *      Step 4. Step 1, Step 2 and Step 3 are continued until current node is not null and stack is not empty
     */
    stack<BNode<T>*> s; 
    BNode<T>* curr = root; 
    while(!s.empty()||curr){
        while(curr!=NULL){s.push(curr); curr=curr->left;}
        curr = s.top(); s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

#endif /* NONRECURSIVETRAVERSAL_H */

