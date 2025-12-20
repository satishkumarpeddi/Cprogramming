#include <stdio.h>
#include <pthread.h>
void* printMethod(void* args){
    char* message = (char*)args;
    printf("%s\n",message);
    return NULL;
}
void main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,printMethod,"Hello By Thread1");
    pthread_create(&t2,NULL,printMethod,"Hello By Thread2");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Both thread's have finished\n");
}