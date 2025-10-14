// Copyright (c) 2025-10-14 Nana Zhao

#include <iostream>
#include <memory>

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;
    ListNode(int x) : val(x), next(nullptr) {}
    virtual ~ListNode() {}
};

class MyLinkedList {
   public:
    std::shared_ptr<ListNode> head;
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        std::shared_ptr<ListNode>* current = &head;
        for (int i = 0; i < index; ++i) {
            if ((*current) == nullptr)
                return -1;
            current = &((*current)->next);
        }
        if ((*current) == nullptr)
            return -1;
        return (*current)->val;
    }

    void addAtHead(int val) {
        auto newNode = std::make_shared<ListNode>(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        auto newNode = std::make_shared<ListNode>(val);
        auto current = &head;
        if (*current == nullptr) {
            head = newNode;
            return;
        }

        while (((*current)->next) != nullptr) {
            current = &((*current)->next);
        }

        (*current)->next = newNode;
        return;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        auto newNode = std::make_shared<ListNode>(val);
        std::shared_ptr<ListNode>* current = &head;
        for (int i = 0; i < index - 1; ++i) {
            if ((*current) == nullptr)
                return;
            current = &((*current)->next);
        }

        if ((*current) == nullptr) {
            return;
        }
        if ((*current)->next == nullptr) {
            (*current)->next = newNode;
            return;
        }

        newNode->next = (*current)->next;
        (*current)->next = newNode;
        return;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr)
            return;
        if (index == 0) {
            head = head->next;
            return;
        }

        auto current = &head;
        for (int i = 0; i < index - 1; ++i) {
            if ((*current) == nullptr)
                return;
            current = &((*current)->next);
        }

        if ((*current) == nullptr || (*current)->next == nullptr)
            return;
        (*current)->next = (*current)->next->next;
        return;
    }
};

int main() {
    MyLinkedList myLinkedList;

    std::cout << "===== 测试开始 =====\n";

    // 1. 测试 addAtHead
    std::cout << "[1] addAtHead(1)\n";
    myLinkedList.addAtHead(1);                                          // 链表: 1
    std::cout << "当前第0个节点值: " << myLinkedList.get(0) << "\n\n";  // 输出1

    // 2. 测试 addAtTail
    std::cout << "[2] addAtTail(3)\n";
    myLinkedList.addAtTail(3);                                          // 链表: 1 -> 3
    std::cout << "当前第1个节点值: " << myLinkedList.get(1) << "\n\n";  // 输出3

    // 3. 测试 addAtIndex
    std::cout << "[3] addAtIndex(1, 2)\n";
    myLinkedList.addAtIndex(1, 2);  // 链表: 1 -> 2 -> 3
    std::cout << "当前链表内容: ";
    for (int i = 0; i < 3; ++i)
        std::cout << myLinkedList.get(i) << " ";
    std::cout << "\n\n";  // 输出 1 2 3

    // 4. 测试 get 越界访问
    std::cout << "[4] get(5) (越界)\n";
    std::cout << "返回值: " << myLinkedList.get(5) << "\n\n";  // 输出 -1

    // 5. 测试 deleteAtIndex
    std::cout << "[5] deleteAtIndex(1)\n";
    myLinkedList.deleteAtIndex(1);  // 删除索引1节点 -> 链表: 1 -> 3
    std::cout << "删除后链表内容: ";
    for (int i = 0; i < 3; ++i)
        std::cout << myLinkedList.get(i) << " ";
    std::cout << "\n\n";  // 输出 1 3 -1

    // 6. 测试尾部插入
    std::cout << "[6] addAtIndex(2, 4) (在尾部插入)\n";
    myLinkedList.addAtIndex(2, 4);  // 链表: 1 -> 3 -> 4
    std::cout << "当前链表内容: ";
    for (int i = 0; i < 4; ++i)
        std::cout << myLinkedList.get(i) << " ";
    std::cout << "\n\n";  // 输出 1 3 4 -1

    // 7. 测试越界插入
    std::cout << "[7] addAtIndex(10, 99) (越界不插入)\n";
    myLinkedList.addAtIndex(10, 99);  // 无操作
    std::cout << "当前链表内容: ";
    for (int i = 0; i < 4; ++i)
        std::cout << myLinkedList.get(i) << " ";
    std::cout << "\n\n";  // 输出 1 3 4 -1

    // 8. 删除所有节点
    std::cout << "[8] deleteAtIndex(0)\n";
    myLinkedList.deleteAtIndex(0);  // 链表: 3 -> 4
    std::cout << "[8] deleteAtIndex(0)\n";
    myLinkedList.deleteAtIndex(0);  // 链表: 4
    std::cout << "[8] deleteAtIndex(0)\n";
    myLinkedList.deleteAtIndex(0);                                      // 链表: 空
    std::cout << "删除完毕后 get(0): " << myLinkedList.get(0) << "\n";  // 输出 -1

    std::cout << "===== 测试结束 =====\n";
}
