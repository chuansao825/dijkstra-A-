#include "../header/edge.h"

edge::edge(int v, int w, double weight) {
	this->v = v;
	this->w = w;
	this->weight = weight;
}

edge::edge() {
	v = 0;
	w = 0;
	weight = INF;
}


string edge::toString() {
	string s1 = to_string(v);
	string s2 = to_string(w);
	return s1+"->"+s2;
}