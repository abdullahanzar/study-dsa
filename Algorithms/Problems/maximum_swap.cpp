#include <iostream>
#include <cmath>

using namespace std;

int countDigits(int num) {
    int count=0;
    while(num!=0) {
        count++;
        num = num / 10;
    }
    return count;
}

int swapDigits(int num, int i, int j) {
    int totalDigits = countDigits(num);
    i = totalDigits - i - 1;
    j = totalDigits - j - 1;
    int swap_digit_1 = (num / static_cast<int>(pow(10, i))) % 10;
    int swap_digit_2 = (num / static_cast<int>(pow(10, j))) % 10;
    int swappedNum = 0;

    int lastIndex = totalDigits - 1;

    while(lastIndex>=0) {
        int digitAtIndex = (num / static_cast<int>(pow(10, lastIndex))) % 10;
        digitAtIndex = lastIndex == i ? swap_digit_2 : lastIndex == j ? swap_digit_1 : digitAtIndex;
        swappedNum = swappedNum * 10  + digitAtIndex;
        lastIndex--;
    } 

    return swappedNum;
}

int maximum_swap(int num) {
    int totalDigits = countDigits(num) - 1;
    int cpy = num;

    int maxDigit = INT_MIN;
    int maxPosition = INT_MIN;
    int swapPosition = INT_MIN;
    int prevMax = INT_MIN;

    while(totalDigits>=0) {
        int lastDigit = num%10;
        if(lastDigit>maxDigit && totalDigits!=0){
            prevMax = maxPosition;
            maxDigit = lastDigit;
            maxPosition = totalDigits;
        }
        if(lastDigit<maxDigit) {
            swapPosition=totalDigits;
        }
        num = num/10;
        totalDigits--;
    }

    cout << swapPosition << endl;
    cout << maxPosition << endl;
    cout << prevMax << endl;

    if(swapPosition == INT_MIN  || maxPosition == INT_MIN) {
        return cpy;
    }
    if(swapPosition > maxPosition) {
        return swapDigits(cpy, prevMax, swapPosition);
    }
    return swapDigits(cpy, maxPosition, swapPosition);
}

int main() {
    int x = 9973;
    cout << maximum_swap(x) << endl;
}