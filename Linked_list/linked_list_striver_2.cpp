// Convert array to linked list
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
    node(int data,node* next1){
        this->data=data;
        this->next=next1;
    }
    node(int data){
        this->data=data;
        next=NULL;
    }
};
node* convertArr2LL(vector<int> arr){
    node* head=new node(arr[0]);
    node* mover=head;
    for (int i = 1; i < arr.size(); i++)
    {
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
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
int size(node* head){
    node* temp=head;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
bool search(node* head,int val){
    node* temp=head;
    while (temp!=NULL)
    {
        if(val==temp->data) return true;
        temp=temp->next;
    }
    return false;
}
node* remove_head(node* head){
    if(head==NULL) return NULL;
    node* temp = head;
    head=head->next;
    delete temp;
    return head;
}
node* remove_tail(node* head){
    if(head==NULL or head->next==NULL) return NULL;  // zero element and one element linked list
    node*temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
node* delete_kth(node* head , int k){
    node* temp=head;
    node* prev=NULL;
    if(head==NULL) return NULL;
    if(k==1){
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    while (temp!=NULL )
    {
        count++;
        if(k==count){
            prev->next=temp->next;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    return head;
}
node* insert_head(node* head,int val){
    node* newnode=new node(val);
    newnode->next=head->next;
    head=newnode;
    return head;
}
node* insert_tail(node* head , int val){
    node* temp=head;
    node* newnode=new node(val);
    if(head==NULL) return newnode;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    return head;
}
node* insertKth(node* head , int k ,int val){
    node* temp=head;
    node* newnode=new node(val);
    int count=0;
    while (temp!=NULL)
    {
        count++;
        if(k-1==count){
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr={12,5,8,7};
    node* head=convertArr2LL(arr);
    // print(head);
    // head=remove_head(head);
    // print(head);
    // head=remove_tail(head);
    // print(head);
    // head=delete_kth(head,2);
    // print(head);
    // head=insert_head(head,20);
    // print(head);
    // head=insert_tail(head,500);
    // print(head);
    head=insertKth(head,2,500);
    print(head);

return 0;
}