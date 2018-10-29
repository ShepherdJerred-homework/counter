#include <thread>
#include <iostream>

using std::thread;
using std::cin;
using std::cout;
using std::endl;
using std::chrono::seconds;
using std::this_thread::sleep_for;

bool shouldContinue = true;

void counterLoop() {
    int counter = 0;
    while (shouldContinue) {
        counter += 1;
        cout << counter << endl;
        sleep_for(seconds(1));
    }
}

int main() {
    thread t (counterLoop);
    cin.ignore();
    shouldContinue = false;
    t.join();
}