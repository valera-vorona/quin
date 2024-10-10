/*
 * In this example we will use TEST() and TEST_END() as the main test unit,
 * which conststs of one test suite (but may consist of any) which in turn
 * includes and runs 3 test cases.
 * Test case definitions should go above the test suite definition and the latter
 * should prepend the main test definition.
 * Any test case shoud begin with TEST_CASE_BEGIN(name) and end with TEST_CASE_END()
 * where name is any allowed c identifier. Inside any test case there should be one
 * or more TEST_REQUIRE(condition) with the condition being any allowed c expression.
 * If the expression equals to 0, the test case treats failed and occures in
 * statistics. All other results treat successive and the test case is considered
 * passed.
 * Test cases combine into test suites. Test suites begin with TEST_SUITE_BEGIN(name)
 * and end with TEST_SUITE_END() where name is any allowed c identifier. Test cases
 * should be run inside the test suite with TEST_CASE_RUN(name) where name is the
 * name of the test case previously defined.
 * Test suites may or may not be combuned into TEST(name) ans TEST_END() as the main
 * test unit. Test suites may be run inside TEST() and TEST_END() block and in this
 * case they become part of the main test or from any other place, e.g. from main()
 * function.
 */

#include <string.h>
#include "quin.h"
/* ==============================
 *
 * Test suite suite_basic
 *
 ================================ */

TEST_CASE(test_1)
    int x = 5, y = 15, z;
    z = x != y;
    TEST_REQUIRE(z);
TEST_CASE_END()
 
TEST_CASE(test_2)
    int x = 5, y = 15, z = 10;
    TEST_REQUIRE(y - x == z);
TEST_CASE_END()
 
TEST_CASE(test_3)
    const char a[] = "asdf";
    int len = strlen(a);
    TEST_REQUIRE(len);
TEST_CASE_END()

/*
 * main test suite basic function
 */

TEST_SUITE(suite_basic)
    TEST_CASE_RUN(test_1);
    TEST_CASE_RUN(test_2);
    TEST_CASE_RUN(test_3);
TEST_SUITE_END()

/* ==============================
 *
 * Test main function
 *
 ================================ */

TEST(test_example)
    TEST_SUITE_RUN(suite_basic);
TEST_END()

/* main */

int main() {
    return TEST_RUN(test_example);
}

