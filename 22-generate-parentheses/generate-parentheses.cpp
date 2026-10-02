class Solution {
public:
void helper(int n,int op,int cl,string s,vector<string>&ans){
    if(s.size()==2*n){
        ans.push_back(s);
        return;
    }
    if(op<n){
        helper(n,op+1,cl,s+'(',ans); 
    }
    if(cl<op){
          helper(n,op,cl+1,s+')',ans); 
    
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(n,0,0,"",ans);
        return ans;
    }
};