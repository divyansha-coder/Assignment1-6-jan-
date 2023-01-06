//
//  main.cpp
//  Assignment1(a)= Add node at first position
//
//  Created by Divyansha Arora on 06/01/23.
//

#include <iostream>
using namespace std;

// creating a class node
class node{
    public :
    int data;
    node * next;
    
    //constructor
    node(int data){
        this->data=  data;
        this->next= NULL;
    }
    
};
// function to add first in linked list
void insert_first(node* &head ,node* &tail ,int value){
    //new node creation with value given
    node * temp = new node(value);
    //placing it at first/head position
    temp->next = head;
    //making it the head
    head = temp;
    if(head -> next == NULL){
        tail = temp;
    }
    
}
 
void print(node* &head){
    //not using head because we don't want the head to actually iterate
    node* temp = head;
    if(temp == NULL)
        cout<<"The list is empty";
   
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
    cout<<endl;
};

int main() {
    //initially both head and tail are null
    node*head=NULL;
    node*tail=NULL;
    //new node created
    node * node1 = new node(2);
    //updating the head and tail of node
    head = tail = node1;
    insert_first(head,tail , 1);
    print(head);
    
    return 0;
   
}
