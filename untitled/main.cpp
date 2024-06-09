#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            std::vector<int> list;
            int remember = nums[i];
            list.push_back(remember);
            for (int j = i + 1; j < nums.size(); j++) {
                list.push_back(nums[j]);
                list.push_back(nums[j+1]);
                std::swap(nums[j], nums[j+1]);
            }
            result.push_back(list);
        }
        return result;
    }
};

int main() {
    std::vector<int> r = {1, 2 ,3};
    std::vector<std::vector<int>> r_new = Solution::permute(r);
    for (int i = 0; i < r_new.size(); i++) {
        for (int j = 0; j < r_new.size(); j++) {
            std::cout << r_new[i][j] << " ";
        }
        std::cout << "\n";
    }
}