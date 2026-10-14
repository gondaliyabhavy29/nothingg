class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)return "";
        string cur="";
         while(num>0){
            int di=min(9,sum);
            cur+=char('0'+di);
            sum-=di;
            num--;
         }
         return sum==0?cur:"";
    }
};