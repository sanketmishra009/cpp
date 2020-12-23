#include<iostream>
using namespace ::std;
const double x = 1.609;

double convert(double miles){
    return (miles*x);
}

int main(){
    int miles=1;
    while(miles!=0){
        cout<<"Enter a mile to convert or 0 to terminate: ";
        cin>>miles;
        cout<<"Distance in km is: "<<convert(miles)<<endl;
    }
    cout<<"\n";
}