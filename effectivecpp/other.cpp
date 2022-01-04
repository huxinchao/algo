#include <iostream>
using namespace std;

class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc);
class GameCharacter {
	typedef int (*HealthCalcFunc)(const GameCharacter&);
	explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf) {}
	int healthValue() const {
		return healthFunc(*this);
	}
private:
	HealthCalcFunc healthFunc;
};

int main()
{
	
	
}
