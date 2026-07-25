#include<bits/stdc++.h>
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int le=0;
        int t=n-k;
        int sum=0,ss=0,s=INT_MAX;
        for(int ri=0;ri<n;ri++){
             sum+=card[ri];
            ss+=card[ri];
          if((ri-le+1)==t){
             s = min(s,ss);
            ss-=card[le];
            le++;
          }
         
        }
        if(k==n)return sum;
        return sum-s;
    }
};