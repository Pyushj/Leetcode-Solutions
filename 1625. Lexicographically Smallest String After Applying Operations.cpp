class Solution {
public:
    string rotate(string str,int k)
    {
        int n=str.length();
        if(k==n)
            return str;
        string suffix=str.substr(0,n-k);
        string prefix=str.substr(n-k);
        return (prefix+suffix);
    }
    string add(string str,int a)
    {
        string s;
        for(int i=0;i<str.length();i++)
        {
            if(i&1)
            {
                int x=str[i]-'0';
                int sum=(x+a)%10;
                s.push_back( (char)(sum+'0') );
            }
            else
                s.push_back(str[i]);
        }
        return s;
        
    }
    string findLexSmallestString(string s, int a, int b) {
        set<string> st;
        st.insert(s);
        queue<string> q;
        q.push(s);
        
        while(!q.empty())
        {
                string temp=q.front();
                q.pop();
                string r=rotate(temp,b);
                string addi=add(temp,a);
                if(st.find(r)==st.end())
                {
                    q.push(r);
                    st.insert(r);
                }
                if(st.find(addi)==st.end())
                {
                    q.push(addi);
                    st.insert(addi);
                }
        }
        string res=*st.begin();
        return res;
        
    }
};
