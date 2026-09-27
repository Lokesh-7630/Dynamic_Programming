class Solution {
public:
    string reverseParentheses(string s) {
        unordered_map<int,int>m;
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                int j=st.top();
                st.pop();
                m[i]=j;
                m[j]=i;
            }
        }
        int dir=1;
        string res="";
        for(int i=0; i<s.size(); i+=dir){
            if(s[i]=='(' || s[i]==')'){
             i=m[i];
             dir=-dir;
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};