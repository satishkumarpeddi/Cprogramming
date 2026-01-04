#include <stdio.h>
#include <stdlib.h>
struct node{
    int data; 
    struct node *left;
    struct node *right; 
};
typedef struct node *NODE;
NODE createNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
NODE insert(NODE root,int data){
    if(root==NULL) return createNode(data);
    if(data<root->data)
        root->left = insert(root->left,data);
    else if(data>root->data)
        root->right = insert(root->right,data);
    else
        return root;
    return root;
}
NODE lowestCommonAncestorOfBS(NODE root,NODE p,NODE q){
    if(root==NULL) return NULL;
    if(root->data>p->data&&root->data>q->data)
       return lowestCommonAncestorOfBS(root->left,p,q);
    else if(root->data<p->data&&root->data<q->data)
       return lowestCommonAncestorOfBS(root->right,p,q);
    else 
       return root;
}
void main(){
    NODE root=NULL;
    root = createNode(6);
    root->left = createNode(2);
    root->right = createNode(8);
    root->left->left = createNode(0);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);
    root->left->right->left = createNode(3);
    root->left->right->right = createNode(5);
    NODE result = lowestCommonAncestorOfBS(root,root->left,root->right);
    printf("%d -> is the lowest common ancestor of BinarySearchTree.\n",result->data);
}