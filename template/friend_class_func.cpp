#include <iostream>

template <typename T>
class myclass;

template <typename T>
void print(myclass<T> & my);

template <typename T>
myclass<T>* operator+(const myclass<T> &my1, const myclass<T> &my2);

template <typename T>
class runclass;

template <typename T>
class myclass
{
public:
    myclass(T t1, T t2): x(t1), y(t2)
    {

    }

    friend void print<T>(myclass<T> & my);
    friend myclass* operator+<T>(const myclass<T>& my1, const myclass<T>& my2);
    friend class runclass<T>;

private:
    T x;
    T y;
};

template <typename T>
void print(myclass<T> & my)
{
    std::cout << "x: " << my.x << " y: " << my.y << std::endl;
}

template <typename T>
myclass<T>* operator+(const myclass<T> &my1, const myclass<T> &my2)
{
    myclass<T> *p = new myclass<T>(my1.x+my2.x, my1.y+my2.y);
    return p;
}

template <typename T>
class runclass
{
public:
    runclass(T i): sum(i)
    {

    }

    void calcSum(const myclass<T> &my)
    {
        sum += my.x + my.y;
    }

    void cleanSum()
    {
        sum = 0;
    }

    void printSum()
    {
        std::cout << "sum: " << sum << std::endl;
    }

private:
    T sum;
};

int main()
{
    myclass<int> my1(19,29);
    print(my1);
    myclass<int> my2(30,90);
    print(my2);

    myclass<int> *pclass = my1 + my2;
    print(*pclass);
    delete pclass;

    runclass<int> run1(0);
    run1.calcSum(my1);
    run1.calcSum(my2);
    run1.printSum();
    run1.cleanSum();
    run1.printSum();

    system("pause");
    return 0;
}
