#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};
typedef struct node *NODE;
NODE createNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->parent=NULL;
    return newNode;
}
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int countNodes(NODE root){
    if(root==NULL)
        return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
void heapifyUp(NODE root){
    while(root->parent&&root->data>root->parent->data){
        swap(&root->data,&root->parent->data);
        root=root->parent;
    }
}
void heapifyDown(NODE root){
    while(root){
        NODE largestNode = root;
        if(root->left&&root->left->data>largestNode->data)
            largestNode=root->left;
        if(root->right&&root->right->data>largestNode->data)
            largestNode=root->right;
        if(largestNode!=root){
            swap(&largestNode->data,&root->data);
            root=largestNode;
        }else{
            break;
        }
    }
}
NODE findPositionToInsert(NODE root,int count){
    int path[32],pathLen=0;
    while(count>1){
        path[pathLen++]=count%2;
        count/=2;
    }
    for(int i=pathLen-1;i>0;i--){
        if(path[i]==0) root=root->left;
        else
            root=root->right;
    }
    return root;
}
NODE findLastNode(NODE root, int count){
    int path[32],pathLen=0;
    while(count>1){
        path[pathLen++]=count%2;
        count/=2;
    }
    for(int i=pathLen-1;i>=0;i--){
        if(path[i]==0) root=root->left;
        else
            root=root->right;
    }
    return root;
}
NODE insert(NODE root, int data){
    if(root==NULL)
        return createNode(data);
    int nodesCount = countNodes(root);
    NODE parent = findPositionToInsert(root, nodesCount+1);
    NODE newNode = createNode(data);
    newNode->parent = parent;
    if(parent->left==NULL) parent->left=newNode;
    else
         parent->right=newNode;
    heapifyUp(newNode);
    return root;
}
NODE deletion(NODE root){
    if(root==NULL){
        return NULL;
    }
    int nodesCount =  countNodes(root);
    if(nodesCount==1){
        free(root);
        return NULL;
    }
    NODE lastNode = findLastNode(root,nodesCount);
    root->data=lastNode->data;
    if(lastNode->parent->left==lastNode)
        lastNode->parent->left=NULL;
    else
        lastNode->parent->right=NULL;
    free(lastNode);
    heapifyDown(root);
    return root;
}
void levelOrder(NODE root){
    if(root==NULL) return;
    NODE queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        NODE current = queue[front++];
        printf("%d --> ",current->data);
        if(current->left!=NULL) queue[rear++]=current->left;
        if(current->right!=NULL) queue[rear++]=current->right;
    }
}
void main(){
    NODE root=NULL;
    root = insert(root,1);
    root = insert(root,31);
    root = insert(root,0);
    root = insert(root,19);
    root = insert(root,13);
    root = insert(root,451);
    root = insert(root,781);
    root = insert(root,87);
    printf("\n");
    levelOrder(root);
    printf("\n");
    root = deletion(root);
    printf("\n");
    levelOrder(root);
}