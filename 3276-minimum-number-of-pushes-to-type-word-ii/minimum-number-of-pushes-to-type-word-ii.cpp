class Solution {
public:
    int minimumPushes(string word) {
        vector<int>cc(26,0);

        for(char ch:word){
            cc[ch-'a']++;
        }

        sort(cc.begin(),cc.end(),greater<int>());

        int mp=0;

        for(int i=0;i<26;i++){
            mp += cc[i]*(i/8+1);
        }

        return mp;
    }
};