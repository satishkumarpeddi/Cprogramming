#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
struct node{
    int key;
    char value[50];
    struct node *next;
};
typedef struct node *NODE;
NODE hashTable[SIZE];
NODE createNode(int key,char *value){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->key=key;
    strcpy(newNode->value,value);
    newNode->next=NULL;
    return newNode;
}
int hashFunction(int key){
    return key%SIZE;
}
void insert(int key,char *value){
    int hashIndex = hashFunction(key);
    NODE newNode= createNode(key,value);
    if(hashTable[hashIndex]==NULL)
        hashTable[hashIndex]=newNode;
    else{
        newNode->next=hashTable[hashIndex];
        hashTable[hashIndex]=newNode;
    }
}
char* search(int key){
    int hashIndex = hashFunction(key);
    NODE temp = hashTable[hashIndex];
    while(temp!=NULL){
        if(temp->key==key)
            return temp->value;
        temp=temp->next;
    }
    return NULL;
}
void delete(int key){
    int hashIndex = hashFunction(key);
    NODE temp = hashTable[hashIndex];
    NODE prev=NULL;
    while(temp!=NULL){
        if(temp->key==key){
            if(prev==NULL)
                hashTable[hashIndex]=temp->next;
            else    
                prev->next=temp->next;
            free(temp);
            printf("Key %d deleted successfully.\n",key);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Key %d not found!\n",key);

}
void display(){
    for(int i=0;i<SIZE;i++){
        printf("Bucket[%d]: ",i);
        NODE temp = hashTable[i];
        while(temp!=NULL){
            printf("(%d, %s) -> ",temp->key,temp->value);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
    for(int i=0;i<SIZE;i++){
        hashTable[i]=NULL;
    }
    insert(1,"Apple");
    insert(11,"Banana");
    insert(2,"Mango");
    insert(22,"Grapes");
    insert(5,"Orange");
    display();
    char* result = search(11);
        if(result!=NULL)
            printf("Found key 11: %s\n",result);
        else   
            printf("Key 11 not found.\n");
    delete(2);
    display();
    return 0;
}