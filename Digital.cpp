#include "Digital.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits.h>

#define random(a) (rand()%a)

using std::cout;
using std::endl;

Digital::Digital(int width, int height)
{
	size_w = width;
	size_h = height;
	cur_x = 0;
	cur_y = 0; 
	map.clear();
	for (int i = 0 ; i < height; ++i) {
		std::vector<int> list(width);
		map.push_back(list);
	}
	makeRandom();
}

Digital::~Digital()
{
	
}

void Digital::makeRandom()
{
	printf("makeRandom\n");
	int size = size_h * size_w;
	int loc = 0, x = 0, y = 0;
	std::srand((unsigned)time(NULL));
	//确定空位的位置
	loc = random(size);
	cur_y = loc / size_w;
	cur_x = loc % size_w; 
	map[cur_y][cur_x] = 0;
	//确定1~(size-1)的位置 
	for (int i = 1 ; i < size ; ++i) {
		do {
			loc = random(size);
			y = loc / size_w;
			x = loc % size_w;
		} while(map[y][x] > 0);
		map[y][x] = i;
	}
}

int Digital::getDistance(std::vector<std::vector<int> > &map)
{
	long distance = 0;
	int x0 = 0, y0 = 0;
	for (int y = 0 ; y < size_h ; ++y) {
		for (int x = 0 ; x < size_w ; ++x) {
			int &val = map[y][x];
			if (val > 0) {
				x0 = (val - 1) % size_w;
				y0 = (val - 1) / size_w;
				distance +=  (abs(x - x0) + abs(y - y0));
				//int t = (abs(x - x0) + abs(y - y0));
				//printf("(%d,%d) val=%d -> (%d,%d) dis=%d\n", x,y,val,x0,y0,t);
			}
		}
	}
	return distance;
}

int Digital::getDistance()
{
	getDistance(this->map);
}

int Digital::getDistance(Gene &gene)
{
	std::vector<std::vector<int> > nmap = this->map;
	return 0;
}

void Digital::showMap()
{
	printf("show map:(%d, %d)\n", size_w, size_h);
	char space = (size_w * size_h > 10) ? '\t' : ' ';
	for (int y = 0 ; y < size_h ; ++y) {
		for (int x = 0 ; x < size_w ; ++x) {
			cout << map[y][x] << space;
		}
		cout << std::endl;
	} 
	cout << endl;
	printf("Distance = %d\n", getDistance());
} 

