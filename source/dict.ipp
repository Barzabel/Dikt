



template<class T>
NativeDict<T>::NativeDict() {
	this->hash = new HashTable(size);
	this->arrvalue = new T[size];


}


template<class T>
T &NativeDict<T>::operator[](string key) {
	if (this->is_key(key))
	{
	}
	else
	{
		this->put(key, NULL);
	}	
	int index = this->hash->find(key);
	for (int i = 0; i < this->hash->get_step(); i++)
	{
		if (this->hash->at(index + this->hash->get_step()*i) == key)
		{
			return this->arrvalue[index + this->hash->get_step()*i];
		}
	}
}



template<class T>
void NativeDict<T>::put(std::string key, T value) {
	int index2 = this->hash->find(key, true);

	if (index2 != (-1)) {
		int index = this->hash->find(key);
		for (int i = 0; i < this->hash->get_step(); i++)
		{
			if(this->hash->at(index + this->hash->get_step()*i)==key)
			{
				this->arrvalue[index + this->hash->get_step()*i] = value;
				return;
			}
		}
		
	}

	int index = this->hash->find(key, false);
	if(index>=0)
	{
		this->hash->put(key);
		this->arrvalue[index] = value;
	}
}




template<class T>
bool  NativeDict<T>::is_key(std::string key) {
	int index = this->hash->find(key, true);

	if (index == (-1)) {
		return false;
	}
	return true;

}

template<class T>
T NativeDict<T>::get(std::string key) {
	int index = this->hash->find(key, true);
	if (index == (-1)) {
		return NULL;
	}
	return this->arrvalue[index];
}
 
template<class T>
NativeDict<T>::~NativeDict() {

	delete[] this->arrvalue;
	delete this->hash;
}