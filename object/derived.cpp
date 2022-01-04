#include <iostream>

using std::cout;
using std::endl;

class ios {
public:
	ios() {
		cout << "create ios" << endl;
	}
	~ios() {
		cout << "destroy ios" << endl;
	}
	void print_adr() {
		cout << this << endl;
	}
};

class istream : virtual public ios {
	
};

class ostream : virtual public ios {
	
};

class iostream : public istream, public ostream {
public:
	void print_adr() {
		istream::print_adr();
		ostream::print_adr();
	}
	
};

ios create_ios() {
	ios s;
	return s;
}

int main() {
	create_ios();
}
