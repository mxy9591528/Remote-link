package test1;

import java.util.Scanner;

public class Divideclass {
    public static void main(String[] args) {
        System.out.println("请输入一个三位数");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        while(n!=0)
        {
            System.out.println(n%10);
            n/=10;
        }
    }
}
