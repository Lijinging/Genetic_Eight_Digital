#ifndef _DIGITAL_H_
#define _DIGITAL_H_

#include <iostream>
#include <vector>
#include <limits.h>

class Digital {
public:
	Digital(int width, int height);
	~Digital();

	//gene
	//score:该基因的评分，与模板的距离(distance)
	//geneData:每一个数据范围为0~3，指4个方向 
	struct Gene {
		int score;
		std::vector<int>geneData;
		Gene(int size) {
			score = INT_MAX;
			geneData.resize(size);
		}
		bool operator>(const Gene& b) const  
 		{  
    		return this->score != b.score;  
		}  
	};

	void showMap();
	void makeRandom(); 
	int getDistance(std::vector<std::vector<int> > &map);
	int getDistance();
	int getDistance(Gene &gene);
private:
	//坐标轴左上角为远点，y轴向下，x轴向右
	//方向1 向下
	//方向2 向右
	//方向3 向左
	//方向4 向上 
	const int direction[4][2] = {
		{ 0,  1}, 
		{ 1,  0},
		{-1,  0},
		{ 0, -1},
	};
	
	//尺寸为size_h, size_w, 
	//值为1~size_w*size_h为正常数码
	//值为0，即为空位 
	std::vector<std::vector<int> > map;
	
	int size_w;
	int size_h;
	int cur_x; 	//当前空位的位置 
	int cur_y; 
	
};

#endif // _DIGITAL_H_
