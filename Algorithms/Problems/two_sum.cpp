// Question description: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std; 

// Brute force solution
vector<int> twoSumWithBruteForce(vector<int>& nums, int target) {
    vector<int> ans = {};

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                ans = {i, j};
                return ans;
            }
        }
    }

    return ans;
}

// Best solution using a hash map
vector<int> twoSumBest(vector<int>& nums, int target) {
    unordered_map<int, int> obj;
    vector<int> ans = {};

    // Store the value and its index in the map
    for (int i = 0; i < nums.size(); i++) {
        obj[nums[i]] = i;
    }

    // Find the complement and check if it exists in the map
    for (int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];

        // Check if the complement exists in the map and is not the current index
        if (obj.find(comp) != obj.end() && obj[comp] != i) {
            ans = {i, obj[comp]};
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> check = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSumWithBruteForce(check, target);
    cout << "Brute Force Solution: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> ans2 = twoSumBest(check, target);
    cout << "Best Solution: ";
    for (int i : ans2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
