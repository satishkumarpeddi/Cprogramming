#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Bus{
    int address;
    int data;
    char controlSignal[10];
};
typedef struct Bus *BUS;
int memory[10];
void transferData(BUS bus){
    if(strcmp(bus->controlSignal,"WRITE")==0){
        memory[bus->address]=bus->data;
        printf("CPU -> Memory: Writing data %d at address %d\n",bus->data,bus->address);
    }else if(strcmp(bus->controlSignal,"READ")==0){
         printf("CPU -> Memory: Reading data %d at address %d\n",bus->data,bus->address);
    }else{
        printf("Invalid control signal.\n");
    }
}
void main(){
    BUS bus1;
    bus1->address=3;
    bus1->data=96;
    strcpy(bus1->controlSignal,"WRITE");
    transferData(bus1);

    strcpy(bus1->controlSignal,"READ");
    transferData(bus1);
}