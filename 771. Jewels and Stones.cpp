class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_map<char,int> mp;
        for(auto x: stones)
        {
            mp[x]++;
        }
        for(int i=0;i<jewels.size();i++)
        {
            if(mp.find(jewels[i])!=mp.end())
                count+=mp[jewels[i]];
        }
        return count;
    }
};
