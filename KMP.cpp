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
vector<int> lpsfind(string s){
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
  string needle;// string which has to be matched 
  string haystack; // string with whom needle must be matched
  vector<int> lps = lpsfind(needle);
  int first = 0;
  int second = 0;
  while (first < haystack.size() and second < needle.size() ) {
      if (haystack[first] == needle[second]) {
          first++;
          second++;
      } else {
          if (second == 0) {
              first++;
          } else {
              second = lps[second - 1];
          }
      }
  }
  if(second==needle.size()) return first-second;
  else return -1;
  
}
