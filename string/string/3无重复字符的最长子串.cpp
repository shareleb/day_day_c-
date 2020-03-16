//#include<iostream>
//#include<vector>
//#include<string>
//#include<map>
//using namespace std;
//
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		map<char, int>m;
//		int max = 0;
//		if (s.size() == 1)
//		{
//			return 1;
//		}
//		else
//		{
//			for (int i = 0; i < s.size(); i++)
//			{
//				for (int j = i; j < s.size(); j++)
//				{
//					auto it = m.insert(pair<char, int>(s[j], 1));
//					if (it.second == false)
//					{
//						if (m.size() > max)
//						{
//							max = m.size();
//							
//						}
//						m.clear();
//						break;
//					}
//
//				}
//
//			}
//			return max;
//
//		}
//	}
//};
//bool isCircle(string s)
//{
//	string str(s);
//	reverse(str.begin(), str.end());
//	if (str == s)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
//int main()
//{
//
//	/*Solution s;
//	string str("jbpnbwwd");
//	cout << s.lengthOfLongestSubstring(str) << endl;*/
//
//	string s("hailah");
//	if (isCircle(s))
//	{
//		cout << "s是回文串" << endl;
//	}
//	else
//	{
//		cout << "s不是回文串" << endl;
//	}
//	system("pause");
//	return 0;
//}