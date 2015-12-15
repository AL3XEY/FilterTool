/**
 * \class ImagePGM
 *
 * This class inherits Image.
 * This class is used to create a PGM image object with the description of all of its specific functions.
 * 
 */


#ifndef IMAGEPGM_H
#define IMAGEPGM_H

#include "Image.h"

using namespace std;

class ImagePGM: public Image {

public:
	/**
     	*  \brief Default constructor
       	*  Image class default constructor
     	*/
	ImagePGM();
	
	/**
     	*  \brief Constructor
     	*  Image class constructor
     	*  \param x and y are respectively the image's width and the image's lenght 
    	*/
	ImagePGM(int x, int y);
	ImagePGM(int x, int y, byte *tab);
	int getIndex(int x, int y);
	int matrixSize();

	/**
      	* \param threshold is threshold used for the sobel filter
     	* \return a PGM image on which Sobel filter has been applied
        * This method is used to apply Sobel filter.
        */
	ImagePGM sobel(int threshold);
	
	/**
     	* \return a PGM image on which a mean filter has been applied
        * This method is used to apply mean filter.
        */
	ImagePGM mean();

};

#endif
