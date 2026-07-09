#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequencies
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Step 2: Load available tasks into a max-heap
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }
        
        // Step 3: Setup the waiting room queue
        // Stores pairs of: {remaining_frequency, time_it_becomes_available}
        queue<pair<int, int>> waitQueue;
        
        int time = 0;
        
        // Step 4: Simulate time passing
        // Keep going as long as we have tasks available OR tasks stuck in waiting
        while (!pq.empty() || !waitQueue.empty()) {
            time++; // 1 unit of time passes
            
            // If we have an available task, process it
            if (!pq.empty()) {
                int currentFreq = pq.top();
                pq.pop();
                
                currentFreq--; // We did the task!
                
                // If it still needs to be done again later, send it to the waiting room
                if (currentFreq > 0) {
                    waitQueue.push({currentFreq, time + n});
                }
            }
            
            // Check if the task at the front of the waiting room is done cooling down
            if (!waitQueue.empty() && waitQueue.front().second == time) {
                // It's ready! Put its frequency back into the available max-heap
                pq.push(waitQueue.front().first);
                waitQueue.pop();
            }
        }
        
        return time;
    }
};