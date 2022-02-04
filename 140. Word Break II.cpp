class Solution {
public:
void wordBreakUtil(string ques,string currAns,unordered_set<string> st,vector<string>& res)
{
    if(ques.length()==0)
    {
        currAns.pop_back();
        res.push_back(currAns);
        return;
    }
    
    for(int i=1;i<=ques.length();i++)
    {
        string prefix=ques.substr(0,i);
        if(st.find(prefix)!=st.end())
        {
            string rest=ques.substr(i);
            wordBreakUtil(rest,currAns+prefix+" ",st,res);
        }
    }
    return;
}
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string> res;
        unordered_set<string> st;
        for(auto x: wordDict)
        {
            st.insert(x);
        }
        
        wordBreakUtil(s,"",st,res);
        return res;
        
    }
};
