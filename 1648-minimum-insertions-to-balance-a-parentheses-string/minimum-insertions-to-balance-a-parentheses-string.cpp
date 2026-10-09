class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int o=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                o+=2;
                if(o&1==1){
                    c++;
                   o--;
                  } 
                }
                else{
                    o--;
                    if(o<0){
                        c++;
                        o+=2;
                    }
                }
            
        }
        return o+c;
    }
};