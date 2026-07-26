// Standalone helper function: returns true when timestamp < element's timestamp
bool comp(int ts, const pair<int, string>& p) {
    return ts < p.first;
}

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // Return empty string if the key doesn't exist
        if (store.find(key) == store.end()) return "";

        const auto& history = store[key];

        // upper_bound finds the first pair where pair.first > timestamp
        auto it = upper_bound(history.begin(), history.end(), timestamp, comp);

        // Case 1: Every timestamp in history is > target timestamp
        if (it == history.begin()) {
            return "";
        }

        // Case 2 & 3: Handles both 'end()' and 'middle' cases by stepping back 1
        --it;
        return it->second;
    }
};