#include <stdio.h>
#include <omp.h>
int main(){
    int a,b,sum=0;
    printf("Enter value's for a and b: ");
    scanf("%d%d",&a,&b);
    #pragma omp parallel shared(a,b,sum)
    {
        #pragma omp single
        {
            #pragma omp task
            {
                sum=a+b;
            }
        }
    }
    printf("Sum of %d and %d is %d\n",a,b,sum);
return 0;
}