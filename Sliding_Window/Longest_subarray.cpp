#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    // longest subarray with some condtition
    vector<int> arr = {2,5,1,7,10}; // length of subarray sum <= k (14)
    int k=14;
    int n=arr.size();
    int i=0;
    int j=0;
    int sum=0;
    int length=0;
    while(j<n){
        sum = sum+arr[j];
        
        while(sum > k){
            sum=sum-arr[i];
            i++;
        }
        
        if(sum <= k ) length = max(length,j-i+1);
        // this statement is after while loop because we have to again check 
        // if the condition is true for new subarray
        j++;
    }
    // TC: O(n) SC: O(1)
    cout<<length<<endl;
    return 0;
}