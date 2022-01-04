#include <iostream>
using namespace std;

class some_value;

typedef int (some_value::*some_value_mfp)(int);

template<some_value_mfp func>
int call(some_value &value, int op) {
	return (value.*func)(op);
}

class some_value {
	int value;
	template<typename T0, typename T1>
	friend class fbi;
public:
	some_value(int _value) : value(_value) {}
	int add_by(int op) {
		return value += op;
	}

	int sub_by(int op) {
		return value -= op;
	}

	int mul_by(int op) {
		return value *= op;
	}
};

template<typename T0, typename T1>
class fbi {
	T0 a;
	T1 b;
public:
	int getValue(const some_value &v) {
		return v.value;
	}
};



int main() {
	using namespace std;
	some_value v0(0);
	cout << call<&some_value::sub_by>(v0, 1) << endl;
	fbi<int,int> f;
	cout << f.getValue(v0) << endl;
}


	




	
