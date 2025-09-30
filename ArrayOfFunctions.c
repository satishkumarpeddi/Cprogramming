#include <stdio.h>
int add(int a,int b){
    return a+b;
}
int substract(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}
int divide(int a,int b){
    if(b!=0)
        return a/b;
    else{
        printf("Division by zero error\n");
        return 0;
    }
}
void main(){
    int (*operation[4])(int,int) = {add,substract,multiply,divide};
    int x,y,choice;
    printf("Enter values for x and y: ");
    scanf("%d %d",&x,&y);
    printf("Choose your operation:");
    printf("0:Add\n1:Substract\n2:Multiply\n3:Divide\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    if(choice>=0&&choice<4){
        int result = operation[choice](x,y);
        printf("Result = %d\n",result);
    }else{
        printf("Invalid choice\n");
    }
}