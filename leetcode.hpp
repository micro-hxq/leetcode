/**
 *  This file includes most necessary c++ header files
 *  and some macros for test.
 */

#ifndef LEETCODE_HPP
#define LEETCODE_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <utility>
#include <climits>
#include <bitset>

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define LEETCODE_EUQAL(euqation, expect, actual, format)                        \
    do {                                                                        \
        ++test_count;                                                           \
        if(euqation)                                                            \
            ++test_pass;                                                        \
        else                                                                    \
        {                                                                       \
            fprintf(stderr, "%s:%d: expect: " format ", acutal: " format "\n",  \
                    __FILE__, __LINE__, expect, actual);                        \
            main_ret = 1;                                                       \
        }                                                                       \
    } while(0)

#define CHECK_TRUE(expression)  \
    LEETCODE_EUQAL((expression) == true, 1, expression, "%d")

#define CHECK_FALSE(expression) \
    LEETCODE_EUQAL((expression) == false, 0, expression, "%d")

#define TEST_REPORT()                                           \
    do {                                                        \
        printf("========================================\n");   \
        printf("%d tests, %d passed.\n", test_count, test_pass);\
        return main_ret;                                        \
    } while(0)


using namespace std;

#endif

