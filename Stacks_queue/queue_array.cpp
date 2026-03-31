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
class que{
public:
    int size;
    int start;
    int end;
    int curr_size;
    vector<int> qu;
    que(int size){
        this->size=size;
        curr_size=0;
        start=-1;
        end=-1;
        qu.resize(size);
    }
    void push(int val){
        if(curr_size==size){
            cout<<"overflow\n";
            return;
        }
        else if(curr_size == 0 ){
            start = 0;
            end = 0; 
        }
        else{
            end = (end+1) %size;
        }
        qu[end]=val;
        curr_size++;
    }
    void pop(){
        if(curr_size==0){
            cout<<"empty queue\n";
            return ; 
        }
        else if (curr_size ==1 ){
            start =-1;
            end=-1;
        }
        else{
            start=(start+1)%size;
        }
        curr_size--;
        return ; 
    }
    int top(){
        if(curr_size == 0) {
            cout<<"empty";
            return -2;
        }
        else{
            return qu[start];
        }
    }
    int sizeOfQueue(){
        return curr_size;
    }
};
int main()
{
    que qu(5);
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.pop();
    qu.pop();
    qu.pop();

return 0;
}