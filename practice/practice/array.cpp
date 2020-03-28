//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> printMatrix(vector<vector<int> > matrix) {
//		int row = matrix.size();
//		int col = matrix[0].size();
//		vector<int>v;
//		if (row == 0 || col == 0) {
//			return v;
//		}
//		while (matrix.size() > 0) {
//			for (int i = 0; i < matrix[0].size(); i++) {
//				v.push_back(matrix[0][i]);
//			}
//			matrix.erase(matrix.begin());
//			if (matrix.size() > 0) {
//				row = matrix.size();
//				col = matrix[0].size();
//				vector<vector<int>> p(col);
//
//				for (int i = col - 1; i >= 0; i--) {
//
//					for (int j = 0; j < row; j++) {
//						p[col - 1 - i].push_back(matrix[j][i]);
//					}
//				}
//				matrix.swap(p);
//			}
//		}
//		return  v;
//	}
//};
//
//
//int main() {
//	Solution s;
//	vector<vector<int>>v(3);
//
//	v[0].push_back(1);
//	v[0].push_back(2);
//	v[0].push_back(3);
//	v[1].push_back(4);
//	v[1].push_back(5);
//	v[1].push_back(6);
//	v[2].push_back(7);
//	v[2].push_back(8);
//	v[2].push_back(9);
//
//	vector<int>vv=s.printMatrix(v);
//	for (auto i : vv) {
//		cout << i << " ";
//	}
//	system("pause");
//	return 0;
//}
