class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string check="123456789";
        int n=check.length();
        for(int i=0;i<n;i++)
        {
            for(int len=2;len<=n-i;len++)
            {
                string str=check.substr(i,len);
                int x=stoi(str);
                if(x>=low && x<=high)
                    res.push_back(x);
            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};
