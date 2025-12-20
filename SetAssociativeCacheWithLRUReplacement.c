#include <stdio.h>
#include <stdlib.h>
#define CACHE_LINES 8
#define WAYS 2
#define SETS (CACHE_LINES/WAYS)
#define INVALID -1
 struct cacheLine{
    int valid;
    int tag;
    int lastUsed;
};
typedef struct cacheLine *CACHELINE;
struct cacheSet{
    CACHELINE lines[WAYS];
};
typedef struct cacheSet *CACHESET;
//Global Cache
CACHESET cache[SETS];