//#include<iostream>
//using namespace std;
//#include<queue>
//#include<stack>
//#include<string>
//
//int p, q;
//int min;   //��С����
//void df(int x, int y, int setp) {
//	if (x == p && y == q) {
//		//�����ҵ��յ�.
//		if (setp < min) {
//			min = step;
//		}
//		return;
//	}
//
//
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//int main() {
//	
//	
//
//	system("pause");
//	return  0;
//
//}
//
//
////ȫ����.
//int book[10];//1-9����  Ϊ0 ����û���� 
//int aaa[10];
//int n;
////��������㷨,�����м���
//
//void dfs(int x)// x��ʾΪ�ڼ�������.
//{
//	int i;
//	if (x == n + 1) {   //��������һ��
//
//		for (i = 1; i <= n; i++) {
//			cout << aaa[i] << " ";
//		}
//		cout << endl;
//		return;
//	}
//	for (i = 1; i <= n; i++) {
//		if (book[i] == 0) {
//			//����û��
//			aaa[x] = i;
//			book[i] = 1;
//			dfs(x + 1);
//			book[i] = 0;
//		}
//
//	}
//
//	return;
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//int fun(int n) {
//	int sum = 0;
//	int a[10] = { 6,2,5,6,4,5,6,3,7,6 };
//	while (n / 10 != 0) {
//		sum += a[n % 10];
//		n /= 10;
//	}
//	sum += a[n];
//
//	return sum;
//}
//
//void  huocairen() {
//	int i, j, k, a, b, c, n;
//	cin >> n;  //n�����
//	int sum = 0;
//	for (a = 0; a <= 11111; a++) {
//		for (b = 0; b <= 11111; b++) {
//			c = a + b;
//			if (fun(a) + fun(b) + fun(c) == n - 4) {
//				cout << a << '+' << b << '=' << a + b << endl;
//				sum++;
//			}
//
//		}
//	}
//	cout << "һ������ƴ��" << sum << "����ͬ�ĵ�ʽ";
//
//
//}
//
//
//
//void zhadanren() {
//	int i, j, x, y, p, q;
//	int n, m, map = 0;
//	int sum = 0;
//	cin >> n >> m;  //n��m��
//	vector<vector<char>>v(n, vector<char>(m));
//	for (i = 0; i <= n - 1; i++) {
//		for (j = 0; j <= m - 1; j++) {
//			cin >> v[i][j];
//		}
//	}
//	for (i = 0; i <= n - 1; i++) {
//		for (j = 0; j <= m - 1; j++) {
//			if (v[i][j] == '.') {
//				sum = 0;
//				x = i, y = j;//����
//				while (v[x][y] != '#') {
//					if (v[x][y] == 'G') {
//						sum++;
//					}
//					//�ж�Խ��.
//					x--;
//				}
//				x = i, y = j;//����
//				while (v[x][y] != '#') {
//					if (v[x][y] == 'G') {
//						sum++;
//					}
//					x++;
//				}
//				x = i, y = j;//��
//				while (v[x][y] != '#') {
//					if (v[x][y] == 'G') {
//						sum++;
//					}
//					y--;
//				}
//				x = i, y = j;//����
//				while (v[x][y] != '#') {
//					if (v[x][y] == 'G') {
//						sum++;
//					}
//					y++;
//				}
//				if (sum > map) {
//					map = sum;
//					p = i;
//					q = j;
//				}
//
//			}
//		}
//	}
//
//
//	cout << "��ը���ŵ�(" << p << "," << q << "),�������" << map << "������" << endl;
//
//
//
//
//}
//bool isright(string &s) {
//	stack<char>st;
//	int i, j;
//	for (i = 0; i < s.size(); i++) {
//		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
//			st.push(s[i]);
//		}
//		else {
//			if (st.size() == 0) {
//				return false;
//			}
//			if (s[i] == ')') {
//				if (st.top() == '(') {
//					st.pop();
//				}
//				else {
//					break;
//				}
//			}
//			if (s[i] == ']') {
//				if (st.top() == '[') {
//					st.pop();
//				}
//				else {
//					break;
//				}
//			}
//			if (s[i] == '}') {
//				if (st.top() == '{') {
//					st.pop();
//				}
//				else {
//					break;
//				}
//			}
//		}
//	}
//	if (st.size() == 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//
//
//void  huiwen() {
//	//���Ĵ���stack���
//	//1.Ҫ�ǻ��Ĵ�����ʱ�ѳɵ�  ,��Ҫ���м�
//	//2.���м�������Ķ���վ, 
//	string s;
//	int i, j, k;
//	stack<char>sk;
//	getline(cin, s);   //��ȡһ��
//	int mid = s.size() / 2 - 1;   //�м�
//
//
//}
//
//
//
//void solveMi() {
//	queue<int>q;
//	int i, j, n;
//	cin >> n;
//	for (i = 1; i <= n; i++) {
//		cin >> j;
//		q.push(j);
//
//	}
//	while (!q.empty()) {
//		cout << q.front() << " ";
//		q.pop();
//		if (!q.empty()) {
//			q.push(q.front());
//			q.pop();
//		}
//	}
//
//}
//
//
//
//
//
//
//
//void qvchong() {
//
//	int a[101], i, j, k, n;
//	int sum;
//	cin >> n;
//	for (i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	//ð������
//	for (i = 1; i <= n - 1; i++) {
//		for (j = 1; j <= n - i; j++) {
//			if (a[j] > a[j + 1]) {
//				swap(a[j], a[j + 1]);
//			}
//
//		}
//	}
//	//�����ȥ��
//	cout << a[1] << " ";  //�����һ����Ȼ��ÿ���жϺ���һ���������Ƿ�Ӣ��
//	for (i = 2; i <= n; i++) {
//		if (a[i] == a[i - 1]) {
//
//		}
//		else {
//			cout << a[i] << " ";
//		}
//	}
//
//
//}
//
//void buyBook() {
//	int a[1001];
//	int i, j, n, k;
//	int sum = 0;
//	cin >> n;
//	for (i = 1; i <= 1000; i++) {
//		a[i] = 0;
//	}
//	for (i = 1; i <= n; i++) {
//		cin >> k;
//		if (a[k] == 0) {
//			sum++;
//			a[k]++;
//		}
//
//	}
//	cout << sum << endl;
//
//	for (i = 1; i <= 1000; i++) {
//		if (a[i] != 0) {
//
//			cout << i << " ";
//		}
//	}
//}
//
//int dealWay(int *src, int left, int right) {
//
//	int tmp = src[left];
//	int i = left;
//	int j = right;
//	while (i != j) {
//		while (src[j] >= tmp && i < j) {
//			j--;
//		}
//		while (src[i] <= tmp && i < j) {
//			i++;
//		}
//
//
//		if (i < j) {
//			swap(src[i], src[j]);
//		}
//	}
//	//i,j ��ȵĵط����ǻ�׼���£�
//	src[left] = src[i];
//	src[i] = tmp;
//	return i;
//}
//
//void Way(int*src, int left, int right) {
//	//��ȷ����߲�����ڵ������棬 ���ڲ���Ҫ��
//	if (left < right) {
//		int mid = dealWay(src, left, right);
//		Way(src, left, mid - 1);
//		Way(src, mid + 1, right);
//	}
//
//}
//void quickSort(int*src, int n) {
//	//�õݹ�
//	Way(src, 1, n);
//}
//
//
//
//
//struct  student
//{
//	char name[21];
//	char score;
//
//}student;
//
//void studentSort() {
//	struct student s[100], t;
//	int i, j, n;
//	cin >> n;
//	for (i = 1; i <= n; i++) {
//		cin >> s[i].name >> s[i].score;
//	}
//
//	for (i = 1; i <= n - 1; i++) {
//		for (j = 1; j <= n - i; j++) {
//			if (s[j].score > s[j + 1].score) {
//				swap(s[j], s[j + 1]);
//			}
//		}
//	}
//	for (i = 1; i <= n; i++) {
//		cout << s[i].name << endl;
//	}
//
//}
//
//
//
//
//void bubble() {
//	int a[100], i, j, k;
//	int n;
//	cin >> n;
//	//����
//	for (i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (i = 1; i <= n - 1; i++) {
//		//n-1��
//		for (j = 1; j <= n - i; j++) {
//			if (a[j] > a[j + 1]) {
//				swap(a[j], a[j + 1]);
//			}
//		}
//	}
//
//
//	for (i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
//
//
//
//}
//
//void tong() {
//	int a[11], i, j, k;
//	for (i = 0; i < 11; i++) {
//		a[i] = 0;
//	}
//	for (i = 1; i <= 5; i++) {
//		cin >> k;
//		a[k]++;
//	}
//
//	for (i = 0; i < 11; i++) {
//		for (j = 1; j <= a[i]; j++) {
//			cout << i << " ";
//		}
//	}
//}
//
