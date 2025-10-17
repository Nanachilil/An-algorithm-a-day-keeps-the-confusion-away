// Copyright (C) 2025-10-17 Nana Zhao

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nums = n;
        ListNode* slow = head;
        ListNode* prev_slow = head;
        ListNode* fast = head;
        bool is_slow_run = false;

        // 判断特殊情况 n=0，
        if (n == 0)
            return head;
        if (head == nullptr)
            return nullptr;

        // 快指针先移动n步
        while (--nums) {
            fast = fast->next;
        }

        // 删除头节点
        if (fast->next == nullptr) {
            return head->next;
        }

        // 共同移动
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
            if (is_slow_run) {
                prev_slow = prev_slow->next;
            }
            is_slow_run = true;
        }

        // 删除节点
        prev_slow->next = slow->next;
        return head;
    }
};

int main() {
    return 0;
}
