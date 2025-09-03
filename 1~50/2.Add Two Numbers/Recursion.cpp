struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
 public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursiveAdd(l1, l2, 0);  // 從 carry = 0 開始
    }

 private:
    ListNode* recursiveAdd(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            return nullptr;  // 結束條件：兩邊都空且沒有進位
        }

        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int sum = val1 + val2 + carry;

        ListNode* node = new ListNode(sum % 10);
        node->next = recursiveAdd(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum / 10);
        return node;
    }
};
