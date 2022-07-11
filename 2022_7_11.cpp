class Solution {
public:
	/**
	 *
	 * @param head ListNodeÀà
	 * @return ListNodeÀà
	 */
	ListNode* deleteDuplicates(ListNode* head) {
		// write code here
		if (head == NULL || head->next == NULL)
			return head;
		ListNode*cur = head->next;
		if (head->val == cur->val)
		{
			while (cur&&head->val == cur->val)
				cur = cur->next;
			head = deleteDuplicates(cur);
		}
		else
			head->next = deleteDuplicates(cur);
		return head;
	}
};