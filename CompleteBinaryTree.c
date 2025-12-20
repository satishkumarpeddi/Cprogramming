#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
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
NODE insertComplete(NODE root,int data){
    NODE newNode = createNode(data);
    if(root==NULL) return newNode;
    NODE queue[MAX];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        NODE curr = queue[front++];
        if(curr->left==NULL){
            curr->left = newNode;
            return root;
        }
        if(curr->right==NULL){
            curr->right= newNode;
            return root;
        }
        queue[rear++]=curr->left;
        queue[rear++]=curr->right;
    }
    return root;
}
bool isCompleteTree(NODE root){
    if(root==NULL){
        return true;
    }
    NODE queue[MAX];
    bool isSeenNull=false;
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        NODE curr = queue[front++];
        if(curr==NULL)
            isSeenNull=true;
        else{
            if(isSeenNull) return false;
            queue[rear++]=curr->left;
            queue[rear++]=curr->right;
        }
    }
    return true;
}
void main(){
    NODE rootComplete=NULL;
    NODE rootNotComplete = NULL;
    int arr[11] = {9,1,4,5,8,10,11,54,-1,0,-2};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        rootComplete = insertComplete(rootComplete,arr[i]);
        rootNotComplete = insert(rootNotComplete,arr[i]);
    }
    printf("Is the BinaryTree (Complete) Complete/Not : %s\n",
           isCompleteTree(rootComplete) ? "Yes" : "No");
    printf("Is the BinaryTree (Not Complete) Complete/Not : %s\n",
           isCompleteTree(rootNotComplete) ? "Yes" : "No");
}