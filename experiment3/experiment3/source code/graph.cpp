#include "../header/graph.h"


graph::graph() {
	//��ȡsimpdata.txt�ļ��е�����
	//�ж��Ƿ��Ѵ����м������ļ����������Ļ�ֱ��ʹ��
	FILE* tempfile = fopen("../experiment3/data source/simpdata.txt", "r");
	if ( tempfile== NULL) 
		initGraph();	//�����м������ļ�
	else
		fclose(tempfile);

	//���м������ļ�,ģʽΪֻ��
	FILE* fp = fopen("../experiment3/data source/simpdata.txt", "r");

	//��ȡ������������
	fscanf(fp, "%d", &numofvertex);
	fscanf(fp, "%d", &numofedges);

	//�����ڽӱ�
	adjlist = new set<edge*>*[numofvertex];
	for (int i = 0; i < numofvertex; i++) {
		adjlist[i] = new set<edge*>;
	}
	//ʹ����������ڽӱ�
	for (int i = 0; i < numofedges; i++) {
		int v = 0;
		int w = 0;
		double weight = 0;
		fscanf(fp, "%d", &v);
		fscanf(fp, "%d", &w);
		fscanf(fp, "%lf", &weight);

		//����ڽӱ�
		adjlist[v]->insert(new edge(v, w, weight));
		adjlist[w]->insert(new edge(w, v, weight));
	}

	fclose(fp);		//�ر��ļ���



	//��ȡ������Ϣ
	//������������
	vertexarray = new vertex*[numofvertex];
	string address = "../experiment3/data source/data.txt";
	FILE* fp2 = fopen(address.c_str(), "r");
	int temp;
	fscanf(fp2, "%d%d",&temp,&temp);	//����������Ϣ
	for (int i = 0; i < numofvertex; i++) {
		int index = 0;
		int x = 0;
		int y = 0;
		fscanf(fp2, "%d%d%d", &index, &x, &y);
		vertexarray[index] = new vertex( x, y);		//�����ݼ�������
	}


}


void graph::initGraph() {
	//���ļ��ж�ȡ����
	//���ļ�
	FILE* fp = fopen("../experiment3/data source/data.txt", "r");
	fscanf(fp, "%d", &numofvertex);		//��ö�����
	fscanf(fp, "%d", &numofedges);		//��ñ���

	//����һ���ļ�������
	FILE* fp2 = fopen("../experiment3/data source/simpdata.txt", "w");

	//������д�����ļ�
	fprintf(fp2, "%d ", numofvertex);
	fprintf(fp2, "%d\n", numofedges);


	
	//��������
	//�ȴ������ж�����������
	vertex* array = new vertex[numofvertex];
	//��ȡ���е������
	for (int i = 0; i < numofvertex; i++) {
		int index;
		fscanf(fp, "%d",&index);	//��������
		fscanf(fp, "%d", &array[i].x);//��ȡx����
		fscanf(fp, "%d", &array[i].y);//��ȡy����
	}
	//�������бߵľ���
	for (int i = 0; i < numofedges; i++) {
		int v = 0;	//����v
		int w = 0;	//����w
		fscanf(fp, "%d%d", &v, &w);	//��ȡһ�������
		//����Ȩ��
		double weight=getWeight(array[v].x, array[v].y, array[w].x, array[w].y);	
		fprintf(fp2, "%d %d %lf\n", v, w, weight);	//������õ�������д�����ļ�
	}
	
	//�����ڴ�
	delete array;	//�ͷŶ��ڴ�
	fclose(fp2);	//�ر��ļ���
	fclose(fp);		//
}


double graph::getWeight(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}