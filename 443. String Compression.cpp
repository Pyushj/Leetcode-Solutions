class Solution {
public:
    int compress(vector<char>& arr) {
        
        
        string str="";
        deque<char> stk;
        deque<int> res;
        int count=0;
        stk.push_back(arr[0]);
        count=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==stk.back())
                count++;
            else
            {
                res.push_back(count);
                count=1;
                stk.push_back(arr[i]);  
            }  
        }
        res.push_back(count);
        while(res.size()>0 && stk.size()>0)
        {
            str.push_back(stk.front());
            stk.pop_front();
            int sz=res.front();
            res.pop_front();
            if(sz!=1)
                str=str+to_string(sz);
        }
        arr.clear();
        for(int i=0;i<str.length();i++)
        {
            arr.push_back(str[i]);
        }
        return arr.size();
        
    }
};
