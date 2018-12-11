#include "pch.h"
#include "SRTree.h"
#include <iostream>

SRTree::SRTree(int m, int d):M(m),D(d),reinserted(false),P(this){	

}

SRTree::SRTree(int m, int d, SRTree* p) : M(m), D(d), reinserted(false), P(p) {

}

SRTree::~SRTree(){
	
}

SRTree* SRTree::ChooseLeaf(Point E) {
	float maxDistance = 10000000, distance;
	SRTree *N;
	for (size_t i = 0; i < branches.size(); ++i) {
		distance = euclidean(branches[i]->S.centroid, E);
		if (maxDistance > distance) {
			maxDistance = distance;
			N = branches[i];
		}
	}
	if (N->branches.size() == 0)
		return N;
	else
		return N->ChooseLeaf(E);
}

void SRTree::SplitLeaf(){
	if (P->branches.size() > M) {
		if (P->P == P) {
			
		}
		else {
			
		}
	}
}

void SRTree::Reinsert() {
	priority_queue<vector<float>,float> distances;
	Point center=R.getCenter();
	for(size_t i=0;i<points.size();++i){
		distances.push(euclidean(points[i],center));
	}
}

void SRTree::Insert(Point E) {
	if (D == E.D) {
		if (branches.size() == 0) {
			points.push_back(E);
			if (points.size() == 0) {
				R = Rectangle(E);
				S = Sphere(E, 0.0);
			}
			else {
				R.adjust(E);
				S.adjust(E);
				if (points.size() > M) {
					SRTree* N = new SRTree(M, D,this);
					N->points = points;
					N->R = R;
					N->S = S;
					points.clear();
					branches.push_back(N);
					N->SplitLeaf();
				}
			}
		}
		else {
			SRTree* N = ChooseLeaf(E);
			N->points.push_back(E);
			if (N->points.size() > M) {
				if (N->reinserted)
					N->SplitLeaf();
				else
					N->Reinsert();
			}
		}
	}
}
