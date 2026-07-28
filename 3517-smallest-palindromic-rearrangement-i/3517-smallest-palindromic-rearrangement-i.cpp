class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
     string lefts=s.substr(0,n/2);
     sort(lefts.begin(),lefts.end());
     string rights=lefts;
     reverse(rights.begin(),rights.end());
     string mid="";
     if(n%2 != 0){
        mid=s[n/2];
     }
     return lefts+mid+rights;
    }
};