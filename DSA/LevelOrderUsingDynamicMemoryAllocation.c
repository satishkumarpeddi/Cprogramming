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
void levelOrder(NODE root,int***result,int* returnSize,int** returnColumnSize){
    if(root==NULL){
        *returnSize=0;
        *returnColumnSize=NULL;
        return;
    }
    *result = (int**)malloc(100*sizeof(int*));
    *returnColumnSize = (int*)calloc(100,sizeof(int));
    NODE queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    int level=0;
    while(front<rear){
        int levelSize = rear-front;
        (*result)[level] = (int*)malloc(levelSize*sizeof(int));
        (*returnColumnSize)[level]=levelSize;
        for(int i=0;i<levelSize;i++){
            NODE node = queue[front++];
            (*result)[level][i] = node->data;
            if(node->left) queue[rear++]=node->left;
            if(node->right) queue[rear++]=node->right;
        }
        level++;
    }
    *returnSize=level;
}
void main(){
    NODE root=NULL;
    root=createNode(3);
    root->left=createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right= createNode(7);
    int** result;
    int returnSize;
    int* returnColumnSize;
    levelOrder(root,&result,&returnSize,&returnColumnSize);
    printf("The level order traversal : ");
    for(int i=0;i<returnSize;i++){
        printf("[");
        for(int j=0;j<returnColumnSize[i];j++){
            printf(" %d ",result[i][j]);
        }
        printf("]");
    }
}