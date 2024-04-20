#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> v(min(numRows, int(s.size())));
        for (int i = 0; i < numRows; i++)
        {
            int pos = i;
            int flag = 1;
            while (pos < s.length())
            {
                v[i] += (s[pos]);
                if (i == numRows - 1 || i == 0)
                {
                    pos += 2 * (numRows - 1) ;
                }
                else if (flag % 2 == 1 && i != numRows - 1)
                {
                    pos += 2 * numRows - 2 * (i + 1);
                    flag++;
                }
                else if (flag % 2 == 0 && i != 0)
                {
                    pos += 2 + 2 * (i - 1);
                    flag++;
                }

            }
        }
        string res;
        for (auto t : v)
        {
            res += t;
        }
        return res;
    }

int main()
{
    string res=convert("PAYPALISHIRING", 3);
    cout << res << endl;
    return 0;


}