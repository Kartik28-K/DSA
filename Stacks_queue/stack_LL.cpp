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
class st{
public:
    node* top;
    int size;
    st(){
        top=NULL;
        size=0;
    }
    void push(int val){
        node* newnode = new node(val);
        newnode->next = top;
        top = newnode;
        size++;
        return;
    }
    void pop(){
        if(top==NULL){
            cout<<"underflow\n";
            return;
        }
        node* temp = top;
        top=top->next;
        delete temp;
        size--;
        return;
    }
    int topStk(){
        if(top==NULL){
            cout<<"empty stack\n";
            return -1;
        }
        else{
            return top->data;
        }
    }
    int sizeStk(){
        return size;
    }
    void print(){
        node* temp = top;
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
    st stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    cout<<stk.sizeStk()<<endl;
    stk.print();
    stk.pop();
    stk.pop();
    cout<<stk.sizeStk()<<endl;
    stk.print();
return 0;
}