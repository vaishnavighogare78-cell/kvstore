// kvstore.cpp - the actual code for the KVStore class.
//
// ============================================================
//  YOUR TASK (Stage 1): fill in the 4 functions below.
//  Each one is only 1-3 lines. Hints are next to each TODO.
//
//  Useful std::unordered_map operations (data_ is the map):
//    data_[key] = value;        // insert or overwrite
//    data_.find(key)            // returns an "iterator" to the entry,
//                               // or data_.end() if not found
//    it->second                 // the value of the entry `it` points to
//    data_.erase(key)           // removes key, returns how many were removed (0 or 1)
//    data_.size()               // number of entries
// ============================================================

#include "kvstore.h"

void KVStore::set(const std::string& key, const std::string& value) {
    data_[key] = value;
}

std::optional<std::string> KVStore::get(const std::string& key) const {
    auto it = data_.find(key);      // search for the key
    if (it == data_.end()) {           // blank 1: the "not found" marker
        return std::nullopt;        // not found → return nothing
    }
    return it->second;                // blank 2: the value the iterator points to
}

bool KVStore::del(const std::string& key) {
    return data_.erase(key) == 1;
}

std::size_t KVStore::size() const {
    return data_.size();
}
