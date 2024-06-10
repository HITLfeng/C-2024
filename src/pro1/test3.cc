#include <iostream>
#include "../utils/utils.h"
#include "../utils/date.h"
using namespace std;

void test1()
{
    Date d;
    d.ShowDate();

    Date d2(2025, 5, 20);
    d2.ShowDate();

    Date d3(d2);
    d3.ShowDate();

    cout << (d > d2 == true ? "d 日期大于 d2 日期" : "d 日期不大于 d2 日期") << endl;
}

class AA
{
public:
    AA(int x) : aa(x) {}
    // explicit AA(int x) : aa(x) {}
    void Show()
    {
        cout << "aa = " << aa << endl;
    }

private:
    int aa;
};

template<typename T>
void Swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

int main()
{
    // test1();
    // AA aa = 10;
    // aa.Show();
    int a = 100;
    int b = 999;
    Swap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    string s = "www.hello.com";
    size_t pos = s.find(".");

    return 0;
}