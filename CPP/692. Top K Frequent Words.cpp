// Freq map with MinHeap using custom Comparator

class Solution {
private:
    struct MinHeapComparator {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans(k);
        unordered_map<string, int> mp;
        for (auto& word : words)
            mp[word]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       MinHeapComparator> minHeap;

        for (auto& it : mp) {
            minHeap.push({it.second, it.first});

            if (minHeap.size() > k)
                minHeap.pop();
        }
        while (k) {
            auto top = minHeap.top();
            minHeap.pop();
            ans[--k] = top.second;
        }
        return ans;
    }
};
