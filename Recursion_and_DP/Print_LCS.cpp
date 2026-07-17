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
#include <string>
using namespace std;
void longestCommonSubsequence(string text1, string text2 , int m , int n , vector<vector<int>> &dp) {
    for(int i=1; i<m+1 ; i++){
        for(int j=1 ; j<n+1 ; j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=0+max( dp[i][j-1] , dp[i-1][j]);
        }
    }
}
int main() {
    // print the LCS
    string str1="abcde";
    string str2="bdgek";
    int m=str1.size();
    int n=str2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    longestCommonSubsequence(str1,str2,m,n,dp);
    int i=m;
    int j=n;
    string ans="";
    while(i>=0 and j>=0){
        if(str1[i-1]==str2[j-1]){
            ans+=str1[i-1]; // when mathced store the answer
            i--;j--;  // and move to diagonal
        }
        else if(dp[i-1][j] > dp[i][j-1]){ // else move to max of up and down
            i--;
        }
        else{
            j--;
        }
    }
    for(int k=0 ; k<ans.size() ; k++) cout<<ans[k];
    return 0;
}
