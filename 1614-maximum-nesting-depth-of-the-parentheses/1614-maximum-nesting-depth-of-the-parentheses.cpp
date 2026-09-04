class Solution {
public:
    int maxDepth(string s) {
        int counter=0;
        int ans=INT_MIN;
        for(char ch:s){
            if(ch=='('){
                counter++;
            }else if(ch==')'){
                counter--;
            }
            ans=max(ans,counter);
        }
        return ans;
    }
};