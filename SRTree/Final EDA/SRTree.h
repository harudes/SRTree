#pragma once
#include "Space.h"
#include <queue>

class SRTree
{	
	int M, D;
	bool reinserted;
	vector<SRTree*> branches;
	vector<Point> points;
	Rectangle R;
	Sphere S;
	SRTree *P;
	SRTree* ChooseLeaf(Point E);
	void SplitLeaf();
	void Reinsert();
public:
	SRTree(int m, int d);
	SRTree(int m, int d, SRTree* p);
	~SRTree();
	void Insert(Point E);
};

