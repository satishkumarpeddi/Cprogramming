#include <stdio.h>
#include <stdlib.h>
#define CACHE_LINES 8
#define MEMORY_BLOCKS 32
struct cacheLine{
    int valid;
    int tag;
    int data;
};
int main(){
    struct cacheLine cache[CACHE_LINES];
    int memoryAccesses[] = {0,5,8,0,12,25,8,16,5,25};
    int numAccesses = sizeof(memoryAccesses)/sizeof(memoryAccesses[0]);
    for(int i=0;i<CACHE_LINES;i++){
        cache[i].valid=0;
        cache[i].tag=-1;
        cache[i].data=-1;
    }
    printf("Direct Mapping Cache Simulation\n");
    printf("Cache Lines: %d\n",CACHE_LINES);
    printf("Memory Blocks: %d\n",MEMORY_BLOCKS);
    printf("-----------------------------\n");
    for(int i=0;i<numAccesses;i++){
        int blockAddress = memoryAccesses[i];
        int lineNumber = blockAddress%CACHE_LINES;
        int tag= blockAddress/CACHE_LINES;
        printf("Accessing Memory Block: %2d -> Cache Line: %d | Tag: %d\n",blockAddress,lineNumber,tag);
        if(cache[lineNumber].valid&&cache[lineNumber].tag==tag){
            printf("Cache Hit! (Line %d contians Block %d)\n",lineNumber,blockAddress);
        }else{
            printf("Cache Miss! Loading block %d into Line %d\n",blockAddress,lineNumber);
            cache[lineNumber].valid = 1;
            cache[lineNumber].tag=tag;
            cache[lineNumber].data=blockAddress;
        }
        printf("------------------------------------------\n");
    }
    printf("|Final Cache State:\n");
    printf("Line\tValid\tTag\tData\n");
    for(int i=0;i<CACHE_LINES;i++){
        printf("%d\t%d\t%d\n",i,cache[i].valid,cache[i].tag,cache[i].data);
    }
}