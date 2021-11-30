#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H

#include "..//header/edge.h"
#include "..//header/vertex.h"
#include <iostream>
#include<string>
#include <stdio.h>
#include<set>

using namespace std;

/*****************************************************************************
* @author  : bigbiginsulator/chuansao825                                                             *
* @date    :2021/11/28
* @file    :
* @brief   :储存图的信息
*****************************************************************************/
class graph {
private:
	int numofvertex;	//点的数量
	int numofedges;		//边的数量
	double getWeight(int x1, int y1, int x2, int y2);	//根据坐标计算距离作为权值		
public:
	set<edge*>** adjlist;	//邻接表
	vertex** vertexarray;	//顶点对象的数组

	/*****************************************************************************
	* @name   :graph
	* @input   :none
	* @output  :none
	* @brief   :从data.txt文件中读取数据构造一个图，储存在邻接表中
	*****************************************************************************/
	graph();


	/*****************************************************************************
	* @name   :
	* @input   :
	* @output  :
	* @brief   :第一次运行时将data.txt中的数据进行处理并储存到simpdata.txt中,
	*			加快后续的效率
	*****************************************************************************/
	void initGraph();


	int getNumOfVertex() { return numofvertex; }
	int getNumOfEdges() { return numofedges; }
};




#endif
