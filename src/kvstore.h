// kvstore.h - the "header" file.
// It DESCRIBES the KVStore class: what it can do (its functions)
// and what it holds (its data). The actual code is in kvstore.cpp.
#pragma once

#include <optional>
#include <string>
#include <unordered_map>

class KVStore {
public:
    // Save `value` under `key`. If the key already exists, overwrite it.
    void set(const std::string& key, const std::string& value);

    // Look up `key`.
    // Returns the value if found, or std::nullopt ("nothing") if not.
    std::optional<std::string> get(const std::string& key) const;

    // Delete `key`. Returns true if it existed, false if it didn't.
    bool del(const std::string& key);

    // How many keys are stored right now.
    std::size_t size() const;

private:
    // The actual storage: a hash map from key -> value, kept in memory (RAM).
    // Like a Python dict: data_["name"] = "Vaishnavi";
    std::unordered_map<std::string, std::string> data_;
};
