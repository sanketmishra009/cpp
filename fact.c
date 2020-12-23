#include<stdio.h>
long fact(int x){
    if(x==0||x==1){
        return 1;
    }
    else{
        return x* fact(x-1);
    }
}
int main(){
    for (int i=0;i<=40;i++){
        printf("The factorial of %d is %ld\n",i,fact(i));
    }
    return 0;
}