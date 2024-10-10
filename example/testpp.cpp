#include <vector>

#define TEST_WO_GLOBALS
#include "quin.h"

/* class to test */

class Test {
public:
    Test(int a) : a(a), b(0) {  }

    Test operator + (const Test &opp) const {
        return Test{ a + opp.a };
    }
    bool operator == (const Test &opp) const {
        return a + b == opp.a + opp.b;
    }

    void set_b(int b) { this->b = b; }
    int sum() const { return a + b; }
private:
    const int a;
    int b;
};

/* ==============================
 *
 * Test suite suite_basic
 *
 ================================ */

TEST_CASE(test_1)
    Test t(1);
    t.set_b(5);
    TEST_REQUIRE(t.sum() == 6);
TEST_CASE_END()

TEST_CASE(test_2)
    std::vector t = { { 1, 2, 3 } };
    TEST_REQUIRE(t[0] + t[1] == t[2]);
TEST_CASE_END()

TEST_CASE(test_3)
    Test t1(5);
    t1.set_b(4);
    Test t2(t1.sum());
    TEST_REQUIRE(t1 == t2);
TEST_CASE_END()
 
/*
 * main test suite basic function
 */

TEST_SUITE(suite_basic)
    TEST_CASE_RUN(test_1);
    TEST_CASE_RUN(test_2);
    TEST_CASE_RUN(test_3);
TEST_SUITE_END()

/*
 * In this example we will not use TEST() and TEST_END() and call TEST_SUITE_RUN()
 * right from the main() function. We can do that when we have only one test suite
 * or when we don't care about the total test summary. When we don't use TEST()
 * and TEST_END() we may #define TEST_WO_GLOBALS, it will exclude global variables
 * qu_total and qu_failed from the compilation but also forbid to use TEST() and
 * TEST_END(). You can undef this macro on top of this file and see that nothing
 * changes because we don't use TEST() and TEST_END() in this example.
 * Btw. macro TEST_WO_GLOBALS, if set, should appear before #include "quin.h"!
 */

int main() {
    return TEST_SUITE_RUN(suite_basic);
}

