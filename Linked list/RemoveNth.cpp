#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;
    
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }
    
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    
    ListNode* nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;
    
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}