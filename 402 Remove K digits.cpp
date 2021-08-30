/*
we start iterating from the begining and check for dips int the number series if any dip occurs simply remove the digit
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        //obviously
        if(k>=num.length())
            return "0";
        //create  a deque to hold characters
        deque<char>dec;
        for(int i=0;i<num.length();i++)
        {
            //as long as the previous digit is larger then the current digit remove it ,do check for the condition of k for poping
            while(dec.size()>0 && ( dec.back()>num[i] && k>0))
            {
                dec.pop_back();
                k--;
            }
            dec.push_back(num[i]);
        }
        //if k is still not 0 we need to remove the last k characters
        while(k>0)
        {
            dec.pop_back();
            k--;
        }
        //remove leading 0's if any
        while(dec.size()>0 && dec.front()=='0')
        {
            dec.pop_front();
        }
        // add to the result
        while(dec.size()>0)
        {
            res.push_back(dec.front());
            dec.pop_front();
        }
        //if result is empty simply return 0
        return (res.size()>0)?res:"0";
        
    }
};
