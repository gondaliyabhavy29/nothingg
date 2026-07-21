class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int pz = 0, cz = 0;
        int to = 0;
        int best = 0;
        int i = 0;

        while(i<n){
            if(s[i]=='0'){
                pz++;
                i++;
            }else{
                while(i<n&&s[i]=='1'){
                    to++;
                    i++;
                }

                while(i<n&&s[i]=='0'){
                    cz++;
                    i++;
                }

                if(pz&&cz)
                    best = max(best,pz+cz);

                pz = cz;
                cz = 0;
            }
        }

        return to+best;
    }
};