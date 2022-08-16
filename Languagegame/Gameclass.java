package Languagegame;

import java.util.Random;

public class Gameclass {
    private String name;
    private int blood;
    private char gender;
    private String face;
    String[] boyface={"风流倜傥","气宇轩昂","相貌英俊","五官端正","相貌平平","一塌糊涂","面目狰狞"};
    String[] girlface={"美奂绝伦","沉鱼落雁","亭亭玉立","相貌平平","相貌丑陋","惨不忍睹"};
    String[] attacks_dis= {
            "%s使出了一招【龙爪手】，转到对方身后，一爪向%s的天灵盖抓去。",
            "%s使出一招【降龙十八掌】，腾身飞空中使出的十八掌化为神龙向%s冲去。",
            "%s大喝一声，伏身于地，脸两颊鼓起，宛如一只蛤蟆，一招【蛤蟆功】，扑向%s。",
            "%s运气于掌，一瞬间掌心变得乌黑，一式【铁砂掌】，推向%s。",
            "%s屏息凝神，以掌为刀，使用【日之呼吸•火之神神樂】，向%s劈砍而去。",
            "%s咬破手指，使用【巨人之力】,化身进击的巨人向%s踩去。"
    };
    String[] injureds_dis={
            "结果%s退了半步，毫发无损。",
            "结果给%s造成一处瘀伤。",
            "结果一击命中，%s疼的弯下腰。",
            "结果%s痛苦的闷哼一声，显然受了点内伤。",
            "结果%s摇摇晃晃，一跤摔倒在地。",
            "结果%s脸色一下变得惨白，连退了好几步。",
            "结果【轰】的一声，%s口中鲜血狂喷而出。",
            "结果%s惨叫一声，像滩软泥般塌了下去。"
    };

    public Gameclass() {
    }

    public Gameclass(String name, int blood, char gender) {
        this.name = name;
        this.blood = blood;
        this.gender=gender;
        this.setFace(gender);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getBlood() {
        return blood;
    }

    public void setBlood(int blood) {
        this.blood = blood;
    }

    public char getGender() {
        return gender;
    }

    public void setGender(char gender) {
        this.gender = gender;
    }

    public String getFace() {
        return face;
    }

    public void setFace(char gender) {
        Random r=new Random();
        if(gender=='男') {
           int index = r.nextInt(boyface.length);
           this.face=boyface[index];
        }
        else if(gender=='女')
        {
            int index=r.nextInt(girlface.length);
            this.face=girlface[index];
        }
        else
            this.face="无相之相";
    }

    public void attack(Gameclass g){
        Random r=new Random();
        int index=r.nextInt(attacks_dis.length);
        String kungfu=attacks_dis[index];
        System.out.printf(kungfu,this.getName(),g.getName());
        System.out.println('\n');
        int hurt=r.nextInt(20)+1;
        int remainblood=g.getBlood()-hurt;
        remainblood=remainblood<0?0:remainblood;
        g.setBlood(remainblood);
        if(remainblood>90)
            System.out.printf(injureds_dis[0],g.getName());
        else if(remainblood>80)
            System.out.printf(injureds_dis[1],g.getName());
        else if(remainblood>70)
            System.out.printf(injureds_dis[2],g.getName());
        else if(remainblood>60)
            System.out.printf(injureds_dis[3],g.getName());
        else if(remainblood>40)
            System.out.printf(injureds_dis[4],g.getName());
        else if(remainblood>20)
            System.out.printf(injureds_dis[5],g.getName());
        else if(remainblood>10)
            System.out.printf(injureds_dis[6],g.getName());
        else
            System.out.printf(injureds_dis[7],g.getName());
        System.out.println('\n');
    }

    public void showInfo(){
        System.out.println("姓名:"+this.getName());
        System.out.println("血量:"+this.getBlood());
        System.out.println("性别:"+this.getGender());
        System.out.println("相貌:"+this.getFace());
    }
}
