class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        int prev=INT_MAX;
        int n=s.length();
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                res.push_back(0);
                prev=i;
            }
            else
            res.push_back(abs(prev-i));
        }
        int next=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==c)
            {
              next=i;
            res[i]=0;
            }
            else
            res[i]=min(res[i],abs(next-i));
        }
        return res;
    }
};
