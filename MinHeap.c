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
int countNodes(NODE root){
    if(root==NULL)
        return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void heapifyUp(NODE root){
    while(root->parent&&root->parent->data>root->data){
        swap(&root->parent->data,&root->data);
        root=root->parent;
    }
}
void heapifyDown(NODE root){
    while(root){
        NODE smallest = root;
        if(root->left&&root->left->data<smallest->data)
            smallest = root->left;
        if(root->right&&root->right->data<smallest->data)
            smallest = root->right;
        if(smallest!=root){
            swap(&smallest->data,&root->data);
            root=smallest;
        }else{
            break;
        }
    }
}
NODE findInsertPosition(NODE root,int count){
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
NODE findLastNode(NODE root,int count){
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
NODE insert(NODE root,int data){
    if(root==NULL)
        return createNode(data);
    int nodesCount = countNodes(root);
    NODE parent = findInsertPosition(root,nodesCount+1);
    NODE newNode = createNode(data);
    newNode->parent = parent;
    if(parent->left==NULL)
        parent->left=newNode;
    else
        parent->right=newNode;
    heapifyUp(newNode);
    return root;
}
NODE deletion(NODE root){
    if(root==NULL)
        return root;
    int nodesCount = countNodes(root);
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
    heapifyDown(root);
    return root;
}
void levelOrder(NODE root){
    NODE queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        NODE currentNode = queue[front++];
        printf("%d --> ",currentNode->data);
        if(currentNode->left!=NULL) queue[rear++]=currentNode->left;
        if(currentNode->right!=NULL) queue[rear++] = currentNode->right;
    }
}
void main(){
    NODE root=NULL;
    root = insert(root,3);
    root = insert(root,9);
    root = insert(root,13);
    root = insert(root,1);
    root = insert(root,73);
    root = insert(root,913);
    root = insert(root,33);
    root = insert(root,34);
    levelOrder(root);
    printf("\n---------------------------\n");
    root = deletion(root);
    levelOrder(root);
    printf("\n---------------------------\n");

}