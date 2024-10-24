#include "twilight/thread_pool.h"
#include <iostream>

void exampleTask(int n) {
    std::cout << "Processing task " << n << std::endl;
}

int main() {
    ThreadPool pool(4);
    
    for (int i = 0; i < 8; ++i) {
        pool.enqueue(exampleTask, i);
    }

    return 0;
}
