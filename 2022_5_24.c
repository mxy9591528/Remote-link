/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 * ��������������
 * @param arr int����һά���� �����������
 * @param arrLen int arr���鳤��
 * @return int����һά����
 * @return int* returnSize ������������
 *
 * C������������ȫ�ֱ��������static����ֹ�ظ�����
 *
 * C������������ȫ�ֱ��������static����ֹ�ظ�����
 */
#define BASE 10
void RadixSort(int*a,int n)
{
    int*temp=(int*)malloc(sizeof(int)*n);
    int max=a[0],gap=1;
    for(int i=1;i<n;i++)
        if(a[i]>max)
            max=a[i];
    while(max/gap>0)
    {
        int*bucket=(int*)calloc(BASE,sizeof(int));
        for(int i=0;i<n;i++)
            bucket[(a[i]/gap)%BASE]++;
        for(int i=1;i<BASE;i++)
            bucket[i]+=bucket[i-1];
        for(int i=n-1;i>=0;i--)
            temp[--bucket[(a[i]/gap)%BASE]]=a[i];
        for(int i=0;i<n;i++)
            a[i]=temp[i];
        gap*=BASE;
    }
    free(temp);
}
int compare(int*e1,int*e2)
{
    return *e1-*e2;
}
int* MySort(int* arr, int arrLen, int* returnSize ) {
    // write code here
    qsort(arr,arrLen,sizeof(int),compare);
    *returnSize=arrLen;
    return arr;
}
