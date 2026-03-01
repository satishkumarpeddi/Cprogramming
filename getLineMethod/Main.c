#include <stdio.h>
#include <stdlib.h>
void main(){
    char* line=NULL;
    size_t len=0;
    ssize_t read;
    printf("Enter a line : ");
    read = getline(&line,&len,stdin);
    if(read!=-1){
        printf("The entered line : %s\n",line);
    }
    free(line);
}