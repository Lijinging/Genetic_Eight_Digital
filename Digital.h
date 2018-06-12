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
	//score:�û�������֣���ģ��ľ���(distance)
	//geneData:ÿһ�����ݷ�ΧΪ0~3��ָ4������ 
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
	//���������Ͻ�ΪԶ�㣬y�����£�x������
	//����1 ����
	//����2 ����
	//����3 ����
	//����4 ���� 
	const int direction[4][2] = {
		{ 0,  1}, 
		{ 1,  0},
		{-1,  0},
		{ 0, -1},
	};
	
	//�ߴ�Ϊsize_h, size_w, 
	//ֵΪ1~size_w*size_hΪ��������
	//ֵΪ0����Ϊ��λ 
	std::vector<std::vector<int> > map;
	
	int size_w;
	int size_h;
	int cur_x; 	//��ǰ��λ��λ�� 
	int cur_y; 
	
};

#endif // _DIGITAL_H_
