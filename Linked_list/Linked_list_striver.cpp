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
int main()
{
    vector<int> arr={12,5,8,7};
    node* head=convertArr2LL(arr);
    print(head);
    cout<<size(head)<<endl;
    cout<<search(head,5)<<endl;
    cout<<search(head,25)<<endl;
return 0;
}