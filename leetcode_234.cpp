// 234. Palindrome Linked List
// Given a singly linked list, determine if it is a palindrome.

// Follow up:
// Could you do it in O(n) time and O(1) space?

#include "leetcode.hpp"


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto rhead = reverse(slow->next);
        while(rhead)
        {
            if(head->val != rhead->val)
                return false;
            head = head->next;
            rhead = rhead->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode *n1 = head->next;
        head->next = nullptr;
        while(n1)
        {
            auto n2 = n1->next;
            n1->next = head;
            head = n1;
            n1 = n2;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    ListNode *head = new ListNode(1);
    CHECK_TRUE(sln.isPalindrome(head));
    ListNode *ln1 = new ListNode(0);
    ListNode *ln2 = new ListNode(0);
    head->next = ln1;
    ln1->next = ln2;
    CHECK_FALSE(sln.isPalindrome(head));
    delete head;
    delete ln1;    
    delete ln2;    

    TEST_REPORT();
}