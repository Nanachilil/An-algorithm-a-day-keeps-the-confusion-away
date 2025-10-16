// Copyright (C) 2025-10-16 Nana Zhao

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* SwapPairs(ListNode* head) {
        auto curr = head;

        if (!curr || !curr->next) {
            return head;
        }

        // 处理头节点
        ListNode* new_head = curr->next;
        curr->next = curr->next->next;
        new_head->next = curr;

        ListNode* prev = curr;
        curr = curr->next;
        if (!curr) {
            return new_head;
        }
        ListNode* after_curr = curr->next;

        while (after_curr) {
            // 交换 curr 和 after_curr
            curr->next = after_curr->next;
            after_curr->next = curr;
            prev->next = after_curr;

            // 更新指针
            prev = curr;
            curr = curr->next;
            if (!curr) {
                return new_head;
            }
            after_curr = curr->next;
        }

        return new_head;
    }
};

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    Solution sol;
    auto new_head = sol.SwapPairs(head);
    auto curr = new_head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    while (new_head) {
        auto temp = new_head;
        new_head = new_head->next;
        delete temp;
    }
    return 0;
}
