#pragma once
#ifndef _VERTEX_H
#define _VERTEX_H


/*****************************************************************************
* @author  : bigbiginsulator/chuansao825                                                             *
* @date    :2021//11/29
* @file    :
* @brief   :一个顶点的信息
*****************************************************************************/
class vertex {
public:
	int x;		//x坐标
	int y;		//y坐标
	vertex(int x,int y);
	vertex();	//默认构造函数
};

#endif