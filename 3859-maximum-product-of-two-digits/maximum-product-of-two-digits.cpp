class Solution {
public:
   int ma(int n){
    int m1=0,m2=0;
    while(n){
        int di=n%10;
        if(di>=m1){
            m2=m1;
            m1=di;

        }
        else if(di>=m2){
            m2=di;
        }
        n/=10;
    }
    return m1*m2;
   }
    int maxProduct(int n) {
        return ma(n);
    }
};