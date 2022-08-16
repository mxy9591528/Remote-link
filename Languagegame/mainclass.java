package Languagegame;

public class mainclass {
    public static void main(String[] args) {
        Gameclass g1=new Gameclass("郭靖",100,'男');
        Gameclass g2=new Gameclass("黄蓉",100,'女');
        g1.showInfo();
        g2.showInfo();
        while(true)
        {
            g1.attack(g2);
            if(g2.getBlood()==0) {
                System.out.println(g1.getName() + "打败了" + g2.getName());
                break;
            }
            g2.attack(g1);
            if(g1.getBlood()==0) {
                System.out.println(g2.getName() + "打败了" + g1.getName());
                break;
            }
        }
    }
}
