class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        int start=0,i=0;
        int num=0;
      
      //removing leading spaces
        while(s[start]==' ')
            start++;
      
      //taking the sign
        if(s[start]=='+' || s[start]=='-')
        {
            sign=(s[start]=='-')?-1:1;
            start++;
        }
        i=start;
        string str="";
        while(s[i]>='0' && s[i]<='9')
        {
            str.push_back(s[i]);
            i++;
        }
        if(str.length()==0)
            return 0;
        for(int i=0;i<str.length();i++)
        {
            if(num >INT_MAX/10 || num== INT_MAX / 10 && str[i] - '0' > 7)
                return  (sign==1)?INT_MAX : INT_MIN;
            num=num*10 + (int)(str[i]-'0');
        }
        return (num*sign);
        
        
    }
};
