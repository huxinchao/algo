#include <iostream>
#include <memory>
#include <vector>
#include <set>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::set;


class Person {
public:
	int num;
	virtual ~Person() {};
	virtual int getNum() = 0;
	static shared_ptr<Person> create(int n);
};

class Soldier : public Person {

public:
	Soldier(int n) {
		num = n;
	}
	int getNum() {
		return num;
	}
};

shared_ptr<Person> Person::create(int n) {
	return shared_ptr<Person>(new Soldier(n));
}

int main() {
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);

	auto ite = s.begin();
    s.erase(ite);

   




	
	
}
