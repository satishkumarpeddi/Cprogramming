#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
int maxMethod(int a,int b){
    return (a>b)?a:b;
}
int height(NODE root){
    if(root==NULL)
        return 0;
    return 1+maxMethod(height(root->left),height(root->right));
}
void levelOrderUtil(NODE root,int ***result,int level,int *returnColumnSize){
    if(root==NULL)  
        return;
    (*result)[level][returnColumnSize[level]++]=root->data;
    levelOrderUtil(root->left,result,level+1,returnColumnSize);
    levelOrderUtil(root->right,result,level+1,returnColumnSize);
}
void levelOrder(NODE root,int*** result,int * returnSize,int **returnColumnSize){
    if(root==NULL){
        return;
    }
    *returnSize = height(root);
    *result = (int**)malloc(height(root)*sizeof(int*));
    *returnColumnSize = (int*)calloc(height(root),sizeof(int));
    for(int i=0;i<height(root);i++){
        (*result)[i] = (int*)malloc(sizeof(int)*(1<<i));
    }
    levelOrderUtil(root,result,0,*returnColumnSize);
}
void main(){
    NODE root=NULL;
    root=createNode(3);
    root->left=createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right= createNode(7);
    int **result;
    int returnSize;
    int *returnColumnSize;
    levelOrder(root,&result,&returnSize,&returnColumnSize);
    printf("The Level Order Traversal Using DFS : ");
    for(int i=0;i<returnSize;i++){
        printf("[");
        for(int j=0;j<returnColumnSize[i];j++){
            printf(" %d ",result[i][j]);
        }
        printf("]");
    }
}