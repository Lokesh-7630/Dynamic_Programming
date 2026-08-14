class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,maxLen=0;
        unordered_map<int,int>freq;
        freq.reserve(256);
        int maxFreq=0;
        while(right<s.size()){
        freq[s[right]-'A']++;
         maxFreq=max(maxFreq,freq[s[right]-'A']);
         while((right-left+1)-maxFreq>k){
        
        freq[s[left]-'A']--;
        maxFreq=0;
        for(int i=0; i<=25; i++){
        maxFreq=max(maxFreq,freq[i]);
        }
        left++;
         }
         if((right-left+1)-maxFreq<=k){
            maxLen=max(maxLen,right-left+1);
         }
         right++;
        }
       return maxLen;
    }
};