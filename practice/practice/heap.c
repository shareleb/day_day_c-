//#include"heap.h"
//#include<stdlib.h>
//#include<stdio.h>
//
//void adjustDown(Heap* hp, int m)
//{
//	int  cur = m;
//	
//	int max;  //用max表示的是下标
//	while (cur * 2 + 1 <= hp->size)  //没有孩子跳出
//	{
//		if (cur * 2 + 2 <= hp->size) {
//			//有左右孩子；
//			if (hp->data[cur * 2 + 1] >= hp->data[cur * 2 + 2]) {
//				max = cur * 2 + 1;
//			}
//			else {
//				max =cur * 2 + 2;
//
//			}
//
//		}
//		else {
//			//有左孩子没有右孩子；
//			max =cur * 2 + 1;
//		}
//		if (hp->data[cur] < hp->data[max]) {
//			
//			DataType tmp= hp->data[max];
//			hp->data[max] = hp->data[cur];
//			hp->data[cur] = tmp;
//			cur = max;
//
//		}
//
//
//	}
//	
//
//}
//
//void HeapInit(Heap * hp, DataType *a, int n)
//{
//	hp->size = n;
//	hp->capacity = 2 * n;
//	hp->data = (DataType*)malloc(sizeof(DataType)* hp->capacity);
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		hp->data[i] = a[i];
//
//	}
//	for (i = n / 2 - 1; i >= 0; i--) {
//		adjustDown(hp, i);
//	}
//}
//void HeapDestory(Heap * hp) {
//	if (hp->data != NULL) {
//		free(hp->data);
//		hp->data = NULL;
//		hp->size = 0;
//		hp->capacity = 0;
//	}
//}
//void HeapPush(Heap * hp, DataType x) {
//	//向堆里插入一个数据
//
//	hp->size++;
//	hp[size]
//
//}