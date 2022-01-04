#include <iostream>

template<template<typename>  class Func, typename T>
void foreach(T array[], unsigned size)
{
    Func<T> func;
    for (unsigned i = 0; i < size; ++i) func(array[i]);
}

template<typename T>
struct inc {
	void operator()(T &v) const{
		++v;
	}
};

template<typename T, T v0, T v1>
void fun(T v2) {
	
}

int main() {
	int array[] = {1,2,3,4,5,6,7,8};
	foreach<inc>(array,8);

	fun<int,1,2>(3);

}

	

