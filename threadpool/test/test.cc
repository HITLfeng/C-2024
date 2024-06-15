
#include <thread>
using namespace std;

typedef ThreadPool ThreadPool;

int main() {
    ThreadPool pool;
    pool.setMode(fixed(default)|cached);
    pool.start();

    return 0;
}