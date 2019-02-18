#include "vdb.h"
#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES

#include <math.h>
#include <vector>

double drand() {
#ifdef __APPLE__
	return arc4random() / (double) (0xFFFFFFFF);
#else
	return rand() / (double) RAND_MAX;
#endif
}

struct Point
{
	double x;
	double y;
};

void visualize_points(std::vector<Point>& pnts, float r, float g, float b)
{
	vdb_begin();
	vdb_color(r, g, b);
	for (int i = 0; i < pnts.size(); i++)
	{
		vdb_point(pnts[i].x, pnts[i].y, 0);
	}
	vdb_end();
}

void visualize_points(std::vector<double>& pnts, float r, float g, float b)
{
	vdb_begin();
	vdb_color(r, g, b);
	for (int i = 0; i < pnts.size()/2; i++)
	{
		vdb_point(pnts[2*i], pnts[2*i+1], 0);
	}
	vdb_end();
}

int main() {
	std::vector<Point> pnts = { {0,0},{1,1} };
	std::vector<double> pnts1 = { 0,0,1,1};
	
	char buffer[50];
	vdb_color(1,0,1);
	for(int i = 0; i < 100; i++) {
		double s0 = drand();
		double s1 = drand();
		
		double r = s0;
		double t = 2 * M_PI * s1;
		
		double x = r * sin(t);
		double y = r * cos(t);

		vdb_label("one");
		sprintf(buffer, "%d-1", i);
		vdb_text(x, y, 0, buffer);
		vdb_point(x, y, 0);
		r = s0 * s0;
		x = r * sin(t);
		y = r * cos(t);
		vdb_label("two");
		sprintf(buffer, "%d-2", i);
		vdb_text(x, y, 1, buffer);
		vdb_point(x, y, 1);
		r = sqrt(s0);
		x = r * sin(t);
		y = r * cos(t);
		vdb_label("three");
		sprintf(buffer, "%d-3", i);
		vdb_text(x, y, 2, buffer);
		vdb_point(x, y, 2);
		
	}
	return 0;
}
