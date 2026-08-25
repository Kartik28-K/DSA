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
void heapify(vector<int> &arr,int n , int i){
    int node=i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n and arr[left] > arr[node]){
        node= left;
    }
    else if(right <= n and arr[right] > arr[node]){
        node= right;
        // if after that again we have to go deeper to place it
    }
    if(node != i){
        // means change hua hai
        swap(arr[node],arr[i]);
        heapify(arr,n,node);
    }
}
int main(){
    vector<int> arr={-1,54,53,55,52,50};
    int n=5;
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr,n,i);
    }

    for (int i = 1; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
}