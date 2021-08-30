class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int len=0,odd=0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second %2==0)
                len+=x.second;
            else
            {
                len+=(x.second-1); //adding only even part of odd frequrncy
                odd++;
            }
        }
      //if no odd frequency is found no need to increase the length
        if(odd>0)
            len++;
        return len;
        
    }
};
