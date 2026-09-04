class Solution {
public:
    bool rotateString(string s, string goal) {
       for(int i=0; i<s.size(); i++){
        string roated=s.substr(i)+s.substr(0,i);
        if(roated==goal){
            return true;
        }
       }
       return false;
    }
};