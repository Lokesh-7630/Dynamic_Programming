class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int maxLen=0;
        unordered_map<int,int>m;
        m.reserve(256);
        for (int i = 0; i < 256; ++i) {
       m[i] = -1;
        }
        
        while(right<s.size()){
           
            //exist in map
            if(m[s[right]]!=-1){
                if(m[s[right]]>=left){
               
                left=m[s[right]]+1;
                }
                
            }
                int len=right-left+1;
                maxLen=max(len,maxLen);
                m[s[right]]=right;
                right++;
        

        }
        return maxLen;

    }
};