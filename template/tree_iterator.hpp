#pragma once

template<typename N>
class tree_iterator {
	const N *pos;
public:
	typedef typename N::value_type value_type;
	typedef typename N::const_reference_type const_reference_type;
	typedef tree_iterator self_type;

	tree_iterator() : pos(0) {}
	tree_iterator(const N *_pos) : pos(_pos) {}

	bool operator == (const self_type &right) const {
		return pos == right.pos;
	}

	self_type& operator ++ () {
		if(pos) {
			if(pos->right) {
				pos = pos->right;
				while(pos->left) pos = pos->left;
			}
			else {
				while((pos->parent) &&
					  (pos->parent->right == pos))
					pos = pos->parent;
				pos = pos->parent;
			}
		}

		return *this;
	}

	const_reference_type operator * () const {
			return pos->value;
	}
};

template<typename N>
bool operator != (const tree_iterator<N> &left, const tree_iterator<N> &right)
{
	return !(left == right);
}
