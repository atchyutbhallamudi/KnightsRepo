class TimeMap {
private:
    // Maps each key to a list of (timestamp, value) pairs
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // Since timestamps in set() are strictly increasing, 
        // appending to vector keeps it naturally sorted.
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // If the key does not exist, return empty string
        if (store.find(key) == store.end()) {
            return "";
        }

        const auto& history = store[key];
        int low = 0;
        int high = history.size() - 1;
        string ans = "";

        // Binary search to find the largest timestamp <= target timestamp
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (history[mid].first <= timestamp) {
                ans = history[mid].second; // Valid candidate found
                low = mid + 1;             // Try to find a larger timestamp <= target
            } else {
                high = mid - 1;            // Current timestamp is too big
            }
        }

        return ans;
    }
};