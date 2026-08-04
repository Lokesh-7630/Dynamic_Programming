class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int>s(nums.begin(), nums.end());
        vector<int>ans;
        int first=*s.begin();
        int last=*s.rbegin();
        for(int i=first; i<=last; i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};