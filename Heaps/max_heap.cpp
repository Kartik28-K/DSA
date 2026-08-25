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
class heap{
public:
    vector<int> arr;
    int size;
    heap(int n){
        arr.resize(n,-1);
        size=0;
    }

    void insert(int x){
        size++;
        int index = size;
        arr[index]=x;
        while(index>1)
        {   
            int parent=index/2;
            if(arr[parent] < x){
                swap(arr[parent],arr[index]);
                index=index/2;
            }
            else{
                return;
            }
            
        }
    }
    void del(){
        if(size==0){
            cout<<"UnderFlow"<<endl;
            return;
        }

        swap(arr[1],arr[size]);
        arr[size]=-1;
        size--;
        int i=1;
        while(i<size)
        {
           int left=2*i;
           int right=2*i+1;
           if(left < size and arr[left] > arr[i]){
                swap(arr[left],arr[i]);
                i=left;
           }
           else if(right < size and arr[right] > arr[i]){
                swap(arr[right],arr[i]);
                i=right;
           }
           else{
                return;
           }
        }
    }
    void print(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int top(){
        return arr[0];
    }
};
int main(){
    // heap using array
    // ith node : left Child -> 2*i , Right Child -> 2*i+1 
    // parent -> i/2 for both left and right
    heap h(50);
    h.insert(20);
    h.insert(21);
    h.insert(22);
    h.insert(23);
    h.print();
    h.del();
    h.print();
}