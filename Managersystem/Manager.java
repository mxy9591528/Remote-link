package Managersystem;

import java.util.Scanner;

public class Manager {
    private Student[] s;
    private int size;
    public Manager() {
        this.size=0;
        this.s=new Student[100];
    }
    public int findid(String id)
    {
        for(int i=0;i<this.size;i++) {
            if (this.s[i].getId().equals(id))
                return i;
        }
        return -1;
    }
    public void add()
    {
        int age;
        String id,name;
        Scanner sc=new Scanner(System.in);
        while(true) {
            System.out.println("请输入学号:");
            while(true) {
                id = sc.next();
                if(this.findid(id)!=-1) 
                    System.out.println("学号重复请重新输入:");
                else
                    break;
            }
            System.out.println("请输入姓名:");
            name=sc.next();
            System.out.println("请输入年龄:");
            age=sc.nextInt();
            Student s=new Student(id,name,age);
            this.s[this.size++]=s;
            System.out.println("录入成功，是否继续添加:y/n");
            String choice=sc.next();
            if(choice=="y")
                ;
            else
                break;
        }
        this.show();
    }
    public void show(){
        for(int i=0;i<this.size;i++)
            System.out.printf("学号:%s\t姓名:%s\t年龄:%d\n",this.s[i].getId(),this.s[i].getName(),this.s[i].getAge());
    }
    public void delete(){
        Scanner sc=new Scanner(System.in);
        System.out.println("请输入需要删除的学生的学号:");
        String id=sc.next();
        int index=findid(id);
        if(index!=-1){
            for(int i=index;i<this.size-1;i++)
                this.s[i]=this.s[i+1];
            this.size--;
            System.out.println("删除成功!");
            this.show();
        }
        else
            System.out.println("无此人信息");
    }
    public void search(){
        Scanner sc=new Scanner(System.in);
        System.out.println("请输入要查询的学生的学号:");
        String id=sc.next();
        int index=findid(id);
        if(index!=-1){
            if(this.s[index].getId().equals("heima002"))
                this.s[index].setAge(this.s[index].getAge()+1);
            System.out.printf("学号:%s\t姓名:%s\t年龄:%d\n",this.s[index].getId(),this.s[index].getName(),this.s[index].getAge());
        }
        else
            System.out.println("无此人信息");
    }
    public void menu(){
        System.out.println("1.添加学生信息");
        System.out.println("2.删除学生信息");
        System.out.println("3.查找学生信息");
        System.out.println("4.显示学生信息");
        System.out.println("0.退出");
    }

}
