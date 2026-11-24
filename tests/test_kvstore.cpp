// test_kvstore.cpp - automated tests for KVStore.
//
// Instead of typing commands by hand, this program calls the KVStore
// functions directly and CHECKS that the results are what we expect.
// If every check passes, it prints "ALL TESTS PASSED" and exits with 0.
// If any check fails, it prints which one (with the line number) and exits with 1.
//
// Run with:  ctest --test-dir build --output-on-failure

#include <iostream>
#include <string>

#include "kvstore.h"

// ---- A tiny testing helper ------------------------------------------------
// CHECK(condition) - if the condition is false, print the line and count a failure.
// (Real projects use a library like GoogleTest; this is the same idea, but tiny.)
static int failures = 0;

#define CHECK(condition)                                                    \
    do {                                                                    \
        if (!(condition)) {                                                 \
            std::cerr << "  FAILED at line " << __LINE__ << ": "            \
                      << #condition << "\n";                                \
            ++failures;                                                     \
        }                                                                   \
    } while (0)

// ---- Tests ----------------------------------------------------------------
// Each test creates a fresh, empty store, so tests don't affect each other.

void test_new_store_is_empty() {
    KVStore store;
    CHECK(store.size() == 0);
    CHECK(!store.get("anything").has_value());
}

void test_set_then_get() {
    KVStore store;
    store.set("name", "Vaishnavi");
    CHECK(store.get("name").has_value());
    CHECK(store.get("name").value() == "Vaishnavi");
    CHECK(store.size() == 1);
}

void test_set_overwrites_old_value() {
    KVStore store;
    store.set("name", "Vaishnavi");
    store.set("name", "Shravya");
    CHECK(store.get("name").value() == "Shravya");
    CHECK(store.size() == 1);  // still only one key, not two
}

void test_get_missing_key() {
    KVStore store;
    store.set("a", "1");
    CHECK(!store.get("b").has_value());
}

void test_delete_existing_key() {
    KVStore store;
    store.set("name", "Vaishnavi");
    CHECK(store.del("name") == true);
    CHECK(!store.get("name").has_value());
    CHECK(store.size() == 0);
}

// ============================================================
//  YOUR TASK (Stage 2): write the next 2 tests yourself.
//  Copy the style of the tests above.
// ============================================================

void test_delete_missing_key() {
    // TODO: make a store, call del on a key that was never set,
    //       and CHECK that it returns false.
}

void test_many_keys() {
    // TODO: set 3 different keys ("a", "b", "c") with different values.
    //       CHECK that size() is 3 and that each get() returns the right value.
    //       Then delete one and CHECK that size() is 2.
}

// ---- Run everything -------------------------------------------------------
int main() {
    test_new_store_is_empty();
    test_set_then_get();
    test_set_overwrites_old_value();
    test_get_missing_key();
    test_delete_existing_key();
    test_delete_missing_key();
    test_many_keys();

    if (failures == 0) {
        std::cout << "ALL TESTS PASSED\n";
        return 0;
    }
    std::cerr << failures << " check(s) failed\n";
    return 1;
}
