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
vector<int> lps(string s){
  vector<int> lp(s.size(),0);
  int pre=0;
  int suff=1;
  while(suff<s.size()){
    if(s[pre]==s[suff]){
      lp[suff]=pre+1;
      pre++;
      suff++;
    }
    else{
      if(pre==0){
        lp[suff]=0;
        suff++;
      }
      else{
        pre=lp[pre-1];
      }
    }
  }
      return lp;
}

int main(){
  string s;
  vector<int> ans=lps(s);
  return ans[as.size()-1]
}
