//������ 01.03.URL��
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int pos = 0;
        string res = "";
        while (pos < S.size() && S[pos] == ' ' && length != 0)
        {
            res += "%20";
            length--;
            pos++;
        }
        if (pos == S.size())
        {
            while (length != 0)
            {
                res += "%20";
                length--;
            }
            return res;
        }
        while (pos < S.size())
        {
            if (length == 0)
                break;
            if (S[pos] != ' ')
            {
                res += S[pos];
                length--;
            }
            else if (S[pos] == ' ')
            {
                res += "%20";
                length--;
            }
            pos++;
        }
        return res;
    }
};

//������ 01.06.�ַ���ѹ��
class Solution {
public:
    string compressString(string S) {
        int i = 0, j = 0;
        string res;
        while (i < S.length())
        {
            while (j < S.length() && S[i] == S[j])
                j++;
            res += S[i];
            res += to_string(j - i);
            i = j;
        }
        return res.length() < S.length() ? res : S;
    }
};

//������ 05.07.��Խ���
class Solution {
public:
    int exchangeBits(int num) {
        return (((num & 0x55555555) << 1) | ((num & 0xaaaaaaaa) >> 1));
    }
};