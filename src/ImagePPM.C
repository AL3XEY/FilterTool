#include"ImagePPM.h"
#include"ImagePGM.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<string.h>
#include<stdlib.h>
#include<string>

using namespace std;

ImagePPM::ImagePPM() {
	_type = "P6";
}

ImagePPM::ImagePPM(int x, int y) :
		Image(x, y) {
	_type = "P6";
	_size = _width * _height;// * 3;
}

int ImagePPM::getIndex(int x, int y) {

	return (y * _width + x);
}

int ImagePPM::matrixSize() {
	return _size * 3;
}

ImagePGM ImagePPM::convertToGrayscale() {

	byte newTab[_size];
	byte moyenne = 0;
	int iterator = 0;

	for (int i = 0; i < matrixSize() - 2; i += 3) {
		moyenne = (_matrix[i] + _matrix[i + 1] + _matrix[i + 2]) / 3;
		newTab[iterator] = moyenne;
		iterator++;
	}

	ImagePGM img(_width, _height, newTab);
	return img;

}
