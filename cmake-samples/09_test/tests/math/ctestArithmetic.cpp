#include "../../math/arithmetic.h"
#include <iostream>
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

// Test for Arithmetic::add
void test_add() {
    check(Arithmetic::add(2, 3) == 5, "test_add", "2 + 3 == 5");
    check(Arithmetic::add(-1, 1) == 0, "test_add", "-1 + 1 == 0");
    check(Arithmetic::add(0, 0) == 0, "test_add", "0 + 0 == 0");
    check(Arithmetic::add(-5, -10) == -15, "test_add", "-5 + -10 == -15");
}

// Test for Arithmetic::multiply
void test_multiply() {
    check(Arithmetic::multiply(2, 3) == 6, "test_multiply", "2 * 3 == 6");
    check(Arithmetic::multiply(-1, 1) == -1, "test_multiply", "-1 * 1 == -1");
    check(Arithmetic::multiply(0, 100) == 0, "test_multiply", "0 * 100 == 0");
    check(Arithmetic::multiply(-5, -5) == 25, "test_multiply", "-5 * -5 == 25");
}

// Test for Rect class
void test_rect() {
    // Default constructor
    Rect r1;
    check(r1.getLength() == 0, "test_rect", "Default constructor length");
    check(r1.getHeight() == 0, "test_rect", "Default constructor height");
    check(r1.surface() == 0, "test_rect", "Default constructor surface");
    check(r1.periphery() == 0, "test_rect", "Default constructor periphery");

    // Parameterized constructor
    Rect r2({1, 2}, 10, 5);
    check(r2.getLength() == 10, "test_rect", "Parameterized constructor length");
    check(r2.getHeight() == 5, "test_rect", "Parameterized constructor height");
    check(r2.getBase().first == 1, "test_rect", "Parameterized constructor base.first");
    check(r2.getBase().second == 2, "test_rect", "Parameterized constructor base.second");

    // Surface and Periphery
    check(r2.surface() == 50, "test_rect", "Surface calculation");
    check(r2.periphery() == 30, "test_rect", "Periphery calculation");

    // Setters
    r1.setLength(20);
    r1.setHeight(10);
    check(r1.getLength() == 20, "test_rect", "Setter length");
    check(r1.getHeight() == 10, "test_rect", "Setter height");
    check(r1.surface() == 200, "test_rect", "Setter surface");
    check(r1.periphery() == 60, "test_rect", "Setter periphery");
}

int main() {
    test_add();
    test_multiply();
    test_rect();

    if (tests_failed) {
        std::cerr << "One or more arithmetic tests failed." << std::endl;
        return 1; // Indicate failure
    }

    std::cout << "All arithmetic tests passed successfully." << std::endl;
    return 0; // Indicate success
}
