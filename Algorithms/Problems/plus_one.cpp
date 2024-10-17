#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int lastIndex = digits.size() - 1;

    while(lastIndex>=0) {
        if((digits[lastIndex]+1) == 10) {
            digits[lastIndex] = 0;
            lastIndex--;
            continue;
        }
        else {
            digits[lastIndex] = digits[lastIndex] + 1;
            break;
        }
    }

    cout << lastIndex << endl;
    //if last index is negative that means we have a condition where carry needs to be brough forward but there is no next digit.
    if(lastIndex < 0) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main() {
    vector<int> num = {9, 9};
    for(int digit : plusOne(num)) {
        cout << digit << " ";
    }
    cout << endl;
}