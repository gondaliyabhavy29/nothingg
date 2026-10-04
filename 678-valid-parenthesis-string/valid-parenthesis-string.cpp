class Solution {
public:
    bool checkValidString(string t) {
       stack<int>f,s;
       for(int i=0;i<t.size();i++){
        char c=t[i];
        if(c=='('){
            f.push(i);
        }
        else if(c=='*'){
            s.push(i);
        }
        else{
            if(f.empty()&&s.empty()){
                return false;
            }
            else if(f.size()){
               f.pop();
            }
            else{
            s.pop();
        }
       }
       }
       while(!f.empty()&&!s.empty()){
          if(f.top()>s.top()){
            return false;
          }
          f.pop(),s.pop();
       }
        return f.empty();
    }
};