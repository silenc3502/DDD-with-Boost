#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

#include "manager.h"
#include "../ui/console/ui_console.h"

std::mutex mtx;

void ui_thread() {
    print_home_ui();

    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        {
            std::lock_guard<std::mutex> lock(mtx); // 뮤텍스 락
            std::cout << "UI Thread: Processing request " << i << std::endl;
        }
    }
}

void processing_thread() {
    for (int i = 0; i < 10; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Processing Thread: Processing request " << i << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void thread_manager (void) {
    std::thread ui(ui_thread);
    std::thread processing(processing_thread);

    ui.join();
    processing.join();
}