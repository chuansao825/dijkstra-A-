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
* @brief   :����ͼ����Ϣ
*****************************************************************************/
class graph {
private:
	int numofvertex;	//�������
	int numofedges;		//�ߵ�����
	double getWeight(int x1, int y1, int x2, int y2);	//����������������ΪȨֵ		
public:
	set<edge*>** adjlist;	//�ڽӱ�
	vertex** vertexarray;	//������������

	/*****************************************************************************
	* @name   :graph
	* @input   :none
	* @output  :none
	* @brief   :��data.txt�ļ��ж�ȡ���ݹ���һ��ͼ���������ڽӱ���
	*****************************************************************************/
	graph();


	/*****************************************************************************
	* @name   :
	* @input   :
	* @output  :
	* @brief   :��һ������ʱ��data.txt�е����ݽ��д������浽simpdata.txt��,
	*			�ӿ������Ч��
	*****************************************************************************/
	void initGraph();


	int getNumOfVertex() { return numofvertex; }
	int getNumOfEdges() { return numofedges; }
};




#endif
