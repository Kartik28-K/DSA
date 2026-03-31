#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
class linkedList{
public:
    node* head;
    node* tail;
    int size;
    linkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    node* push_front(int val){
        node* newnode= new node(val);
        if(size==0){
            head=newnode;
            tail=newnode;
        }
        else if (size!=0){
            newnode->next=head;
            head=newnode;
        }
        size++;
        return head;
    }
    node* push_back(int val){
        node* newnode= new node(val);
        if(size==0){
            head=newnode;
            tail=newnode;
        }
        else if(size!=0){
            tail->next=newnode;
            tail=newnode;
        }
        size++;
        return head;
    }
    node* pop_front(){
        head=head->next;
        size--;
        return head;
    }
    node* pop_back(){
        node* temp=head;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        tail=temp;
        tail->next=NULL;
        size--;
        return head;
    }
    void print(node* head){
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main()
{
    linkedList l1;
    node* head=NULL;
    head=l1.push_front(1);
    head=l1.push_front(2);
    head=l1.push_front(3);
    head=l1.push_front(4);
    l1.print(head);
    head=l1.pop_front();
    l1.print(head);
    head=l1.push_back(5);
    l1.print(head);
    head=l1.pop_front();
    l1.print(head);
    head=l1.pop_back();
    l1.print(head);


return 0;
}