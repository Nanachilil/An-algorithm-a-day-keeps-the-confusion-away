// Copyright (c) 2025-10-14 Nana Zhao

#include <iostream>
#include <memory>

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
   public:
    std::shared_ptr<ListNode> head;

    MyLinkedList() = default;

    int get(int index) const {
        auto cur = head;
        for (int i = 0; i < index && cur; ++i)
            cur = cur->next;
        return cur ? cur->val : -1;
    }

    void addAtHead(int val) {
        auto newNode = std::make_shared<ListNode>(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        auto newNode = std::make_shared<ListNode>(val);
        if (!head) {
            head = newNode;
            return;
        }
        auto cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        auto cur = head;
        for (int i = 0; i < index - 1 && cur; ++i)
            cur = cur->next;

        if (!cur)
            return;  // index 超过长度，不插入

        auto newNode = std::make_shared<ListNode>(val);
        newNode->next = cur->next;
        cur->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (!head)
            return;

        if (index == 0) {
            head = head->next;
            return;
        }

        auto cur = head;
        for (int i = 0; i < index - 1 && cur; ++i)
            cur = cur->next;

        if (!cur || !cur->next)
            return;
        cur->next = cur->next->next;
    }

    void print() const {
        auto cur = head;
        std::cout << "链表: ";
        while (cur) {
            std::cout << cur->val;
            if (cur->next)
                std::cout << " -> ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
};

int main() {
    MyLinkedList list;

    std::cout << "===== 测试开始 =====\n";

    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);  // 链表: 1 -> 2 -> 3
    list.print();

    std::cout << "get(1): " << list.get(1) << "\n";  // 2

    list.deleteAtIndex(1);  // 删除节点2 → 1 -> 3
    list.print();

    list.addAtIndex(2, 4);  // 尾插 → 1 -> 3 -> 4
    list.print();

    list.addAtIndex(10, 99);  // 越界，不插入
    list.print();

    list.deleteAtIndex(0);  // 删除1 → 3 -> 4
    list.print();

    list.deleteAtIndex(0);  // 删除3 → 4
    list.deleteAtIndex(0);  // 删除4 → 空
    list.print();

    std::cout << "get(0): " << list.get(0) << "\n";  // -1
    std::cout << "===== 测试结束 =====\n";
}
