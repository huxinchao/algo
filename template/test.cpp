#include "test.h"

template<typename T>
const T& func(const T& v) {
	return v;
}	

template const int& func(const int &);



	
