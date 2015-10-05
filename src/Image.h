/**
 * \class Image
 *
 * This class is used to gather all neccesary attritubes to define a Image (PPM or PGM)
 * as well as functions.
 * 
 */


#ifndef IMAGE_H
#define IMAGE_H

#include<string>
#include"InvalidImageType.h"

typedef unsigned char byte;

using namespace std;

class Image {

protected:
	string _type; ///< image's type (ppm or pgm)
	int _width; ///< image's width
	int _height; ///< image's height
	int _size; ///< size of the one dimension matrix that contains all image pixels'informations
	int _max_level; ///< max value of grey level (PGM) or color level (PPM)
	byte *_matrix; ///< one dimension matrix that contains all image pixels' informations
public:
	/*!
     	*  \brief Default constructor
       	*  Image class default constructor
     	*/
	Image() {};

	/*!
     	*  \brief Constructor
     	*  Image class constructor
     	*  \param x and y are respectively the image's width and the image's lenght 
    	 */
	Image(int x, int y);

	/** 
	* \brief Load an image
      	* \param filename which is the image's name
     	* \return 0 if everything is right and throw an InvalidImageType if something is wrong
      	* 
        * This method is used to load a image ".ppm" or ".pgm".
        */
	int load(std::string filename) throw (InvalidImageType);

	/** 
	* \brief Save an image
      	* \param filename which is the image's name
     	* \return 0 if everything is right and return -1 on the contrary
	*
        * This method is used to save an image ".ppm" or ".pgm".
        */
	int save(std::string filename);

	/** 
      	* \param x and y are pixel's coordinates in a two dimension matrix
     	* \return index of the pixel in one dimension matrix
        * This method is used to get the pixel's one dimension matrix index from its two dimension coordinates.
        */
	virtual int getIndex(int x, int y)=0;

	/** 
     	* \return the size of the one dimension matrix whitch is different for PPM and PGM image
        * This method is used to know the image matrix's size.
        */
	virtual int matrixSize()=0;

};

#endif
