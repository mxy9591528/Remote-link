/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param n int����
 * @return bool������
 *
 * C������������ȫ�ֱ��������static����ֹ�ظ�����
 */
bool poweroftwo(int n) {
	// write code here
	int k = 1;
	while (k)
	{
		if (k == n)
			return true;
		k <<= 1;
	}
	return false;
}

int compare(const void*e1, const void*e2)
{
	return *(int*)e1 - *(int*)e2;
}
int* sortedArray(int* nums, int numsLen, int* returnSize) {
	// write code here
	*returnSize = numsLen;
	for (int i = 0; i < numsLen; i++)
		nums[i] *= nums[i];
	qsort(nums, numsLen, sizeof(int), compare);
	return nums;
}

int compare(const void*e1, const void*e2)
{
	return *(int*)e1 - *(int*)e2;
}
int maxGap(int* nums, int numsLen) {
	// write code here
	qsort(nums, numsLen, sizeof(int), compare);
	int max = 0;
	for (int i = 0; i < numsLen - 1; i++)
	{
		if (max < nums[i + 1] - nums[i])
			max = nums[i + 1] - nums[i];
	}
	return max;
}