#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct node *NODE;
NODE createNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height =1;
    return newNode;
}
int height(NODE root){
    if(root==NULL)
        return 0;
    return root->height;
}
int balanceFactor(NODE root){
    if(root==NULL)
        return 0;
    return height(root->left)-height(root->right);
}
int maxMethod(int a,int b){
    return (a>b)?a:b;
}
NODE rightRotation(NODE y){
    NODE x = y->left;
    NODE T2 = x->right;
    y->left= T2;
    x->right=y;
    y->height = 1+maxMethod(height(y->left),height(y->right));
    x->height = 1+maxMethod(height(x->left),height(x->right));
    return x;
}
NODE leftRotation(NODE x){
    NODE y = x->right;
    NODE T2 = y->left;
    x->right = T2;
    y->left=  x;
    y->height = 1+maxMethod(height(y->left),height(y->right));
    x->height = 1+maxMethod(height(x->left),height(x->right));
    return y;
}

NODE insert(NODE root,int data){
    if(root==NULL)
        return createNode(data);
    if(data<root->data)
        root->left= insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    else 
        return root;
    root->height = 1+maxMethod(height(root->left),height(root->right));
    int balanceFactorValue = balanceFactor(root);
    if(balanceFactorValue>1&&data<root->left->data){
        return rightRotation(root);
    }
    if(balanceFactorValue<-1&&data>root->right->data){
        return leftRotation(root);
    }
    if(balanceFactorValue>1&&data>root->left->data){
        root->left= leftRotation(root->left);
        return rightRotation(root);
    }
    if(balanceFactorValue<-1&&data<root->right->data){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}
NODE minValueNode(NODE root){
    NODE currentNode=root;
    if(currentNode->left!=NULL){
        currentNode=currentNode->left;
    }
    return currentNode;
}
NODE deletion(NODE root,int data){
    if(root==NULL) return NULL;
    if(data<root->data){
        root->left = deletion(root->left,data);
    }else if(data>root->data){
        root->right = deletion(root->right,data);
    }else{
        if(root->right==NULL)
            return root->left;
        if(root->left==NULL)
            return root->right;
        NODE temp = minValueNode(root->right);
        root->data=temp->data;
        root->right= deletion(root->right,temp->data);
    }
    root->height = 1+maxMethod(height(root->left),height(root->right));
    int balanceFactorValue = balanceFactor(root);
    if(balanceFactorValue>1&&balanceFactor(root->left)>=0){
        return rightRotation(root);
    }
    if(balanceFactorValue>1&&balanceFactor(root->left)<0){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if(balanceFactorValue<-1&&balanceFactor(root->right)<=0){
        return leftRotation(root);
    }
    if(balanceFactorValue<-1&&balanceFactor(root->right)>0){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}
void inOrder(NODE root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d --> ",root->data);
        inOrder(root->right);
    }
}
void main(){
    NODE root=NULL;
    root = insert(root,3);
    root = insert(root,31);
    root = insert(root,33);
    root = insert(root,63);
    root = insert(root,93);
    root = insert(root,381);
    root = insert(root,83);
    inOrder(root);
    printf("-----------------------\n");
    root = deletion(root,381);
    inOrder(root);
    printf("---------------------\n");
}