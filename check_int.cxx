
#include <iostream>
#include <thread>

const int N_SECONDS = 10;

void check_every_sec(int &int_to_check) {
    int prev_int = 0;
    for (int i = 0; i < N_SECONDS; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if (int_to_check != prev_int) std::cout << int_to_check << "\n";
        prev_int = int_to_check;
    }
}

int main() {
    int the_int = 0;
    int prev_int = 0;
    std::thread t{check_every_sec, std::ref(the_int)};
    for (int i = 0; i < 1000*N_SECONDS; ++i) {
        the_int = i;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    t.join();
    return 0;
}

