class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string,string> map; 

        for(auto know : knowledge){
            map[know[0]] = know[1];
        }

        string ans = "";
        string word = ""; 
        bool flag = false; 
        
        for(int i = 0; i<n; i++){
            if(s[i] == '('){ 
                flag = true;
                continue;
            }
            else if(s[i] == ')'){ 
                if(map[word] != ""){ 
                    ans += map[word];
                }
                else ans.push_back('?');

                flag = false;
                word = "";
                continue;
            }

            if(flag) word.push_back(s[i]);
            if(!flag) ans.push_back(s[i]); 
        }

        return ans;
    }
};