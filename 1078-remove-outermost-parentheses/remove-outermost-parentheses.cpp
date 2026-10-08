class Solution {
public:
    string removeOuterParentheses(string s) {
        string t;
        int c = s.length();
        int idx=0;
        for(int i=0;i<c;i++){
           if(s[i]=='('){
            if(idx>0){
                t+=s[i];
            }
            idx++;
           }
           else{
             idx--;
            if(idx>0){
                t+=s[i];

            }
           
           }
        }
        return t;
    }
};