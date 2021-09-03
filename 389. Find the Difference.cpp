class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26]={};
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            freq[t[i]-'a']--;
            if(freq[t[i]-'a']==-1)
                return t[i];
        }
        return 'z';
    }
};
