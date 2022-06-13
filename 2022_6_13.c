#include<stdio.h>
int half(int left, int right, int key,int*a)  
{
	if (left < right)
	{
		int mid = (left + right) / 2;    
		if (a[mid] == key)      
			return mid;
		else if (a[mid] > key)     
			return half(left, mid - 1, key,a);   
		else                            
			return half(mid + 1, right, key,a);   
	}
	return -1;
}
