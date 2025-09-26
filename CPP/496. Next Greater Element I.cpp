class Solution {
private:
    vector<int> better(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        unordered_map<int, int> ngeMap;
        ngeMap[nums2[n2 - 1]] = -1;

        stack<int> st;
        st.push(nums2[n2 - 1]);
        for (int i = n2 - 2; i >= 0; --i) {
            while (!st.empty() && nums2[i] > st.top())
                st.pop();

            if (st.empty())
                ngeMap[nums2[i]] = -1;

            else if(nums2[i] < st.top())
                ngeMap[nums2[i]] = st.top();                    

            st.push(nums2[i]);
        }
        for (auto& num: nums1)
            ans.push_back(ngeMap[num]);

        return ans;
    }

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return better(nums1, nums2);
    }
};
