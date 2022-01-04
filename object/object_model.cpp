#include <iostream>
using namespace std;

class Point {
public:
	Point(float xval) {
		_x = xval;
	};
	virtual ~Point() {
		cout << "~P" << endl;
	};

	float x() const;
	static int PointCount() {
		return _point_count;
	};

protected:

	virtual ostream& print(ostream& os) const {
		return os;
	};
	float _x;
	static int _point_count;
};

class DPoint : public Point {
public:
	DPoint(float x) : Point(x) {}
	~DPoint() {
		cout << "~DP" << endl;
	}
};

int main() {
	Point *dp = new DPoint(3);
	delete dp;
}
