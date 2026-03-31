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
class qu{
public:
    node* start;
    node* end;
    int size;
    qu(){
        start=end=NULL;
        size=0;
    }
    void push(int val){
        node* newnode = new node(val);
        if(end==NULL and start==NULL){
            start=end=newnode;
        }
        else{
            end->next = newnode;
            end=newnode;
        }
        size++;
        return;
    }
    void pop(){
        if(start==NULL and end==NULL){
            cout<<"underflow\n";
            return;
        }
        else if(start ->next == NULL){
            delete start;
            start=NULL;
            end=NULL;
            size--;
            return;
        }
        node* temp = start;
        start=start->next;
        delete temp;
        size--;
        return;
    }
    int topStk(){
        if(start==NULL){
            cout<<"empty stack\n";
            return -1;
        }
        else{
            return start->data;
        }
    }
    int sizeStk(){
        return size;
    }
    void print(){
        node* temp = start;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        return;
    }
};
int main()
{
    qu Que;
    Que.push(1);
    Que.push(2);
    Que.push(3);
    Que.push(4);
    Que.push(5);
    cout<<Que.sizeStk()<<endl;
    Que.print();
    Que.pop();
    Que.pop();
    cout<<Que.sizeStk()<<endl;
    Que.print();
return 0;
}