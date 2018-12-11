#pragma once
#include "Point.h"

class Space
{
public:
	virtual void adjust(Point u)=0;
};

class Rectangle : public Space {
	
public:
	vector<float> mins;
	vector<float> maxs;
	Rectangle();
	Rectangle(Point u); 
	Rectangle(Point u, Point v);
	void adjust(Point u);
	Point getCenter();
	~Rectangle();
};

class Sphere : public Space {
	
public:
	Point centroid;
	float r;
	Sphere();
	Sphere(Point u, float R);
	void adjust(Point u);
	~Sphere();
};
