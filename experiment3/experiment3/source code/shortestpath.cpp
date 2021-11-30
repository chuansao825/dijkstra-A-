#include "../header/shortestpath.h"

shortestpath::shortestpath(graph* g, int s) {
	

	this->g = g;
	this->s = s;
	disTo = new double[g->getNumOfVertex()];
	edgeTo = new edge*[g->getNumOfVertex()];
	//��ditTo������ⶼ��ΪINF����㴦��Ϊ0
	for (int i = 0; i < g->getNumOfVertex(); i++) {
		if (i == s)
			disTo[i] = 0;
		else
			disTo[i] = INF;
	}

	pq = new PQ(g->getNumOfVertex());
	pq2 = new PQ2(g->getNumOfVertex());
	start = 0;
	end = 0;
}


void shortestpath::solveShortestPath() {
	//��ʼ��ʱ
	start = clock();


	int currentvertex = -1;	//��ǰҪ�����ɳڲ����ĵ�
	pq->add(s, 0);			//���ȶ��г�ʼֵΪ��ʼ��

	//dijkstra�㷨
	while (pq->getN() != 0) {
		//�����ȶ��У�С���ѣ��л�ȡ��һ������·�����Ķ��㣬��currentvertex
		currentvertex = pq->deleteMin().first;


		//�Ըõ�currentvertex�����ɳڲ���
		for (set<edge*>::iterator iter = g->adjlist[currentvertex]->begin();
			iter != g->adjlist[currentvertex]->end(); iter++) {
			edge* tempedge = *iter;		//��ȡһ�����ӱ�
			int w = tempedge->w;			//�ߵ���һ������
			double weight = tempedge->weight;	//�ߵ�Ȩֵ

			//�ж��Ƿ�Ҫ�����ɳڲ���
			if (disTo[w] > disTo[currentvertex] + weight) {
				disTo[w] = disTo[currentvertex] + weight;	//����disTo
				edgeTo[w] = tempedge;		//����edgeTo

				//�������ȶ����е�����
				//w���������ڶ����о͸���ֵ
				if (pq->isExist(w))
					pq->changePQ(w, disTo[w]);
				//w�����ݲ��ڶ����У�����ֵ
				else
					pq->add(w, disTo[w]);
			}
		}
	}


	//������ʱ
	end = clock();
}




void shortestpath::solveShortestPath(int destination) {
	start = clock();


	int currentvertex = -1;	//��ǰҪ�����ɳڲ����ĵ�
	pq->add(s, 0);			//���ȶ��г�ʼֵΪ��ʼ��

	//dijkstra�㷨
	while (pq->getN() != 0) {
		//�����ȶ��У�С���ѣ��л�ȡ��һ������·�����Ķ��㣬��currentvertex
		currentvertex = pq->deleteMin().first;

		//������Ӹ��жϣ�����ǰ�������·�����Ľڵ����Ŀ�Ķ���ͽ���
		if (currentvertex==destination)
			break;


		//�Ըõ�currentvertex�����ɳڲ���
		for (set<edge*>::iterator iter = g->adjlist[currentvertex]->begin();
			iter != g->adjlist[currentvertex]->end(); iter++) {
			edge* tempedge = *iter;		//��ȡһ�����ӱ�
			int w = tempedge->w;			//�ߵ���һ������
			double weight = tempedge->weight;	//�ߵ�Ȩֵ

			//�ж��Ƿ�Ҫ�����ɳڲ���
			if (disTo[w] > disTo[currentvertex] + weight) {
				disTo[w] = disTo[currentvertex] + weight;	//����disTo
				edgeTo[w] = tempedge;		//����edgeTo

				//�������ȶ����е�����
				//w���������ڶ����о͸���ֵ
				if (pq->isExist(w))
					pq->changePQ(w, disTo[w]);
				//w�����ݲ��ڶ����У�����ֵ
				else
					pq->add(w, disTo[w]);
			}
		}
	}


	end = clock();
}

void shortestpath::solveShortestPath2(int destination) {
	start = clock();


	int currentvertex = -1;	//��ǰҪ�����ɳڲ����ĵ�
	pq2->add(s, 0);			//���ȶ��г�ʼֵΪ��ʼ��

	//dijkstra�㷨
	while (pq2->getN() != 0) {
		//�����ȶ���(�����)�л�ȡ��һ������·�����Ķ��㣬��currentvertex
		currentvertex = pq2->deleteMin().first;

		//������Ӹ��жϣ�����ǰ�������·�����Ľڵ����Ŀ�Ķ���ͽ���
		if (currentvertex == destination)
			break;


		//�Ըõ�currentvertex�����ɳڲ���
		for (set<edge*>::iterator iter = g->adjlist[currentvertex]->begin();
			iter != g->adjlist[currentvertex]->end(); iter++) {
			edge* tempedge = *iter;		//��ȡһ�����ӱ�
			int w = tempedge->w;			//�ߵ���һ������
			double weight = tempedge->weight;	//�ߵ�Ȩֵ

			//�ж��Ƿ�Ҫ�����ɳڲ���
			if (disTo[w] > disTo[currentvertex] + weight) {
				disTo[w] = disTo[currentvertex] + weight;	//����disTo
				edgeTo[w] = tempedge;		//����edgeTo

				//�������ȶ����е�����
				//w���������ڶ����о͸���ֵ
				if (pq2->isExist(w))
					pq2->changePQ(w, disTo[w]);
				//w�����ݲ��ڶ����У�����ֵ
				else
					pq2->add(w, disTo[w]);
			}
		}
	}


	end = clock();
}


void shortestpath::printShortestPath(int destination) {
	edge* tempedge = NULL;
	int i = destination;
	//ʹ��һ��ջ���ݴ�����
	stack<edge*> st;
	while (true) {
		tempedge = edgeTo[i];
		st.push(tempedge);		//ѹջ
		if (tempedge->v == s)	//�ѵ������
			break;
		i = tempedge->v;		//��������
	}

	int counter = 0;
	//��ջ������ӡ����
	while (!st.empty()) {
		edge* e=st.top();	//���ջ��Ԫ��
		st.pop();	//��ջ
		cout << e->toString() << "\t" ;
		counter++;
		if (counter == 6){
			counter = 0;	//�Զ��������
			cout << endl;
		}
	}
	cout << endl;
	cout << "����:" << disTo[destination]<<endl;

	//���ʱ��
	cout << "����ʱ�䣺" << getTime() << "ms" << endl;

}





shortestpath::~shortestpath() {
	delete disTo;
	delete edgeTo;
	delete pq;
	delete pq2;
}




void shortestpath::AStar(int destination) {
	start = clock();


	//���졢��ʼ��open_set��close_set�����涥������
	set<int>* open_set = new set<int>();
	set<int>* close_set = new set<int>();




	//�㷨���
	//��������������ȶ���
	pq2->add(s, 0);

	while (pq2->getN() != 0) {
		//�����ȶ����еõ����ȼ���ߵĵ�n�������õ����close_set
		int currentvertex = pq2->deleteMin().first;
		close_set->insert(currentvertex);
		open_set->erase(currentvertex);

		//�ж��Ƿ�����˳�
		if (currentvertex == destination)
			break;

		//�Ե�n�Ƚ����ɳڲ�������g(n),Ȼ���ÿ�����ڵ����h(n)�����õ�f(n),������close�ĵ����
		//���ȶ���
		for (set<edge*>::iterator iter = g->adjlist[currentvertex]->begin();
			iter != g->adjlist[currentvertex]->end(); iter++) {
			edge* tempedge = *iter;			//��ȡһ�����ӱ�
			int w = tempedge->w;			//�ߵ���һ������
			double weight = tempedge->weight;	//�ߵ�Ȩֵ
			double g_n = 0;		//g(n)
			double h_n = 0;		//h(n)
			double f_n = 0;		//f(n)

			//�ж��Ƿ���close_set��
			if (close_set->find(w) != close_set->end())
				continue;
			if (open_set->find(w)==open_set->end()) {
				open_set->insert(w);
			}

			if (disTo[currentvertex] + tempedge->weight < disTo[w]) {
				disTo[w] = disTo[currentvertex] + tempedge->weight;
				edgeTo[w] = tempedge;
			}
			g_n = disTo[w];
			int dx = (g->vertexarray[w]->x) - (g->vertexarray[destination]->x);
			int dy = (g->vertexarray[w]->y) - (g->vertexarray[destination]->y);
			h_n = sqrt(pow(dx, 2) + pow(dy, 2));	//��������Ϊŷ�ϼ��ξ���
			f_n = g_n + h_n;

			//�������ȶ���
			//w���������ڶ����о͸���ֵ
			if (pq2->isExist(w))
				pq2->changePQ(w, f_n);
			//w�����ݲ��ڶ����У�����ֵ
			else
				pq2->add(w, f_n);

		}
	}


	end = clock();
}