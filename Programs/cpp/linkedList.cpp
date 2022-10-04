
#include<iostream>
using namespace std;
        
class Node{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class LinkedList{
public:
    Node *head;
    LinkedList(){
        head=NULL;
    }
    void insert(int d){
        Node *newNode=new Node(d);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void print(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl; 
    }
    
};
int main(){
    LinkedList l;
    l.insert(5);
    l.insert(4);
    l.insert(3);
    l.insert(2);
    l.insert(1);
    l.print();

}

