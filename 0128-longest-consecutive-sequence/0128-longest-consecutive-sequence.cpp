class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Dump all numbers into a hash set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int longestStreak = 0;

        // Step 2: Iterate through the set (or the array)
        for (int num : numSet) {
            
            // Step 3: Check if this number is the START of a sequence.
            // If (num - 1) exists, this 'num' is not the start, so we skip it!
            if (!numSet.count(num - 1)) {
                
                int currentNum = num;
                int currentStreak = 1;

                // Step 4: Now that we found a start, count upwards!
                while (numSet.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                // Update the maximum streak found so far
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};