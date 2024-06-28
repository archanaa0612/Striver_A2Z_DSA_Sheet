#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        priority_queue<int, vector<int>, greater<int>> pq;

        // Count occurrences of each card
        for (int card : hand) {
            count[card]++;
        }

        // Insert all unique cards into the priority queue
        for (const auto& entry : count) {
            pq.push(entry.first);
        }

        // Process the cards in the priority queue
        while (!pq.empty()) {
            int first = pq.top();

            // Try to form a group starting with the smallest card
            for (int i = 0; i < groupSize; ++i) {
                int currentCard = first + i;
                if (count[currentCard] == 0) return false;

                count[currentCard]--;

                // If the count of currentCard becomes zero and it is the top of the heap, pop it
                if (count[currentCard] == 0 && currentCard == pq.top()) {
                    pq.pop();
                }
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;
    cout << (solution.isNStraightHand(hand1, groupSize1) ? "True" : "False") << endl;

    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 4;
    cout << (solution.isNStraightHand(hand2, groupSize2) ? "True" : "False") << endl;

    return 0;
}
