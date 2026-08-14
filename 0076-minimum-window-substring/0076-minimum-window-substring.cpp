class Solution {
public:
    string minWindow(string s, string t) {
        int sIdx=-1;
        int minLen=INT_MAX;
        int left=0,right=0;
        unordered_map<int,int>freq;
        freq.reserve(256);
        int count=0;
        for(int i=0; i<t.size(); i++){
            freq[t[i]-'A']++;
        }
        while(right<s.size()){
          if(freq[s[right]-'A']>0){
            count++;
          }
            freq[s[right]-'A']--;
          
          while(count==t.size()){
            if(right-left+1<minLen){
                minLen=right-left+1;
                sIdx=left;
            }
            
            freq[s[left]-'A']++;
            if(freq[s[left]-'A']>0) count--;

            
            left++;
            

          }
          right++;
        }
        return sIdx==-1 ? "" : s.substr(sIdx,minLen);

    }
};