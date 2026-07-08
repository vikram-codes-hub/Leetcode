class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // Ignore leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // Check sign
        bool isNegative = false;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                isNegative = true;
            i++;
        }

        // Ignore leading zeros
        while (i < n && s[i] == '0')
            i++;

        int ans = 0;

        // Read digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0';

            // Overflow check
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return isNegative ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return isNegative ? -ans : ans;
    }
};