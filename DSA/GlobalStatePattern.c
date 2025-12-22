#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;
int maxDiameter=0;

NODE createNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
int maxMethod(int a,int b){
    return (a>b)?a:b;
}
int height(NODE root){
    if(root==NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    maxDiameter = maxMethod(maxDiameter,left+right+1);
    return maxMethod(left,right)+1;
}
int diameterOfBinaryTree(NODE root){
    maxDiameter=0;
    height(root);
    return maxDiameter;
}

void main(){
    NODE root=NULL;
    root=createNode(1);
    root->left=createNode(3);
    root->right=createNode(2);
    root->left->left = createNode(5);
    root->left->right = createNode(3);
    root->right->right = createNode(9);
    printf("The Max Diameter : %d\n",diameterOfBinaryTree(root));
}