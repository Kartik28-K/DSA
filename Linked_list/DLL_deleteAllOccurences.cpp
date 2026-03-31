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
    node* prev;
    node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
node* convertArr2DLL(node* head,vector<int> &arr,node* &tail){
    node* temp=head;
    for (int i = 1; i < arr.size(); i++)
    {
        node* newnode=new node(arr[i]);
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
    }
    tail=temp;
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
void print_rev(node* tail){
    node* temp=tail;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<endl;
}
node* del_head(node* head){
    if (head== NULL or head->next == NULL) return NULL; // zero elemennt and one element
    node* temp= head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;
}
node* del_tail(node*head , node* &tail){
    if(head == NULL) return NULL;        // empty
    if(head == tail){                   // single node
        delete head;                    // zero element or one element
        return NULL;
    }
    node* temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete temp;
    return head;
}
node* del_kth(node* head,int k ){
    node* temp=head;
    if(head->next==NULL and head->prev==NULL) {
        delete temp ;
        return head;
    }
    else if(temp->prev==NULL){
        return del_head(head);
    }
    int count=0;
    while (temp!=NULL)
    {
        count++;
        if(k==count){
            temp->prev->next=temp->next;
            delete temp;
            break;
        }
        temp=temp->next;
    }
    return head;
}
node* insert_before_head(node* head , int val){
    node* temp=head;
    node* newnode= new node(val);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    return head;
}
node* insert_before_tail(node* head , node* &tail,int val){
    if(head->next==NULL){
        return insert_before_head(head,val);
    }
    node* newnode=new node(val);
    node*temp=tail->prev;
    tail->prev->next=newnode;
    tail->prev=newnode;
    newnode->next=tail;
    newnode->prev=temp;
    return head;
}
node* insert_before_kth(node* head , int val ,int k){
    if(k==1){
        return insert_before_head(head,val);
    }
    node* temp=head;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        if(count==k){
            break;
        }
        temp=temp->next;
    }
    node* newnode=new node(val);
    node* temp2=temp->prev;
    newnode->next=temp;
    newnode->prev=temp2;
    temp2->next=newnode;
    temp->prev=newnode;
    return head;
}
node* deleAllOccur(node* head , int num){
    node* temp=head;
    
    while (temp!=NULL)
    {
        node* nextnode=temp->next;
        if (temp->data==num)
        {
            if(head==temp){
                head=head->next;
                if (head != NULL) head->prev = NULL;
                delete temp;
                temp=head;
            }
            else{
                temp->prev->next=nextnode;
                if(nextnode!=NULL) nextnode->prev=temp->prev;
                delete temp;
                temp=nextnode;
                if(nextnode!=NULL) nextnode=nextnode->next;
            }
        }
        else{
            temp=temp->next;
        } 
    }
    return head;
}
int main()
{
    vector<int> arr={10,4,10,10,6,10};
    // delete all occurence of 10
    node* tail=NULL;
    node* head=new node(arr[0]);
    head=convertArr2DLL(head,arr,tail);
    print(head);
    head=deleAllOccur(head,10);
    print(head);
return 0;
}