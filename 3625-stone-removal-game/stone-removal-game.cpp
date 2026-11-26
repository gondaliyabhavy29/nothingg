class Solution {
public:
    bool canAliceWin(int n) {
        int k=10;
        int t=0;
        while(n>=k&&n!=0){
            n-=k;
            k--;
            t=!t;
        }
        if(t==0)return false;
        else return true;
    }
};