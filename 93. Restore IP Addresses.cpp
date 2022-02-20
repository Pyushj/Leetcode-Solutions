class Solution {
public:
    bool isValid(string str)
    {
        int n=stoi(str);
        if(n<0 || n>255)
            return false;
        if(n==0)
        {
            if(str.length()>1)
            return false;
        }
        else
        {
            int digits=log10(n)+1;
            if(digits!=str.length())
            return false;
        }
        return true;
    }
    void solve(string ques,string currAns,int dots,vector<string>& res)
    {
        if(dots>4)
            return;
        if(dots==4 && ques.length()==0)
        {
            currAns.pop_back();
            res.push_back(currAns);
            return;
        }
        int n=ques.length();
        for(int len=1;len<=min(3,n);len++)
        {
            string prefix=ques.substr(0,len);
            if(isValid(prefix))
            {
                string rest=ques.substr(len);
                solve(rest,currAns+prefix+".",dots+1,res);
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        solve(s,"",0,res);
        return res;
    }
};
