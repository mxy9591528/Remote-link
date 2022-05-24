/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 将给定数组排序
 * @param arr int整型一维数组 待排序的数组
 * @param arrLen int arr数组长度
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 *
 * C语言声明定义全局变量请加上static，防止重复定义
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
