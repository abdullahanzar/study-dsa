#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charMap;

    int left = 0;
    int maxLength = 0;
    int right = 0;

    for(right = 0; right<s.length(); right++) {
        char character = s[right];

        if(charMap.find(character) != charMap.end() && charMap[character] >= left) {
            left = charMap[character] + 1;
        }

        charMap[character] = right;

        maxLength = max(maxLength, right - left + 1);
    }

    cout << s.substr(left, right) << endl;

    return maxLength;
}

int main(int argc, char** argv) {
    string check = "pwwkew";

    if(argc > 1) {
        check = argv[1];
    }

    cout << lengthOfLongestSubstring(check) << endl;
}