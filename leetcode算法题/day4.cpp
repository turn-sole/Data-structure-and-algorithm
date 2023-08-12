#include<iostream>

using namespace std;

//int main(int argc, char* argv[])
//
//{
//
//	string a = "hello world";
//
//	string b = a;
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	string c = b;
//
//	c = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	a = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	return 0;
//
//}

//int main()
//{
//	string str("Hello Bit.");
//	str.reserve(111);
//	str.resize(5);
//	str.reserve(50);
//	cout << str.size() << ":" << str.capacity() << endl;
//	return 0;
//}

int main(int argc, char* argv[])
{
	string strText = "How are you?";
	string strSeparator = " ";
	string strResult;
	int size_pos = 0;
    int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
		size_prev_pos = ++size_pos;
	}
	if (size_prev_pos != strText.size())
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
	}
	cout << endl;
	return 0;
}

//43. 字符串相乘
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>A, B;
        int m = num1.size(), n = num2.size();
        for (int i = m - 1; i >= 0; i--)
            A.push_back(num1[i] - '0');
        for (int i = n - 1; i >= 0; i--)
            B.push_back(num2[i] - '0');

        vector<int>C(m + n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i + j] += A[i] * B[j];
            }
        }

        int v = 0;
        for (int i = 0; i < C.size(); i++)
        {
            v += C[i];
            C[i] = v % 10;
            v /= 10;
        }

        int k = C.size() - 1;
        while (k > 0 && !C[k])
            k--;
        string num;
        while (k >= 0)
            num += C[k--] + '0';
        return num;
    }
};

//136. 只出现一次的数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        for (auto e : nums)
        {
            value ^= e;
        }

        return value;
    }
};

//118. 杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>a(numRows);

        for (int i = 0; i < numRows; i++)
        {
            a[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            }
        }

        return a;

    }
};



