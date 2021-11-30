#include "../header/shortestpath.h"

shortestpath::shortestpath(graph* g, int s) {
	

	this->g = g;
	this->s = s;
	disTo = new double[g->getNumOfVertex()];
	edgeTo = new edge*[g->getNumOfVertex()];
	//将ditTo除起点外都置为INF，起点处置为0
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
	//开始计时
	start = clock();


	int currentvertex = -1;	//当前要进行松弛操作的点
	pq->add(s, 0);			//优先队列初始值为起始点

	//dijkstra算法
	while (pq->getN() != 0) {
		//从优先队列（小根堆）中获取下一个进入路径树的顶点，即currentvertex
		currentvertex = pq->deleteMin().first;


		//对该点currentvertex进行松弛操作
		for (set<edge*>::iterator iter = g->adjlist[currentvertex]->begin();
			iter != g->adjlist[currentvertex]->end(); iter++) {
			edge* tempedge = *iter;		//获取一条连接边
			int w = tempedge->w;			//边的另一个顶点
			double weight = tempedge->weight;	//边的权值

			//判断是否要进行松弛操作
			if (disTo[w] > disTo[currentvertex] + weight) {
				disTo[w] = disTo[currentvertex] + weight;	//更新disTo
				edgeTo[w] = tempedge;		//更新edgeTo

				//更新优先队列中的数据
				//w的数据已在队列中就更新值
				if (pq->isExist(w))
					pq->changePQ(w, disTo[w]);
				//w的数据不在队列中，插入值
				else
					pq->add(w, disTo[w]);
			}
		}
	}


	//结束计时
	end = clock();
}




void shortestpath::solveShortestPath(int destination) {
	start = clock();


	int currentvertex = -1;	//当前要进行松弛操作的点
	pq->add(s, 0);			//优先队列初始值为起始点

	//dijkstra算法
	while (pq->getN() != 0) {
		//从优先队列（小根堆）中获取下一个进入路径树的顶点，即currentvertex
		currentvertex = pq->deleteMin().first;

		//在这里加个判断，若当前进入最短路径树的节点等于目的顶点就结束
		if (currentvertex==destination)
			break;


		//对该点currentvertex进行松弛操作
		for (set<edge*>::iterator iter = g->adjlist[currentvertex]->begin();
			iter != g->adjlist[currentvertex]->end(); iter++) {
			edge* tempedge = *iter;		//获取一条连接边
			int w = tempedge->w;			//边的另一个顶点
			double weight = tempedge->weight;	//边的权值

			//判断是否要进行松弛操作
			if (disTo[w] > disTo[currentvertex] + weight) {
				disTo[w] = disTo[currentvertex] + weight;	//更新disTo
				edgeTo[w] = tempedge;		//更新edgeTo

				//更新优先队列中的数据
				//w的数据已在队列中就更新值
				if (pq->isExist(w))
					pq->changePQ(w, disTo[w]);
				//w的数据不在队列中，插入值
				else
					pq->add(w, disTo[w]);
			}
		}
	}


	end = clock();
}

void shortestpath::solveShortestPath2(int destination) {
	start = clock();


	int currentvertex = -1;	//当前要进行松弛操作的点
	pq2->add(s, 0);			//优先队列初始值为起始点

	//dijkstra算法
	while (pq2->getN() != 0) {
		//从优先队列(三叉堆)中获取下一个进入路径树的顶点，即currentvertex
		currentvertex = pq2->deleteMin().first;

		//在这里加个判断，若当前进入最短路径树的节点等于目的顶点就结束
		if (currentvertex == destination)
			break;


		//对该点currentvertex进行松弛操作
		for (set<edge*>::iterator iter = g->adjlist[currentvertex]->begin();
			iter != g->adjlist[currentvertex]->end(); iter++) {
			edge* tempedge = *iter;		//获取一条连接边
			int w = tempedge->w;			//边的另一个顶点
			double weight = tempedge->weight;	//边的权值

			//判断是否要进行松弛操作
			if (disTo[w] > disTo[currentvertex] + weight) {
				disTo[w] = disTo[currentvertex] + weight;	//更新disTo
				edgeTo[w] = tempedge;		//更新edgeTo

				//更新优先队列中的数据
				//w的数据已在队列中就更新值
				if (pq2->isExist(w))
					pq2->changePQ(w, disTo[w]);
				//w的数据不在队列中，插入值
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
	//使用一个栈来暂存数据
	stack<edge*> st;
	while (true) {
		tempedge = edgeTo[i];
		st.push(tempedge);		//压栈
		if (tempedge->v == s)	//已到达起点
			break;
		i = tempedge->v;		//继续回溯
	}

	int counter = 0;
	//弹栈，并打印数据
	while (!st.empty()) {
		edge* e=st.top();	//获得栈顶元素
		st.pop();	//弹栈
		cout << e->toString() << "\t" ;
		counter++;
		if (counter == 6){
			counter = 0;	//自动换行输出
			cout << endl;
		}
	}
	cout << endl;
	cout << "距离:" << disTo[destination]<<endl;

	//输出时间
	cout << "花费时间：" << getTime() << "ms" << endl;

}





shortestpath::~shortestpath() {
	delete disTo;
	delete edgeTo;
	delete pq;
	delete pq2;
}




void shortestpath::AStar(int destination) {
	start = clock();


	//构造、初始化open_set与close_set，储存顶点的序号
	set<int>* open_set = new set<int>();
	set<int>* close_set = new set<int>();




	//算法求解
	//将出发点插入优先队列
	pq2->add(s, 0);

	while (pq2->getN() != 0) {
		//从优先队列中得到优先级最高的点n，并将该点加入close_set
		int currentvertex = pq2->deleteMin().first;
		close_set->insert(currentvertex);
		open_set->erase(currentvertex);

		//判断是否可以退出
		if (currentvertex == destination)
			break;

		//对点n先进行松弛操作计算g(n),然后对每个相邻点计算h(n)，最后得到f(n),并将非close的点加入
		//优先队列
		for (set<edge*>::iterator iter = g->adjlist[currentvertex]->begin();
			iter != g->adjlist[currentvertex]->end(); iter++) {
			edge* tempedge = *iter;			//获取一条连接边
			int w = tempedge->w;			//边的另一个顶点
			double weight = tempedge->weight;	//边的权值
			double g_n = 0;		//g(n)
			double h_n = 0;		//h(n)
			double f_n = 0;		//f(n)

			//判断是否在close_set中
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
			h_n = sqrt(pow(dx, 2) + pow(dy, 2));	//启发函数为欧氏几何距离
			f_n = g_n + h_n;

			//加入优先队列
			//w的数据已在队列中就更新值
			if (pq2->isExist(w))
				pq2->changePQ(w, f_n);
			//w的数据不在队列中，插入值
			else
				pq2->add(w, f_n);

		}
	}


	end = clock();
}