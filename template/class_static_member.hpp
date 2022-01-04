template<typename T>
struct the_class {
	static int id;
	the_class() { ++id; }
};

template<typename T> int the_class<T>::id = 0;
