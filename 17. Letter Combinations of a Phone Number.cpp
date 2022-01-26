class Solution {
public:
    string hash[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     vector<string> letterCombinationsUtil(string digits) {
        
        if(digits.size()==0)
        {
            vector<string> x;
            x.push_back("");
            return x;
        }
        
        char ch=digits[0];
        int idx=(int)(ch-'0');
        string str=digits.substr(1);
        vector<string> small=letterCombinationsUtil(str);
        vector<string> res;
        for(int i=0;i<hash[idx].size();i++)
        {
            for(auto x:small)
            {
                res.push_back(hash[idx][i]+x);
            }
        }
        return res;
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0)
        {
            return {};
        }
        
        return letterCombinationsUtil(digits);
    }
};
