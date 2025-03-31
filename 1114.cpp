#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;

void printFirst() { cout << "first"; }
void printSecond() { cout << "second"; }
void printThird() { cout << "third"; }

void runBasicTest() {
    cout << "Basic Test: ";
    Foo foo;

    thread t1(&Foo::first, &foo, printFirst);
    thread t2(&Foo::second, &foo, printSecond);
    thread t3(&Foo::third, &foo, printThird);

    t1.join();
    t2.join();
    t3.join();

    cout << endl;
}

void runRandomOrderTest() {
    cout << "Random Order Test: ";
    Foo foo;
    vector<thread> threads;

    threads.push_back(thread(&Foo::first, &foo, printFirst));
    threads.push_back(thread(&Foo::second, &foo, printSecond));
    threads.push_back(thread(&Foo::third, &foo, printThird));

    random_shuffle(threads.begin(), threads.end()); // Randomize thread start order

    for (auto &t : threads) {
        t.join();
    }

    cout << endl;
}

void runMultipleInstancesTest() {
    cout << "Multiple Instances Test:\n";
    runBasicTest();
    runBasicTest(); // Running twice to ensure instance independence
}

int main() {
    runBasicTest();
    runRandomOrderTest();
    runMultipleInstancesTest();
    return 0;
}
