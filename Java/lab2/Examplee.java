package lab2;

public class Examplee {
    Examplee(){}
    Examplee(int i){
        System.out.println("Constructor Example#" + i);
    }
    public static void main(String args[]){
        for (int i=0; i<10; i++){
            new Examplee(i);
        }
    }
}
