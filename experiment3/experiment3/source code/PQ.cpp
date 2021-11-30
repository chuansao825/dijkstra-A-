#include "../header/PQ.h"

PQ::PQ(int length) {
	this->length = length+1;
	N = 0;
	priotyqueue = new pair<int, double>[length];
	priotyqueue[0].first = 0;
	priotyqueue[0].second = 0;
}

void PQ::add(int index,double weight) {
	//�Ƚ��²���ķ���С���ѵ�ĩβ��Ȼ��ͨ��swim��ʹ����������
	N++;	//���ȶ���������1
	priotyqueue[N].first = index;
	priotyqueue[N].second = weight;
	swim(N);	//���һ��Ԫ���ϸ�
}


void PQ::sink(int index) {
	while (index <= N / 2) {
		//����ӽڵ���weight��С�Ľڵ�
		int left = index * 2;		//��ڵ���±�
		int right = index * 2 + 1;	//�ҽڵ�
		int index2 = left;
		//�ų��ҽڵ���Ч�����
		if(right<=N)
			//�ҵ�weight��С�Ľڵ�
			index2 = (priotyqueue[left].second) < (priotyqueue[right].second) ? left : right;

		if (priotyqueue[index].second <= priotyqueue[index2].second)
			break;

		exch(index, index2);	//����С�����нڵ��ֵ
		index = index2;
	}
}



void PQ::swim(int index) {
	while (index > 1) {
		pair<int,double> parent = priotyqueue[index / 2];		//���ڵ�
		if (parent.second <= priotyqueue[index].second)
			break;
		exch(index, index / 2);		//�븸��㽻��Ԫ��
		index = index / 2;
	}
}



void PQ::exch(int index1, int index2) {
	pair<int,double> temp = priotyqueue[index1];
	priotyqueue[index1] = priotyqueue[index2];
	priotyqueue[index2] = temp;
}


pair<int,double> PQ::deleteMin() {
	//��ĩβ��Ԫ������Ԫ�ؽ�����Ȼ����Ԫ��sinkʹС������������
	exch(1, N);
	N--;	//���ȶ���������1
	sink(1);//ʹ����������

	return priotyqueue[N + 1];		//���ر�ɾ����Ԫ��
}


bool PQ::isExist(int index) {
	for (int i = 0; i < N; i++) {
		if (priotyqueue[i].first == index)
			return true;
	}
	return false;
}


void PQ::changePQ(int index, double weight) {
	//��ֱ���޸�
	for (int i = 0; i < N; i++) {
		if (priotyqueue[i].first == index)
			priotyqueue[i].second = weight;
	}

	//��������sinkһ�Σ�ʹ���лָ�˳��
	for (int i = N / 2; i >= 1; i--) {
		sink(i);
	}
}



int PQ::getN() {
	return N;
}