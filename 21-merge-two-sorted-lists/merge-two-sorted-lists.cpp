class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        vector<int> arr;

        while (list1 != NULL) {
            arr.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2 != NULL) {
            arr.push_back(list2->val);
            list2 = list2->next;
        }

        sort(arr.begin(), arr.end());

        ListNode* head = NULL;
        ListNode* tail = NULL;

        for (int i = 0; i < arr.size(); i++) {

            ListNode* temp = new ListNode(arr[i]);

            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
        }

        return head;
    }
};