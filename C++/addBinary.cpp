/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
            swap(a, b);
        b.insert(b.begin(), a.length() - b.length(), '0');
        string sum(a.length(), '0');
        int pos = a.length();
        int carry = 0;
        while (pos--) {
            int bitsum = (a[pos] - '0') + (b[pos] - '0') + carry;
            if (bitsum >= 2) {
                sum[pos] = char(bitsum - 2 + '0');
                carry = 1;
            }
            else {
                sum[pos] = char(bitsum + '0');;
                carry = 0;
            }
        }
        if (carry == 1)
            sum.insert(sum.begin(), '1');
        return sum;
    }
};
