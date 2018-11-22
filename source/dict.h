#pragma once
#ifndef _DICT_
#define _DICT_

#include"HashTeble/HashTable.h"





template<class T>
class NativeDict{
public:
	NativeDict();
	void put(std::string key, T value);
	bool is_key(std::string key);
	T get(std::string key);
	T &operator[](string key);
	
	~NativeDict();
private:
	T *arrvalue;
	HashTable *hash;
	int size=1000;
};


#include"dict.ipp"

#endif // !_DICT_