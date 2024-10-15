#include <iostream>

using namespace std;

struct ListNode {
    int val;

    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int main() {
    ListNode *head = new ListNode(1);
    
    cout << "Enter some values, enter a non integer to stop" << endl;

    while(true) {
        int x;
        cin >> x;
        if (!cin) {
            break;
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new ListNode(x);
    };

    ListNode *temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;


    system("pause");

    return 0;
}


