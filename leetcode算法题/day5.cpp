#include <iostream>

#include <vector>

using namespace std;

//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//
//	vector<int>::iterator itor;
//
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}

int main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);
	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(100);
	v.resize(20);
	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(50);
	v.resize(5);
	cout << v.size() << ":" << v.capacity() << endl;
}

//26. 删除有序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int front = 0, after = 0, k = 1;
        while (front <= after && after < len - 1)
        {
            if (nums[after] != nums[after + 1])
            {
                if (front == after)
                {
                    front++;
                    after++;
                    k++;
                    continue;
                }
                front++;
                nums[front] = nums[after + 1];
                k++;
            }
            after++;
        }
        return k;
    }
};

