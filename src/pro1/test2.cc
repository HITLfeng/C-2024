#include <iostream>
#include "../utils/utils.h"
using namespace std;

#define ADD(x, y) ((x) + (y))

void test1()
{
    int x = ADD(10, 20);
    cout << "x = " << x << endl;

    int arr[] = {1, 2, 3, 4, 5};
    cout << ELE_SIZE(arr) << endl;

    for (auto e : arr)
        cout << e << endl;
            int a = 10;
    int &b = a;
    int c = 20;
    b = c;
    cout << "b = " << b << endl;
    cout << "a = " << a << endl;
}

class A {
public:
    void AP() {
        cout << "AP" << endl;
    }

    void AC() {
        cout << "AC" << endl;
    }
};

void test2()
{
    A().AP();
    A().AC();

    cout << sizeof(A) << endl;
}

int main()
{
    test2();
    return 0;
}