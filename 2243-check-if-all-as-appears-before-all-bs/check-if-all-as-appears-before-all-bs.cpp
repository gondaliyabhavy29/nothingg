class Solution {
public:
    bool checkString(string s) {
        bool ok=false;
        for(auto c:s){
            if(c=='b')ok=true;
            else if(ok==true)return false;
        }
        return true;
    }
};