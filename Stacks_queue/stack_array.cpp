// stack using arrays
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
class stk{
public:
    int top;
    int size;
    vector<int> st ;
    stk(int size){
        this->size=size;
        top=-1;
        st.resize(size);
    }
    void push(int val){
        if(top >= size-1){
            cout<<"stack overflow"<<endl;
        }
        top=top+1;
        st[top]=val;
        return;
    }
    void pop(){
        if(top==-1){
            cout<<"stack under flow"<<endl;
            return;
        }
        top--;
        return;
    }
    int sizeOfStack(){
        return top+1;
    }
    int topOfStack (){
        if (top == -1){
            cout<<"empty stack";
            return 0;
        }
        else return st[top];
    }
    void print(){
        for (int i = top; i >= 0; i--)
        {
            cout<<st[i]<<" ";
        }
        cout<<endl;
        return;
    }
};
int main()
{
    stk st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.print();
    st.push(6);
    st.pop();
    st.pop();
    st.pop();
    st.print();

return 0;
}