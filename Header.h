#ifndef __SOURCE_H_INCLUDED__
#define __SOURCE_H_INCLUDED__

#include <iostream>
#include <opencv2/opencv.hpp>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace cv;
using namespace ml;

void *matrixArray(Mat matrixName, string fileN)
{
	fstream inFile;
	stringstream fn;
	fn << "img/" << fileN << ".dat";
	inFile.open(fn.str(), ios::in | ios::app | ios::binary);

	for (int i = 0; i < matrixName.rows; i++) {
		for (int j = 0; j < matrixName.cols; j++) {
			if (matrixName.rows - i == 1 && matrixName.cols == j + 1) inFile << (int)(matrixName.at<uchar>(i, j)) / 255;
			else inFile << (int)(matrixName.at<uchar>(i, j)) / 255;
		}
	}
	inFile.close();
	return 0;
}

char *matrixAbs()
{
	ifstream matrixAb;
	//char fname[] =  "img/data.dat";
	matrixAb.open("img/data.dat", ifstream::binary);
	matrixAb.seekg(0, matrixAb.end);
	int buffSize = matrixAb.tellg();
	matrixAb.seekg(0, matrixAb.beg);

	char *lines = new char[buffSize];
	matrixAb.read(lines, buffSize);
	cout << lines << endl;
	return lines;
	delete[] lines;
}


#endif