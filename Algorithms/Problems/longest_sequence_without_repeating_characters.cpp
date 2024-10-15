#include <iostream>
#include <unordered_set>
#include <string>

/* UNORDERED SET CONTAINS THESE FUNCTIONS:
    .insert()
    .find() -> returns a .end() if not found
    .begin() -> to be able to loop through, the beginning
    .end() -> end of the set
*/

using namespace std;

int lengthOfLongestSubstring(string s) {
    //BE VERY CLEAR, THEY ARE ASKING THE LENGTH NOT THE CHARACTERS, JUST THE LENGTH OF THE LONGEST UNDUPLICATE SUBSTRING
    unordered_set<char> charSet;

    int left = 0;
    int maxLength = 0;

    for(int right = 0; right<s.length(); right++) {
        //CHECK IF ALREADY IN THE CHARACTER SET
        //IF IS A DUPLICATE

        char character = s[right];

        while(charSet.find(character) != charSet.end()) {
            //INCREASE LEFT TO KEEP TRACK OF THE LENGTH OF THE LONGEST SUBSTRING, NOTICE THE MAX_LENGTH BELOW
            left++;
            //ERASE THE CHARACTER FROM THE SET, SINCE A SAME CHARACTER WILL BE ADDED BELOW
            charSet.erase(character);
        }

        charSet.insert(character);
        //MAX LENGTH CAN BE CALCULATED AS THE RIGHT MOST TRAVERSED STRING - THE DUPLICATES + 1 TO BALANCE THE INDEX,
        //WE WANT THE LENGTH NOT THE INDEX POSITIONING THAT IS WHY WE ARE ADDING 1.
        //THIS CHECKING OF MAXIMUM ELEMENT IS EXTREMELY IMPORTANT SINCE WE NEED THE MAXIMUM UNIQUE CHARACTERS FROM A SEQUENCE 
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}


int main(int argc, char ** argv) {
    string check = "pwwkew";

    if(argc > 1) {
        check = argv[1];
    }

    int longestSubstringWithoutRepeating = lengthOfLongestSubstring(check);

    cout << longestSubstringWithoutRepeating;
}