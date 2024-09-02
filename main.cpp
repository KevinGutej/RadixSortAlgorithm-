#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int findMaxValue(const vector<int>& nums) {
    int maxValue = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > maxValue) {
            maxValue = nums[i];
        }
    }
    return maxValue;
}

void digitSort(vector<int>& nums, int place) {
    int size = nums.size();
    vector<int> sortedList(size);
    int count[10] = {0};
    for (int i = 0; i < size; i++) {
        count[(nums[i] / place) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        sortedList[count[(nums[i] / place) % 10] - 1] = nums[i];
        count[(nums[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++) {
        nums[i] = sortedList[i];
    }
}

void sortUsingRadix(vector<int>& nums) {
    int largestNum = findMaxValue(nums);
    for (int place = 1; largestNum / place > 0; place *= 10) {
        digitSort(nums, place);
    }
}

int main() {
    vector<int> numList;
    int inputNum;
    cout << "Enter integers to sort (type 'q' to stop):" << endl;
    while (cin >> inputNum) {
        numList.push_back(inputNum);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (numList.empty()) {
        cout << "No numbers were entered. Exiting the program." << endl;
        return 0;
    }
    sortUsingRadix(numList);
    cout << "Sorted in ascending order:" << endl;
    for (int i = 0; i < numList.size(); i++) {
        cout << numList[i] << " ";
    }
    cout << endl;
    cout << "Sorted in descending order:" << endl;
    for (int i = numList.size() - 1; i >= 0; i--) {
        cout << numList[i] << " ";
    }
    cout << endl;

    return 0;
}
