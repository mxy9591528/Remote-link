class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int left = 0, right = rotateArray.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (rotateArray[mid] > rotateArray[right])
				left = mid + 1;
			else if (rotateArray[mid] < rotateArray[right])
				right = mid;//存在中点即为最小值的可能，要保留
			else
				right--;//逐个缩减右区间
		}
		return rotateArray[left];
	}
};