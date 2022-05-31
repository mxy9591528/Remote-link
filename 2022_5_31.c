int* moveZeroes(int* nums, int numsLen, int* returnSize) {
	// write code here
	*returnSize = numsLen;
	int left = 0, right = 0;
	while (right < numsLen)
	{
		if (nums[right])
		{
			int temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
		}
		right++;
	}
	return nums;
}