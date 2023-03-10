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
    
    //destructor
    ~node(){
        int value = this ->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout <<" memory is free for node with value "<< value << endl;
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

void insert_last(node* &tail ,node* &head, int value){
    //new node creation with value given
    node * temp = new node(value);
    //placing it at last position
    if(tail == NULL){
        tail = head = temp;
    }
    tail->next = temp;
    //making it the tail
    tail = temp;
    
    
    
}


void insert_index(node* &head , node* &tail ,int index , int value , int size){
    
    //create a node
    node*temp = new node(value);
    node*pointer = head;
    
    if(index <= 0 || index > size + 1 ){
        cout<<"invalid"<<endl;
        return;
    }
    else if (index == 1){
        insert_first(head, tail, value);
        return;
    }
    else if(index == size+1){
        insert_last(tail, head, value);
        return;
    }
    else{
        int count =1;
        while(count < index-1){
            pointer = pointer-> next;
            count ++;
        }
        temp ->next = pointer -> next ;
        pointer->next = temp;
        
    }
}

void remove_last(node* &head , node* &tail){
    
    if(head == tail && tail == NULL){
        cout<<" no element present";
        return;
    }
    else if(head==tail){
        delete head;
        head = tail = NULL;
        return;
    }
        
    else{
        node * temp = head;
        
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;}
    
    
}
node * reverse_(node* &head,node* &tail){
    node*prev=NULL;
    node*curr=head;
    node*forward = NULL;
    
    if(head == NULL){
        return head;
    }
    if (head->next == NULL){
        return head;
    }
    while(curr != NULL){
        forward=curr->next;
        curr->next = prev;
        prev = curr;
        curr=forward;
        }
    tail = head;
    head = prev;
    
    
    return head;
}
void k_fromlast(int k , node* &head ){
    
    node* fast = head;
    node* slow = head;
    
    if(head==NULL){
        cout<<"THE LIST IS EMPTY"<< endl;
        return;
    }
    
   for(int i =0;i<k;i++){
         fast = fast->next;}
    
    
   while(fast-> next != NULL ){
        fast = fast->next;
        slow = slow->next;
    }
    cout<< slow->data<< endl;
    return;
};
 
node* middle(node* &head){
    
    
    if(head == NULL || head->next == NULL)
        return head;
    
    node* fast = head->next;
    node* slow = head;
    
        while(fast -> next != NULL ){
            
            fast= fast->next;
            
            if(fast->next!= NULL){
                fast = fast ->next;
            }
            slow = slow->next;
            
        }
        return slow;
    
};

int length(node*head){
    
    int count=0;
    while(head != NULL){
        count++;
        head = head ->next;
    }
        
    
    return count;
}
 
void print(node* &head){
    //
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
    insert_last(tail,head, 9);
    insert_index(head, tail, 2 , 6, length(head));
    
    //reverse_(head, tail);
    //remove_last(head, tail);
    //k_fromlast(2, head );
    //printNthFromLast(head, 2);
    print(head);
    cout<<middle(head)->data<<endl;
    cout<<"head has the value "<<head->data<<endl;
    cout<<"tail has the value "<<tail->data<<endl;
    
    cout<<"the length is "<<length(head)<<endl;
    
    return 0;
   
}
