#include <iostream>
#include <vector>
using namespace std;

string operators = "+-*";

bool solve(vector<int>& nums, int target, string& result, int index = 0, int current = 0) {
    if (index == nums.size() - 1) {
        if (current == target) {
           result += '='+ to_string(target);
            return true;
        } else {
            return false;
        }
    }
    for (char op : operators) {
        string temp = result;
        result += op+  to_string(nums[index]);
        int next = current;

        switch (op) {
            case '+':
                next += nums[index];
                break;
            case '-':
                next -= nums[index];
                break;
            case '*':
                next *= nums[index];
                break;
        }

        if (solve(nums, target, result, index + 1, next)) {
            return true;
        }

        result = temp;  // backtrack
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    string result;
    if (solve(nums, nums.back(), result)) {

        cout << result<<'\n';
    } else {
        cout << "No solution found.\n";
    }
    return 0;
}
