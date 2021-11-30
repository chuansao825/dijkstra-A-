#include "../header/PQ2.h"

PQ2::PQ2(int length) {
	this->length = length + 1;
	N = 0;
	priotyqueue = new pair<int, double>[length];
	priotyqueue[0].first = 0;	//index==0����ʹ��
	priotyqueue[0].second = 0;
}

void PQ2::add(int index, double weight) {
	//�Ƚ��²���ķ���С���ѵ�ĩβ��Ȼ��ͨ��swim��ʹ����������
	N++;	//���ȶ���������1
	priotyqueue[N].first = index;
	priotyqueue[N].second = weight;
	swim(N);	//���һ��Ԫ���ϸ�
}



void PQ2::sink(int index) {
	while (index <= (N + 1) / 3) {
		//����ӽڵ���weight��С�Ľڵ�
		int left = index * 3 - 1;		//��ڵ���±�
		int mid = index * 3;		//�м�Ľڵ�
		int right = index * 3 + 1;	//�ҽڵ�
		//�ҵ�weight��С�Ľڵ㣬����ע���ӽڵ㳬����Ч��Χ�����
		int index2 = left;
		if (priotyqueue[left].second > priotyqueue[mid].second && mid <= N)
			index2 = mid;
		if (priotyqueue[index2].second > priotyqueue[right].second && right <= N)
			index2 = right;

		if (priotyqueue[index].second <= priotyqueue[index2].second)
			break;
		exch(index, index2);	//����С�����нڵ��ֵ

		index = index2;
	}
}



void PQ2::swim(int index) {
	while (index > 1) {
		pair<int, double> parent = priotyqueue[(index + 1) / 3];		//���ڵ�
		if (parent.second <= priotyqueue[index].second)
			break;
		exch(index, (index + 1) / 3);		//�븸��㽻��Ԫ��
		index = (index + 1) / 3;		//�ϸ�
	}
}



void PQ2::exch(int index1, int index2) {
	pair<int, double> temp = priotyqueue[index1];
	priotyqueue[index1] = priotyqueue[index2];
	priotyqueue[index2] = temp;
}


pair<int, double> PQ2::deleteMin() {
	//��ĩβ��Ԫ������Ԫ�ؽ�����Ȼ����Ԫ��sinkʹС������������
	exch(1, N);
	N--;	//���ȶ���������1
	sink(1);//ʹ����������

	return priotyqueue[N + 1];		//���ر�ɾ����Ԫ��
}


bool PQ2::isExist(int index) {
	for (int i = 0; i < N; i++) {
		if (priotyqueue[i].first == index)
			return true;
	}
	return false;
}


void PQ2::changePQ(int index, double weight) {
	//��ֱ���޸�
	for (int i = 0; i < N; i++) {
		if (priotyqueue[i].first == index)
			priotyqueue[i].second = weight;
	}

	//��������sinkһ�Σ�ʹ���лָ�˳��
	for (int i = (N + 1) / 3; i >= 1; i--) {
		sink(i);
	}
}



int PQ2::getN() {
	return N;
}
