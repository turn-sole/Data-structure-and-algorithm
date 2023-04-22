#include<iostream>
//class A
//{
//private:
//	int value;
//public:
//	A(int n) { value = n; }
//	A(const A&& other) { value = other.value; }
//	void Print() { std::cout << value << std::endl; }
//};
//int _tmain(int argc, _TCHAR* argv[])
//{
//	A a = 10;
//	A b = a;
//	b.Print();
//	return 0;
//}
class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);
private:
	char* m_pData;
};