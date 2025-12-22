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
int* maxElementInLevel(NODE root,int *returnSize){
    if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    int* result = (int*)malloc(100*sizeof(int));
    NODE queue[100];
    *returnSize=0;
    int front=0;
    int rear=0;
    queue[rear++]=root;
    while(front<rear){
        int size = rear-front;
        int max = INT_MIN;
        for(int i=0;i<size;i++){
            NODE node = queue[front++];
            if(node->data>max){
                max = node->data;
            } 
            if(node->left) queue[rear++] = node->left;
            if(node->right) queue[rear++] = node->right;
        }
        result[(*returnSize)++] = max;
    }
    return result;
}
void main(){
    NODE root=NULL;
    root=createNode(1);
    root->left=createNode(3);
    root->right=createNode(2);
    root->left->left = createNode(5);
    root->left->right = createNode(3);
    root->right->right = createNode(9);
    int returnSize=0;
    int* result = (int*)malloc(100*sizeof(int));
    result = maxElementInLevel(root,&returnSize);
    for(int i=0;i<3;i++){
        printf("%d --> ",result[i]);
    }
}