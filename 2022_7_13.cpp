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
				right = mid;//�����е㼴Ϊ��Сֵ�Ŀ��ܣ�Ҫ����
			else
				right--;//�������������
		}
		return rotateArray[left];
	}
};