// Copyright (c) 2025-10-15 Nana Zhao

#include <iostream>
#include <memory>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = nullptr;
        ListNode* current_head = head;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        for (tail = head; tail->next != nullptr; tail = tail->next) {
        }
        current_head = head->next;
        while (head != tail) {
            head->next = tail->next;
            tail->next = head;
            head = current_head;
            if (current_head != nullptr) {
                current_head = current_head->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    Solution solution;
    ListNode* reversed_head = solution.reverseList(head);

    auto curr = reversed_head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    // 手动释放整个链表

    curr = reversed_head;
    while (curr != nullptr) {
        ListNode* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
    return 0;
}
