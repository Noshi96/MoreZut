package lab2;

public class Birdo {
    Birdo(String name){
        System.out.println("Bird Name = " + name);
    }

    Birdo () {
        this("Starling");
        System.out.println("Constructor Bird.class");
    }

    public static void main(String args[]){
        Birdo a = new Birdo();
    }
}
