/*���߳�*/


#include "../header/graph.h"
#include "../header/shortestpath.h"


int main(void) {
	//��ȡ�ļ����ݣ�����һ��ͼ
	graph* g = new graph();

	int begin;
	int end;


	
	while (true) {
		//get input
		cout << "begin:\t\tend:" << endl;
		cin >> begin >> end;
		
		//δ�Ż�ǰ
		shortestpath* sp1 = new shortestpath(g, begin);
		//�����ʼ�㵽�������е�����·��
		sp1->solveShortestPath();
		//��ӡ��Ϣ
		sp1->printShortestPath(end);
		delete sp1;


		//�Ż���ʽ1
		shortestpath* sp2 = new shortestpath(g, begin);
		sp2->solveShortestPath(end);
		sp2->printShortestPath(end);
		delete sp2;

		//ʹ���˶��ѵ��Ż�����
		shortestpath* sp3 = new shortestpath(g, begin);
		sp3->solveShortestPath2(end);
		sp3->printShortestPath(end);
		delete sp3;


		//ʹ��A*�㷨
		shortestpath* sp4 = new shortestpath(g, begin);
		sp4->AStar(end);
		sp4->printShortestPath(end);
		delete sp4;

		
	}

}