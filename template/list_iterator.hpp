#pragma once

template<typename T> class list;

template<typename N>
class list_iterator {
	N *pos;
	template<typename T> friend class list;
	int zero = 0;
public:
	typedef typename N::value_type value_type;
	typedef typename N::reference_type reference_type;
	typedef typename N::const_reference_type const_reference_type;

	typedef list_iterator self_type;

	list_iterator() : pos(0) {}
	list_iterator(N *_pos) : pos(_pos) {}
	bool operator != (const self_type &right) const {
		return pos != right.pos;
	}

	bool operator == (const self_type &right) const {
		return pos == right.pos;
	}

	self_type& operator ++ () {
		if(pos)
			pos = pos->next;
		return *this;
	}

	reference_type operator * () {
		if(pos)
			return pos->value;
		return zero;		
	}
};



