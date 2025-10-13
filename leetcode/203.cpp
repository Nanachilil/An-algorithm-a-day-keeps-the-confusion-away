// Copyright (C) 2025-10-13 Nana Zhao

#include <iostream>
#include <memory>
#include <vector>

// ======================================================
// 节点定义（含构造函数与析构函数）
// ======================================================
struct ListNode {
    int val;
    std::unique_ptr<ListNode> next;

    // 构造函数
    explicit ListNode(int input_x) : val(input_x) {
        // std::cout << "Construct Node(" << val << ")\n";
    }

    // 析构函数：递归销毁链表
    ~ListNode() {
        // std::cout << "Destruct Node(" << val << ")\n";
    }
};

// ======================================================
// 删除指定值的节点（核心算法）
// ======================================================
void removeElements(std::unique_ptr<ListNode>& head, int val) {
    // 使用指向 unique_ptr 的指针来遍历链表
    std::unique_ptr<ListNode>* current = &head;

    while (current->get()) {
        if ((*current)->val == val) {
            // 删除当前节点：跳过它（被跳过节点的析构自动触发）
            *current = std::move((*current)->next);
        } else {
            // 前进
            current = &((*current)->next);
        }
    }
}

// ======================================================
// 辅助函数：根据数组构造链表
// ======================================================
std::unique_ptr<ListNode> buildList(const std::vector<int>& values) {
    std::unique_ptr<ListNode> head;
    std::unique_ptr<ListNode>* tail = &head;

    for (auto v : values) {
        *tail = std::make_unique<ListNode>(v);
        tail = &((*tail)->next);
    }
    return head;
}

// ======================================================
// 辅助函数：打印链表
// ======================================================
void printList(const std::unique_ptr<ListNode>& head) {
    const ListNode* node = head.get();
    std::cout << "[";
    while (node) {
        std::cout << node->val;
        node = node->next.get();
        if (node)
            std::cout << ", ";
    }
    std::cout << "]\n";
}

// ======================================================
// 主函数：测试
// ======================================================
int main() {
    {
        std::cout << "=== Example 1 ===\n";
        auto head = buildList({1, 2, 6, 3, 4, 5, 6});
        std::cout << "Before: ";
        printList(head);

        removeElements(head, 6);

        std::cout << "After : ";
        printList(head);
    }

    {
        std::cout << "\n=== Example 2 ===\n";
        auto head = buildList({});
        std::cout << "Before: ";
        printList(head);

        removeElements(head, 1);

        std::cout << "After : ";
        printList(head);
    }

    {
        std::cout << "\n=== Example 3 ===\n";
        auto head = buildList({7, 7, 7, 7});
        std::cout << "Before: ";
        printList(head);

        removeElements(head, 7);

        std::cout << "After : ";
        printList(head);
    }

    std::cout << "\nProgram End.\n";
    return 0;
}
