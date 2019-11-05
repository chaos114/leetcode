class Solution {
public:
    int scoreOfParentheses(string S) {
      int res = 0;
      int cur = 0;
      for(int i = 0;i < S.size();i++){
         if(S[i] == '('){
             if(S[i + 1] == ')'){
                 res += pow(2,cur);
                 i++;
             }
             else cur++;
         }
         else cur--;
      }
      return res;
    }
};