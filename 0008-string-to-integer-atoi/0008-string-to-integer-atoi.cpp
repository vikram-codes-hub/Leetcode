class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        bool neg=false;


        while(i<n && s[i]==' ')i++;


        if(i!=n && (s[i]=='-' || s[i]=='+')){
            neg=(s[i]=='-');
            i++;
        }
       long long ans = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

         
            if (!neg && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)))
                return INT_MAX;

            if (neg && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 8)))
                return INT_MIN;

            ans = ans * 10 + digit;
            i++;
        }

        return neg ? -ans : ans;
    }
};