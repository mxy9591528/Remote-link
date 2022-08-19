package test1;

import java.util.Scanner;

public class transferclass {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        char[]list={'Ⅰ','Ⅱ','Ⅲ','Ⅳ','Ⅴ','Ⅵ','Ⅶ','Ⅷ','Ⅸ'};
        System.out.println("请输入数字字符串:");
        String s=sc.next();
        StringBuilder res=new StringBuilder();
        if(check(s))
        {
            for(char c:s.toCharArray())
            {
                if(c=='0')
                {
                    res.append("");
                    System.out.println("不能含0");
                    break;
                }
                else
                    res.append(list[c-'1']);
            }
            System.out.println(res);
        }
        else
            System.out.println("输入有误");
    }
    public static boolean check(String str)
    {
        if(str==null)
            return false;
        for(char i:str.toCharArray())
            if(!Character.isDigit(i))
                return false;
        return true;
    }
}
