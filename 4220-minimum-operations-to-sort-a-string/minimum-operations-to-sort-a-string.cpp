class Solution {
public:
    int minOperations(string s) {
        string t=s;
        string k=s;
        int n=k.size();
        sort(t.begin(),t.end());
        if(k==t)return 0;
        else if(n<3 && k!=t)return -1;
        else if(k[0]==t[0]||k[n-1]==t[n-1])return 1;
        else if(k[0]==t[n-1] && k[n-1]==t[0]){
            sort(k.begin(),k.end()-1);
            if(k[0]==t[0])return 2;
            sort(s.begin()+1,s.end());
            if(s[n-1]==t[n-1])return 2;
            return 3;
        } 
        else return 2;
    }
};