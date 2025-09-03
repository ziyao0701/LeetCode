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
        ListNode dummy(0);               // 虛擬頭節點，方便最後回傳
        ListNode* current = &dummy;      // 指向目前操作節點

        int carry = 0;                   // 進位

        while (l1 || l2 || carry) {
            int sum = carry;             // 先加上前一位的進位
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;            // 計算新的進位
            current->next = new ListNode(sum % 10);  // 取個位數建立新節點
            current = current->next;     // 移動到下一個節點
        }

        return dummy.next;               // 回傳真正的頭節點
    }
};