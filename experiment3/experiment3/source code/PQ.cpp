#include "../header/PQ.h"

PQ::PQ(int length) {
	this->length = length+1;
	N = 0;
	priotyqueue = new pair<int, double>[length];
	priotyqueue[0].first = 0;
	priotyqueue[0].second = 0;
}

void PQ::add(int index,double weight) {
	//先将新插入的放在小根堆的末尾，然后通过swim来使堆重新有序
	N++;	//优先队列容量加1
	priotyqueue[N].first = index;
	priotyqueue[N].second = weight;
	swim(N);	//最后一个元素上浮
}


void PQ::sink(int index) {
	while (index <= N / 2) {
		//获得子节点中weight较小的节点
		int left = index * 2;		//左节点的下标
		int right = index * 2 + 1;	//右节点
		int index2 = left;
		//排除右节点无效的情况
		if(right<=N)
			//找到weight较小的节点
			index2 = (priotyqueue[left].second) < (priotyqueue[right].second) ? left : right;

		if (priotyqueue[index].second <= priotyqueue[index2].second)
			break;

		exch(index, index2);	//交换小根堆中节点的值
		index = index2;
	}
}



void PQ::swim(int index) {
	while (index > 1) {
		pair<int,double> parent = priotyqueue[index / 2];		//父节点
		if (parent.second <= priotyqueue[index].second)
			break;
		exch(index, index / 2);		//与父结点交换元素
		index = index / 2;
	}
}



void PQ::exch(int index1, int index2) {
	pair<int,double> temp = priotyqueue[index1];
	priotyqueue[index1] = priotyqueue[index2];
	priotyqueue[index2] = temp;
}


pair<int,double> PQ::deleteMin() {
	//将末尾的元素与首元素交换，然后将首元素sink使小根堆重新有序
	exch(1, N);
	N--;	//优先队列容量减1
	sink(1);//使堆重新有序

	return priotyqueue[N + 1];		//返回被删除的元素
}


bool PQ::isExist(int index) {
	for (int i = 0; i < N; i++) {
		if (priotyqueue[i].first == index)
			return true;
	}
	return false;
}


void PQ::changePQ(int index, double weight) {
	//先直接修改
	for (int i = 0; i < N; i++) {
		if (priotyqueue[i].first == index)
			priotyqueue[i].second = weight;
	}

	//自右向左sink一次，使队列恢复顺序
	for (int i = N / 2; i >= 1; i--) {
		sink(i);
	}
}



int PQ::getN() {
	return N;
}