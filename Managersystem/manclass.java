package Managersystem;

import java.util.Scanner;

public class manclass {
    public static void main(String[] args) {
        Manager m = new Manager();
        while(true) {
            m.menu();
            Scanner sc = new Scanner(System.in);
            System.out.println("请选择:");
            int choice = sc.nextInt();
            switch (choice)
            {
                case 1:m.add();break;
                case 2:m.delete();break;
                case 3:m.search();break;
                case 4:m.show();break;
                case 0:System.exit(0);
            }
        }
    }
}
