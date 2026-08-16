class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>m;
        for(int i=0; i<3; i++){
            m[i]=-1;
        }
        int count=0;
        for(int i=0; i<s.size(); i++){
          m[s[i]-'a']=i;
          if(m[0]!=-1 && m[1]!=-1 && m[2]!=-1){
            count+=(1+min(min(m[0],m[1]),m[2]));
          }
        }  
        return count;      
    }
};