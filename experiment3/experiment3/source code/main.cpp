/*主线程*/


#include "../header/graph.h"
#include "../header/shortestpath.h"


int main(void) {
	//读取文件数据，创建一个图
	graph* g = new graph();

	int begin;
	int end;


	
	while (true) {
		//get input
		cout << "begin:\t\tend:" << endl;
		cin >> begin >> end;
		
		//未优化前
		shortestpath* sp1 = new shortestpath(g, begin);
		//求解起始点到其余所有点的最短路径
		sp1->solveShortestPath();
		//打印信息
		sp1->printShortestPath(end);
		delete sp1;


		//优化方式1
		shortestpath* sp2 = new shortestpath(g, begin);
		sp2->solveShortestPath(end);
		sp2->printShortestPath(end);
		delete sp2;

		//使用了多叉堆的优化方法
		shortestpath* sp3 = new shortestpath(g, begin);
		sp3->solveShortestPath2(end);
		sp3->printShortestPath(end);
		delete sp3;


		//使用A*算法
		shortestpath* sp4 = new shortestpath(g, begin);
		sp4->AStar(end);
		sp4->printShortestPath(end);
		delete sp4;

		
	}

}