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
node* rev(node* head){
    node* temp = head;
    node* prev = NULL;
    while (temp!=NULL)
    {
        node* nextnode = temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextnode;
    }
    return prev;
}
node* add_one(node* head){
    node* temp = head;
    node* new_head = rev(temp);
    node* temp2 = new_head;
    int carry = 1;
    while (carry!=0 and temp2!=NULL)
    {
        int ans = temp2->data + carry;
        if(ans < 10){
            temp2->data = ans;
            carry=0;
        }
        else{
            int div = int(floor(ans/10.0));
            int quo = ans%10;
            temp2->data = quo;
            if( carry!=0 and temp2->next == NULL){
                node* newnode = new node(div);
                temp2->next = newnode;
                break;
            }
            carry = div;
        }
        temp2=temp2->next;
    }
    node* final_head = rev(new_head);
    return final_head;
}
int add_one_m2(node* head ){
    if(head==NULL){
        return 1;
    }
    int ans = head->data + add_one_m2( head->next);
    if(ans < 10){
        head->data = ans ;
        return 0 ;
    }
    else{
        head->data = 0;
        return 1;
    }
}
int main()
{
    vector<int> arr={9,9,9};
    node* head=convertArr2LL(arr);
    print(head);
    int carry = add_one_m2(head);
    if(carry == 1){
        node* newnode = new node(carry);
        newnode->next = head;
        head =newnode;
    }
    print(head);

return 0;
}