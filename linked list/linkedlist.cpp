#include<iostream>
#include<vector>
using namespace std;
class node{
 public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }

};
class list{
    node* head;
    node* tail;
public:
        list(){
       head=tail=NULL;
        }
   void pushfront(int val){
        node* newnode= new node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        
        }

    }
    void printll(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;

        }
        cout<<"NULL\n";
    }
    void pushback(int val){
        node* newnode=new node(val);
        if(tail==NULL){
            tail=head=newnode;            
        }
        else{
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
    }
    int popback(){
        if(tail==NULL){
            cout<<"empty list\n";
            return -1;
        }
        else if(head==tail){
            int val=tail->data;
            node* temp=tail;
            tail=head=NULL;
            delete temp;
            return val;
        }
        else{
            node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            
            return temp->data;
            
        }

    }
};
int main(){
    list adi;
    adi.pushfront(5);
    adi.printll();    
    cout<<adi.popback()<<"\n";
    adi.printll();
    adi.pushfront(7);
    adi.pushfront(6);
    adi.pushback(2);
    adi.pushback(90);
    adi.pushback(20);
    adi.printll();
    int a=adi.popback();
    cout<<a<<"\n";
    adi.printll();

    return 0;
}
