/**
 * \class ImagePPM
 *
 * This class inherits Image.
 * This class is used to create a PPM image object with the description of all of its specific functions.
 * 
 */

#ifndef IMAGEPPM_H
#define IMAGEPPM_H

#include "Image.h"
#include "ImagePGM.h"

using namespace std;

class ImagePPM: public Image {

public:
	/**
     	*  \brief Default constructor
       	*  ImagePPM class default constructor
     	*/
	ImagePPM();

	/**
     	*  \brief Constructor
     	*  Image class constructor
     	*  \param x and y are respectively the image's width and the image's lenght 
    	*/
	ImagePPM(int x, int y);
	int getIndex(int x, int y);
	int matrixSize();
	
	/**
     	* \return a PGM image in grey scale
        * This method is used to generate a PGM image from a PPM image.
        */
	ImagePGM convertToGrayscale();

};

#endif
