class Solution {
public:
    bool checkString(string s) {
        int valid=1;
        for(char ch: s){
            if(ch=='b'){
                valid=0;
            
            }
             else if(valid==0){
             return false;
            }
            
            }
                   
             return true;
    }
};