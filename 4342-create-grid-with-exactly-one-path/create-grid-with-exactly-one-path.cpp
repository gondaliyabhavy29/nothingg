class Solution {
public:
    vector<string> createGrid(int m, int n) {
         vector<string>a(m,"");
       for(int i=0;i<n;i++){
            a[0]+='.';
        }
        for(int i=1;i<m;i++){
           for(int j=0;j<n;j++){
                
                if(j==n-1){
                    a[i]+='.';
                }
                else{
                    a[i]+='#';
                }
            }
        }
        return a;
    }
};