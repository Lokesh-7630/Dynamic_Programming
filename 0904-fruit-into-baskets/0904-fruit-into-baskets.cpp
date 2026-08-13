class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int left=0,right=0;
       int maxLen=0;
       unordered_map<int,int>m;
       while(right<fruits.size()){
        
        //increment thr freq
        m[fruits[right]]++;

        if(m.size()>2){
            while(m.size()>2){
                m[fruits[left]]--;
                if(m[fruits[left]]==0) m.erase(fruits[left]);
                left++;
            }
        }
        maxLen=max(maxLen,right-left+1);
        right++;
       }
       return maxLen;
    }
};