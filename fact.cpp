#include<iostream>
using namespace :: std;

long long fact(int x){
    if (x==1 || x==0){
        return 1;
    }
    else{
        return x* fact(x-1);
    }
}

int main(){
    for(int i=0;i<=40;i++){
        cout<<"The factorial of "<<i<<" is "<<fact(i)<<"\n";
    }
}