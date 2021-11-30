#include "../header/graph.h"


graph::graph() {
	//读取simpdata.txt文件中的数据
	//判断是否已创建中间数据文件，若创建的话直接使用
	FILE* tempfile = fopen("../experiment3/data source/simpdata.txt", "r");
	if ( tempfile== NULL) 
		initGraph();	//创建中间数据文件
	else
		fclose(tempfile);

	//打开中间数据文件,模式为只读
	FILE* fp = fopen("../experiment3/data source/simpdata.txt", "r");

	//读取顶点数、边数
	fscanf(fp, "%d", &numofvertex);
	fscanf(fp, "%d", &numofedges);

	//创建邻接表
	adjlist = new set<edge*>*[numofvertex];
	for (int i = 0; i < numofvertex; i++) {
		adjlist[i] = new set<edge*>;
	}
	//使用数据填充邻接表
	for (int i = 0; i < numofedges; i++) {
		int v = 0;
		int w = 0;
		double weight = 0;
		fscanf(fp, "%d", &v);
		fscanf(fp, "%d", &w);
		fscanf(fp, "%lf", &weight);

		//填充邻接表
		adjlist[v]->insert(new edge(v, w, weight));
		adjlist[w]->insert(new edge(w, v, weight));
	}

	fclose(fp);		//关闭文件流



	//读取顶点信息
	//创建顶点数组
	vertexarray = new vertex*[numofvertex];
	string address = "../experiment3/data source/data.txt";
	FILE* fp2 = fopen(address.c_str(), "r");
	int temp;
	fscanf(fp2, "%d%d",&temp,&temp);	//丢弃首行信息
	for (int i = 0; i < numofvertex; i++) {
		int index = 0;
		int x = 0;
		int y = 0;
		fscanf(fp2, "%d%d%d", &index, &x, &y);
		vertexarray[index] = new vertex( x, y);		//将数据加入数组
	}


}


void graph::initGraph() {
	//从文件中读取数据
	//打开文件
	FILE* fp = fopen("../experiment3/data source/data.txt", "r");
	fscanf(fp, "%d", &numofvertex);		//获得顶点数
	fscanf(fp, "%d", &numofedges);		//获得边数

	//创建一个文件储存结果
	FILE* fp2 = fopen("../experiment3/data source/simpdata.txt", "w");

	//将数据写入新文件
	fprintf(fp2, "%d ", numofvertex);
	fprintf(fp2, "%d\n", numofedges);


	
	//处理数据
	//先创建所有顶点对象的数组
	vertex* array = new vertex[numofvertex];
	//读取所有点的坐标
	for (int i = 0; i < numofvertex; i++) {
		int index;
		fscanf(fp, "%d",&index);	//丢弃索引
		fscanf(fp, "%d", &array[i].x);//读取x坐标
		fscanf(fp, "%d", &array[i].y);//读取y坐标
	}
	//计算所有边的距离
	for (int i = 0; i < numofedges; i++) {
		int v = 0;	//顶点v
		int w = 0;	//顶点w
		fscanf(fp, "%d%d", &v, &w);	//读取一个顶点对
		//计算权重
		double weight=getWeight(array[v].x, array[v].y, array[w].x, array[w].y);	
		fprintf(fp2, "%d %d %lf\n", v, w, weight);	//将计算得到的数据写入新文件
	}
	
	//清理内存
	delete array;	//释放堆内存
	fclose(fp2);	//关闭文件流
	fclose(fp);		//
}


double graph::getWeight(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}