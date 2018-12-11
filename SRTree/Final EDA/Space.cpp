#include "pch.h"
#include "Space.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Rectangle::Rectangle(Point u) {
	mins = u.x;
	maxs = u.x;
}

Rectangle::Rectangle() {}

Rectangle::Rectangle(Point u, Point v) {
	mins.assign(u.x.size(), 0.0);
	maxs.assign(u.x.size(), 0.0);
	for (size_t i = 0; i < u.x.size(); ++i) {
		if (u.x[i] < v.x[i]) {
			mins[i] = u.x[i];
			maxs[i] = v.x[i];
		}
		else {
			mins[i] = v.x[i];
			maxs[i] = u.x[i];
		}
	}
}

void Rectangle::adjust(Point u) {
	for (size_t i = 0; i < mins.size(); ++i) {
		if (u.x[i] < mins[i])
			mins[i] = u.x[i];
		if (u.x[i] > maxs[i])
			maxs[i] = u.x[i];
	}
}

Point Rectangle:getCenter(){
	vector<float> x(mins.size(),0);
	for(size_t i=0;i<mins.size();++i){
		x[i]=(maxs[i]-mins[i])/2;
	}
	return Point(mins.size(),x);
}

Rectangle::~Rectangle() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Sphere::Sphere() {}

Sphere::Sphere(Point u, float R): centroid(u),r(R) {

}

void Sphere::adjust(Point u) {

}

Sphere::~Sphere() {

}
