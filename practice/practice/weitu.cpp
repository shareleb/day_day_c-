//#include<iostream>
//using namespace std;
//#include<vector>
//
//namespace leb {
//	class bitmap {
//
//	public:
//		bitmap(size_t bitc) :m_bitc(bitc / 32 + 1), m_bitCount(bitc) {
//
//		}
//		void set(size_t pos) {
//			if (pos > m_bitCount) {
//				return;
//			}
//
//			size_t index = pos / 32;
//			size_t bits = pos % 32;
//			m_bitc[index] |= 1u << bits;   //将1标记为unsigned类型。
//		//置0 位 |   置1  用与非     置反为异或
//
//		}
//		void reset(size_t pos) {
//			if (pos > m_bitCount) {
//				return;
//			}
//
//			size_t index = pos / 32;
//			size_t bits = pos % 32;
//			m_bitc[index] &= ~(1u << bits);
//		}
//
//		bool get(size_t pos) {
//			if (pos > m_bitCount) {
//				return false;
//			}
//
//			size_t index = pos / 32;
//			size_t bits = pos % 32;
//			return m_bitc[index] >> bits & 1;
//		}
//
//		size_t size() {
//			return m_bitCount;
//		}
//		size_t count() {
//			//8进制
//			size_t bittable[16] = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4 };
//			size_t size = m_bitc.size();
//			size_t count = 0;
//			size_t i;
//			for (i = 0; i < size; i++) {
//				int value = m_bitc[i];
//				int j = 0;
//				for (j = 0; j < sizeof(m_bitc[0]); j++, value >>= 8) {
//					char c = value;
//					count += bittable[c & 0x0f];
//					c >>=4;
//					count += bittable[c & 0x0f];
//				}
//			}
//			return count;
//		}
//
//	private:
//		vector<int>  m_bitc;
//		size_t m_bitCount; //相当于capacity；
//		//size可选项。
//
//	};
//
//}
//int main() {
//
//	leb::bitmap bt(10);
//	bt.set(3);
//	bt.set(5);
//	bt.set(8);
//	bt.set(0);
//	bt.set(7);
//	bt.reset(5);
//
//	cout << bt.count() << endl;
//	
//
//
//	system("pause");
//	return 0;
//}