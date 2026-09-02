class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string result="";
        for(char ch:s){
            if(ch=='('){
                if(count>0) result+='(';
                count++;
            }
            else if(ch==')'){
                count--;
                
                if(count>0) result+=')';
                
            }
        }
        return result;
    }
};