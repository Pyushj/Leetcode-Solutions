class Solution {
public:
    void subset(int pos,int n,string curr,string& res,unordered_set<string>& st)
    {
        if(pos>n)
        {
            if(st.find(curr)==st.end())
                res=curr;
            return;
        }
        subset(pos+1,n,curr+"1",res,st);
        subset(pos+1,n,curr+"0",res,st);
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string > st;
        int n=nums.size();
        for(auto x: nums)
        {
            st.insert(x);
        }
        string res="";
        subset(1,n,"",res,st);
        return res;
        
    }
};
------------------------*******************************---------------------------------
