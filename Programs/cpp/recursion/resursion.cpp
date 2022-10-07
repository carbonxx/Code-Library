// short recursion programs
#include<iostream>
using namespace std;
int fib(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return fib(n-1)+fib(n-2);
}
int addNum(int n){
    if(n==0)return 0;
    return n+addNum(n-1);
}
int permutation(int n){
    if(n==0)return 0;
    return n+permutation(n-1);
}
int power(int n){
    if(n==0)return 1;
    return n*power(n-1);
}
int factorial(int n){
    if(n==0)return 1;
    return n*factorial(n-1);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cout<<fib(i)<<" ";cout<<endl;
    for(int i=0;i<n;i++)cout<<addNum(i)<<" ";cout<<endl;
    for(int i=0;i<n;i++)cout<<permutation(i)<<" ";cout<<endl;
    for(int i=0;i<n;i++)cout<<factorial(i)<<" ";cout<<endl;
        cout<<power(n)<<" ";cout<<endl;
}