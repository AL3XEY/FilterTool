#include"Image.h"
#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<string>

using namespace std;

Image::Image(int x, int y) {
	_width = x;
	_height = y;
	_size = x * y;
	_max_level = 255;
	_matrix = new byte[_size];
	for (int i = 0; i < _size; i++) {
		_matrix[i] = 0;
	}
}

char *readitem(FILE *file, char *buffer) {
	char *aux;
	int k;

	k = 0;
	aux = buffer;
	while (!feof(file)) {
		*aux = fgetc(file);
		switch (k) {
		case 0:
			if (*aux == '#')
				k = 1;
			if (isalnum(*aux))
				k = 2, aux++;
			break;
		case 1:
			if (*aux == 0xA)
				k = 0;
			break;
		case 2:
			if (!isalnum(*aux)) {
				*aux = 0;
				return buffer;
			}
			aux++;
			break;
		}
	}
	*aux = 0;
	return buffer;
}

int Image::load(std::string filename) throw (InvalidImageType) {

	FILE *file;
	char *buffer;
	int i;

	buffer = (char*) calloc(80, sizeof(char));
	file = fopen(filename.c_str(), "rb");
	if (file == NULL) {
		cerr << "Can not open " << filename << "in Image::Load\n";
	}

	readitem(file, buffer);
	if (strcmp(buffer, _type.c_str()) != 0) {
		throw(InvalidImageType(buffer, _type));
	}

	_width = atoi(readitem(file, buffer));
	_height = atoi(readitem(file, buffer));
	_size = _width * _height;
	_max_level = atoi(readitem(file, buffer));
	_matrix = new byte[matrixSize()];

	for (i = 0; i < matrixSize(); i++) {
		fread(&_matrix[i], sizeof(byte), 1, file);
	}

	fclose(file);
	free(buffer);

	return 0;
}

int Image::save(std::string filename) {

	FILE *file;
	char buffer[80];

	file = fopen(filename.c_str(), "wb");
	if (file == NULL) {
		cerr << "Can not save " << filename << " in Image::Load\n";
		return -1;
	}

	sprintf(buffer, "%s\n%d %d\n255\n", _type.c_str(), _width, _height);
	fwrite(buffer, strlen(buffer), 1, file);

	for (int i = 0; i < matrixSize(); i++)
		fwrite(&_matrix[i], sizeof(byte), 1, file);

	fclose(file);

	return 0;
}

