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
int prior(char s){
    if(s=='^') return 3;
    else if(s=='*' or s=='/') return 2;
    else if(s=='+' or s=='-') return 1;
    else return -1;
}
int main()
{
    string s = "a+b*(c^d-c)";
    int i=0;
    string ans="";
    stack<char> st;
    int n = s.size();
    while (i<n)
    {
        if((s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9')){
            ans = ans+s[i]; // if i is operator
        }
        else if(s[i]=='('){
            st.push(s[i]); // if i is opening bracket
        }
        else if (s[i]==')'){
            // pop and add it to ans till we get opening bracket
            while (!st.empty() and st.top()!='(') // stack khali na ho
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            // operator
            while (!st.empty() and prior(s[i])<=prior(st.top()) and s[i] != '^') // ye last waali ko analyse krna hai
            {
                ans += st.top();
                st.pop();   
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i];
    }
return 0;
}