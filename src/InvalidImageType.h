/**
 * \class InvalidImageType
 *
 * This class is used to generate an exception if an image's type does not match the excepted type.
 * 
 */

#include<string>

using namespace std;

class InvalidImageType {
public:
	const char * _actual_type; ///< image's type
	const string _excepted_type; ///< image's excepted type

	InvalidImageType(char * actual_type, string excepted_type) :
			_actual_type(actual_type), _excepted_type(excepted_type) {
	}
};
