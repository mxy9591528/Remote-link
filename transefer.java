package test1;

import java.util.Scanner;

public class transefer {
    public static void main(String[] args) {
        String list1="零壹贰叁肆伍陆柒捌玖";
        String list2="十百千万十百千亿十百千万亿";
        System.out.println("请输入数字:");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        StringBuilder res=new StringBuilder("元");
        int cnt=0;
        while(n!=0)
        {
            res.append(list1.charAt(n % 10));
            n/=10;
            if(n!=0)
                res.append(list2.charAt(cnt++));
        }
        System.out.println("转换后为:");
        res.reverse();
        System.out.println(res);
    }
}
