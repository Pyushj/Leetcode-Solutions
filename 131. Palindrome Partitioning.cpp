class Solution {
public:
    bool isPalindrome(string str)
    {
        int start=0,end=str.length()-1;
        while(start<=end)
        {
            if(str[start]!=str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void palin(string ques,vector<string>& currAns,vector<vector<string>>& res)
    {
        if(ques.length()==0)
        {
            res.push_back(currAns);
            return;
        }
        for(int i=1;i<=ques.length();i++)
        {
            string prefix=ques.substr(0,i);
            if(isPalindrome(prefix))
            {
                string rest=ques.substr(i);
                currAns.push_back(prefix);
                palin(rest,currAns,res);
                currAns.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currAns;
        palin(s,currAns,res);
        return res;
    }
};
