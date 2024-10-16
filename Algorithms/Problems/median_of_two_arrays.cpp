#include<iostream>
#include<vector>


using namespace std;


/*THIS IS A NAIVE APPROACH
REMEMBER THE ARRAYS ARE ALREADY SORTED, YOU REALLY DON'T NEED TO MERGE THEM TO COMPUTE THE COMBINED SIZE AND MEDIAN*/
vector<int> mergeSortedArrays(vector<int>& a, vector<int>& b) {
    int len1 = a.size();
    int len2 = b.size();

    vector<int> mergedSortedArray;

    int i=0, j=0;

    //COMPARE AND MERGE
    while(i<len1 && j<len2) {
        if(a[i]<b[j]) {
            mergedSortedArray.push_back(a[i]);
            i++;
        }
        else {
            mergedSortedArray.push_back(b[j]);
            j++;
        }
    }

    //ADD THE REMAINING ELEMENTS
    while(i<len1) {
        mergedSortedArray.push_back(a[i]);
        i++;
    }

    while(j<len2) {
        mergedSortedArray.push_back(b[j]);
        j++;
    }

    for(auto i=mergedSortedArray.begin(); i<mergedSortedArray.end(); ++i) {
        cout << *i << " ";
    }

    cout << endl;

    return mergedSortedArray;
    
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> mergedSortedArray = mergeSortedArrays(nums1, nums2);

    int size = mergedSortedArray.size();

    cout << size << endl;

    if(size%2 == 0) {
        return (double) (mergedSortedArray[(int) size/2] + mergedSortedArray[(int) (size/2 - 1)]) / 2;
    } else {
        return mergedSortedArray[(int) size/2];
    }
}

/*TIME COMPLEXITY OF THIS APPROACH IS O(M+N) AS WELL AS SPACE COMPLEXITY*/

/*THE MOST EFFICIENT APPROACH IS USING BINARY SEARCH
THIS SEARCHES FOR A PARTITION SUCH THAT THERE ARE EQUAL / ALMOST EQUAL ELEMENTS ON LEFT AND RIGHT SIDES OF THE PARTITION*/
/*SUCH THAT FOR PARTITIONS X AND Y, MAXLEFTX <= MINRIGHTY AND MAXLEFTY <= MINRIGHTX
IF NOT WE DIVIDE INTO BRINARY PARTITIONS AGAIN*/

double findMedianSortedEffecient(vector<int>& input1, vector<int>& input2) {
    int x = input1.size();
    int y = input2.size();

    if(x>y) {
        return findMedianSortedEffecient(input2, input1);
    }

    int low = 0;
    int high = x;

    while(low <= high) {
        //BOTH THE PARTITIONS ADD TO THE LENGTH OF THE MERGED ARRAY
        // PARTITION 1 + PARTITION 2 = X+Y + 1 (FOR EVEN / ODD)
        int partition1 = (low + high) / 2;
        int partition2 = ((x+y+1) / 2) - partition1; //THIS LINE IS A BIT AMBIGUOUS TO UNDERSTAND
    
        int maxLeftX = (partition1 == 0) ? INT_MIN : input1[partition1 - 1];
        int minRightX = (partition1 == x) ? INT_MAX : input1[partition1];

        int maxLeftY = (partition2 == 0) ? INT_MIN : input2[partition2 - 1];
        int minRightY = (partition2 == y) ? INT_MAX : input2[partition2];

        if(maxLeftX<=minRightY && maxLeftY<=minRightX) {
            // cout << maxLeftX << endl;
            // cout << maxLeftY << endl;
            //FOUND THE CORRECT PARTITION
            //COMPUTE THE MEDIAN 
            //IF SIZE IS ODD -> MAX(maxLeftX, maxLeftY)
            //IF SIZE IS EVEN -> AVG(MAX(maxLeftX, maxLeftY), MIN(minRightY, minRightX))
            if((x+y)%2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if(maxLeftX > minRightY) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }
    return 0.0;
}

int main() {
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3, 4, 5};

    //cout << findMedianSortedArrays(arr1, arr2) << endl;
    cout << findMedianSortedEffecient(arr1, arr2) << endl;
}