#include "../../helper/util.h"
#include <iostream>
#include <sstream>
#include <string>

// Global flag to track test failures
bool tests_failed = false;

// Custom assertion function
void check(bool condition, const std::string& test_name, const std::string& message) {
    if (!condition) {
        std::cerr << "FAILED: " << test_name << " - " << message << std::endl;
        tests_failed = true;
    }
}

// Test for Util::print(const char*)
void test_print_string() {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    const char* test_str = "Hello, World!";
    Util::print(test_str);

    std::cout.rdbuf(old);

    check(buffer.str() == "Util::print: Hello, World!\n", "test_print_string", "Output did not match expected string.");
}

// Test for Util::print(int)
void test_print_int() {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    int test_int = 123;
    Util::print(test_int);

    std::cout.rdbuf(old);

    check(buffer.str() == "Util::print: 123\n", "test_print_int", "Output did not match expected integer string.");
}

int main() {
    test_print_string();
    test_print_int();

    if (tests_failed) {
        std::cerr << "One or more helper tests failed." << std::endl;
        return 1; // Indicate failure
    }

    std::cout << "All helper tests passed successfully." << std::endl;
    return 0; // Indicate success
}
