#include<iostream>
using namespace std;
class stack{
    int *arr;
    int top;
    int capacity;
public:
        stack(int cap){
        capacity=cap;
        arr=new int[capacity];
        top=-1;
    }
    void push(int d){
        if(top==capacity-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=d;
    }
    int pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int d=arr[top];
        top--;
        return d;
    }
    int peek(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        if(top==-1)return true;
        return false;
    }
    bool isFull(){
        if(top==capacity-1)return true;
        return false;
    }
};
int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}
