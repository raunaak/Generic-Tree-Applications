#ifndef LOWESTCOMMONANCESTOR_H
#define LOWESTCOMMONANCESTOR_H

#include<iostream>
#include<cstddef>
#include<vector>
#include "BNode.h"
#include "TraversalApplication1.h"
#include "TraversalApplication2.h"
#include "TraversalAlgo.h"
using namespace std;

template<typename T>
bool searchAncestorList(BNode<T>* root, vector<T> &v, const T& key){
    if(!root)return false;
    if(root->data==key){v.insert(v.begin()+0,root->data); return true;}
    if(searchAncestorList(root->left,v,key)||searchAncestorList(root->right,v,key)){v.insert(v.begin()+0,root->data); return true;}
    return false;
}

template<typename T>
T lastCommon(vector<T> &v1, vector<T> &v2){
    for(int i=0; i<min(v1.size(),v2.size()); i++){
        if(v1[i]!=v2[i])return ((i>0)?v1[i-1]:NULL);
    }
    return v1[min(v1.size(),v2.size())-1];
}

template<typename T>
T lowestCommonAncestor(BNode<T>* root, const T& key1, const T& key2){
    vector<T> v1, v2;
    searchAncestorList(root, v1, key1);
    searchAncestorList(root, v2, key2);
    return lastCommon(v1, v2);
}
#endif /* LOWESTCOMMONANCESTOR_H */

