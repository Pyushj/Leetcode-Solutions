class Solution {
public:
    vector<string> res;
    char changeCase(char ch)
    {
        char naya;
        if(ch>='a' && ch<='z')
            naya=(char)(ch-32);
        else
            naya=(char)(ch+32);
        return naya;
    }
    void permute(string  str,string currAns)
    {
        if(str.length()==0)
        {
            res.push_back(currAns);
            return;
        }
        char ch=str[0];
        string rest=str.substr(1);
        if(ch>='0' && ch<='9')
            permute(rest,currAns+ch);
        else
        {
            char newCase=changeCase(ch);
            permute(rest,currAns+ch);
            permute(rest,currAns+newCase);
        }
    }
    vector<string> letterCasePermutation(string s) {
        permute(s,"");
        return res;
        
    }
};
