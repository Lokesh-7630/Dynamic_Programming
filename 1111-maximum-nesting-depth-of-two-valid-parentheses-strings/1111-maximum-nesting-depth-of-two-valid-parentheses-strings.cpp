class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>answer;
        answer.reserve(seq.length());
        
        int current_depth = 0;
        
        for (char c : seq) {
            if (c == '(') {
                current_depth++;
                answer.push_back(current_depth % 2);
            } else { // c == ')'
                answer.push_back(current_depth % 2);
                current_depth--;
            }
        }
        
        return answer;
    }
};