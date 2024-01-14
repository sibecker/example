#include <catch2/catch_test_macros.hpp>

#include "example.h"

TEST_CASE("Tests") {
    CHECK(f(0) == 0);
    CHECK(f(1) == 1);
    for(int i = -40; i < 40; ++i) {
        CHECK(f(i) == f(i-1) + f(i-2));
    }
}
