#include <iostream>
#include <stack>

using std::cout;
using std::endl;


template<typename Stack>
class stack_iterator
{
public:
	typedef typename Stack::value_type value_type;
	typedef typename Stack::reference reference;

private:
	Stack &s;
	value_type *pos;

public:

	stack_iterator(Stack &_s) : s(_s), pos(_s.size() ? &_s.top() : 0) {}
	reference operator * () const {
		return *pos;
	}

	stack_iterator& operator ++ () {
		s.pop();
		pos = s.size() ? &s.top() : 0;
		return *this;
	}

	bool operator == (const stack_iterator &rh) const {
		return pos == rh.pos;
	}

	bool operator != (const stack_iterator &rh) const {
		return pos != rh.pos;
	}
};

int main() {
	A a;
	++a;
}
