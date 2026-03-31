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
    node* left; // left pointer to left child
    node* right; // right pointer to right child
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
int main()
{
        //     1
        //    / \
        //   /   \
        //  2     3
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
return 0;
}