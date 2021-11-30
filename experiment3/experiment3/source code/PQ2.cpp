#include "../header/PQ2.h"

PQ2::PQ2(int length) {
	this->length = length + 1;
	N = 0;
	priotyqueue = new pair<int, double>[length];
	priotyqueue[0].first = 0;	//index==0处不使用
	priotyqueue[0].second = 0;
}

void PQ2::add(int index, double weight) {
	//先将新插入的放在小根堆的末尾，然后通过swim来使堆重新有序
	N++;	//优先队列容量加1
	priotyqueue[N].first = index;
	priotyqueue[N].second = weight;
	swim(N);	//最后一个元素上浮
}



void PQ2::sink(int index) {
	while (index <= (N + 1) / 3) {
		//获得子节点中weight较小的节点
		int left = index * 3 - 1;		//左节点的下标
		int mid = index * 3;		//中间的节点
		int right = index * 3 + 1;	//右节点
		//找到weight较小的节点，必须注意子节点超过有效范围的情况
		int index2 = left;
		if (priotyqueue[left].second > priotyqueue[mid].second && mid <= N)
			index2 = mid;
		if (priotyqueue[index2].second > priotyqueue[right].second && right <= N)
			index2 = right;

		if (priotyqueue[index].second <= priotyqueue[index2].second)
			break;
		exch(index, index2);	//交换小根堆中节点的值

		index = index2;
	}
}



void PQ2::swim(int index) {
	while (index > 1) {
		pair<int, double> parent = priotyqueue[(index + 1) / 3];		//父节点
		if (parent.second <= priotyqueue[index].second)
			break;
		exch(index, (index + 1) / 3);		//与父结点交换元素
		index = (index + 1) / 3;		//上浮
	}
}



void PQ2::exch(int index1, int index2) {
	pair<int, double> temp = priotyqueue[index1];
	priotyqueue[index1] = priotyqueue[index2];
	priotyqueue[index2] = temp;
}


pair<int, double> PQ2::deleteMin() {
	//将末尾的元素与首元素交换，然后将首元素sink使小根堆重新有序
	exch(1, N);
	N--;	//优先队列容量减1
	sink(1);//使堆重新有序

	return priotyqueue[N + 1];		//返回被删除的元素
}


bool PQ2::isExist(int index) {
	for (int i = 0; i < N; i++) {
		if (priotyqueue[i].first == index)
			return true;
	}
	return false;
}


void PQ2::changePQ(int index, double weight) {
	//先直接修改
	for (int i = 0; i < N; i++) {
		if (priotyqueue[i].first == index)
			priotyqueue[i].second = weight;
	}

	//自右向左sink一次，使队列恢复顺序
	for (int i = (N + 1) / 3; i >= 1; i--) {
		sink(i);
	}
}



int PQ2::getN() {
	return N;
}
