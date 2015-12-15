#include"ImagePGM.h"
#include<string>
#include<cmath>

using namespace std;

ImagePGM::ImagePGM() {
	_type = "P5";
}

ImagePGM::ImagePGM(int x, int y) :
		Image(x, y) {
	_type = "P5";
}

ImagePGM::ImagePGM(int x, int y, byte *tab) :
		Image(x, y) {
	_type = "P5";
	_matrix = new byte[_size];
	for (int i = 0; i < _size; i++)
		_matrix[i] = tab[i];
}

int ImagePGM::getIndex(int x, int y) {

	return (y * _width + x);
}

int ImagePGM::matrixSize() {
	return _size;
}

ImagePGM ImagePGM::sobel(int threshold) {

	int sobelx[3][3] = { { -1, -2, -1 }, { 0, 0, 0 }, { 1, 2, 1 } };
	int sobely[3][3] = { { -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 } };
	int gx = 0, gy = 0;
	int g;
	byte newTab[_size];
	byte tmp;

	for (int i = 1; i < _width - 1; i++) {
		for (int j = 1; j < _height - 1; j++) {
			gx = (sobelx[0][0] * _matrix[getIndex(i - 1, j - 1)]
					+ sobelx[0][1] * _matrix[getIndex(i, j - 1)]
					+ sobelx[0][2] * _matrix[getIndex(i + 1, j - 1)]
					+ sobelx[1][0] * _matrix[getIndex(i - 1, j)]
					+ sobelx[1][1] * _matrix[getIndex(i, j)]
					+ sobelx[1][2] * _matrix[getIndex(i + 1, j)]
					+ sobelx[2][0] * _matrix[getIndex(i - 1, j + 1)]
					+ sobelx[2][1] * _matrix[getIndex(i, j + 1)]
					+ sobelx[2][2] * _matrix[getIndex(i + 1, j + 1)]);

			gy = (sobely[0][0] * _matrix[getIndex(i - 1, j - 1)]
					+ sobely[0][1] * _matrix[getIndex(i, j - 1)]
					+ sobely[0][2] * _matrix[getIndex(i + 1, j - 1)]
					+ sobely[1][0] * _matrix[getIndex(i - 1, j)]
					+ sobely[1][1] * _matrix[getIndex(i, j)]
					+ sobely[1][2] * _matrix[getIndex(i + 1, j)]
					+ sobely[2][0] * _matrix[getIndex(i - 1, j + 1)]
					+ sobely[2][1] * _matrix[getIndex(i, j + 1)]
					+ sobely[2][2] * _matrix[getIndex(i + 1, j + 1)]);
            g = sqrt(gx * gx + gy * gy);
            //uncomment this to see a binary image (black and white)
            /*if (g > threshold) {
            	tmp = 255;
            } else {
            	tmp = 0;
            }*/
            //comment this to see a grayscaled image
            tmp = g/8;
            newTab[getIndex(i, j)] = tmp;
        }
	}
	ImagePGM img(_width, _height, newTab);
	return img;
}

ImagePGM ImagePGM::mean() {
	int g;
	byte newTab[_size];
	byte tmp;

	for (int i = 1; i < _width - 1; i++) {
		for (int j = 1; j < _height - 1; j++) {
			g = ( _matrix[getIndex(i - 1, j - 1)]
					+  _matrix[getIndex(i, j - 1)]
					+  _matrix[getIndex(i + 1, j - 1)]
					+  _matrix[getIndex(i - 1, j)]
					+  _matrix[getIndex(i, j)]
					+  _matrix[getIndex(i + 1, j)]
					+  _matrix[getIndex(i - 1, j + 1)]
					+  _matrix[getIndex(i, j + 1)]
					+  _matrix[getIndex(i + 1, j + 1)]);

            	tmp = g/9;
            	newTab[getIndex(i, j)] = tmp;
        	}
	}
	ImagePGM img(_width, _height, newTab);

	return img;
}
