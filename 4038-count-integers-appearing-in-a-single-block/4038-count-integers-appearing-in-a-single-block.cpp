class Solution {
public:
    int countSpecialIntegers(vector<int>& arr) {
        if (arr.size() == 1)
            return 1;

        unordered_map<int, int> mp;
        bool seen[101] = {false};

        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {

            if (mp.find(arr[i]) == mp.end()) {
           // first occurance
                mp[arr[i]] = i;
                count++;
                continue;
            }
            else {
                int sub = i - mp[arr[i]];

                if (sub == 1) {
                    //still its contiguous
                    mp[arr[i]] = i;
                }
                else if (seen[arr[i]] == false) {
                    // appeared again after gap Not VALID
                    seen[arr[i]] = true;
                    count--;
                }
            }
        }

        return count;
    }
};