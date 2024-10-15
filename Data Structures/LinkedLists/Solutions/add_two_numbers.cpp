/*ADD TWO NON NEGATIVE INTEGERS PRESENT INSIDE A LINKED LIST*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;

    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode *node, bool formatted = false) {
    if(formatted) {
        string number = "";

        while(node!=nullptr) {
            number = to_string(node->val) + number;
            node = node->next;
        }

        cout << number;
    }
    else {
        while(node!=nullptr) {
            cout << node->val;

            if(node->next!=nullptr) 
            cout << "->";

            node = node->next;
        }
    }

    cout<<endl;
};

class Solution {
    public: 
        ListNode* addTwoNumbers(ListNode *L1, ListNode *L2) {
            ListNode* dummy = new ListNode();
            ListNode* temp = dummy;

            int carry = 0;

            while(L1!=nullptr || L2!=nullptr || carry!=0) {
                int val1 = (L1!=nullptr) ? L1->val : 0;
                int val2 = (L2!=nullptr) ? L2->val : 0;

                int sum = val1 + val2 + carry;

                carry = sum / 10;
                int digit = sum % 10;

                temp -> next = new ListNode(digit);

                temp = temp->next;

                if(L1 != nullptr) L1 = L1->next;
                if(L2 != nullptr) L2 = L2->next;
            }

            return dummy->next;
        }
};

int main() {
    ListNode* l1 = new ListNode(8, new ListNode(3, new ListNode(7, nullptr)));
    ListNode* l2 = new ListNode(9, new ListNode(2, new ListNode(9, nullptr)));

    Solution solution;

    ListNode *result = solution.addTwoNumbers(l1, l2);

    printList(result, true);

    system("pause");

    return 0;
};