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

