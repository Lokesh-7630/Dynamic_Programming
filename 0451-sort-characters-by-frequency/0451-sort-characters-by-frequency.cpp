class Solution {
    private:   
    static bool comparator(pair<int,char>p1,pair<int,char>p2){
            if(p1.first<p2.first) return false;
            if(p1.first>p2.first) return true;
            return p1.second<p2.second;
        }
public:
    string frequencySort(string s) {
      
     vector<pair<int,char>>freq(256);
     for(int i=0; i<256; i++){
       freq[i] = {0, (char)i};
     }
     for(char ch:s){
        freq[(unsigned char)ch].first++;
     }
     sort(freq.begin(),freq.end(),comparator);
     string ans="";
     for(int i=0; i<256; i++){
        if(freq[i].first>0) ans.append(freq[i].first, freq[i].second);
     }
     return ans;
    }
};