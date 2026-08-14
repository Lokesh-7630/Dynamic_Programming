class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0,right=0,maxLen=0;
        
        unordered_map<int,int>freq;
        freq.reserve(256);
    
        while(right<s.size()){
            freq[s[right]-'A']++;
           while(freq[s[right]-'A']>2){
           freq[s[left]-'A']--;
           left++;
           }
           maxLen=max(maxLen,right-left+1);
           right++;
        }
        return maxLen;
    }
};