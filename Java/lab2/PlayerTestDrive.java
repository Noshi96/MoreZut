package lab2;

class Player {
    static int playerCount = 0;
    private String name;

    public Player(String n){
        name = n;
        playerCount++;
    }
}
public class PlayerTestDrive {
    public static void main(String args[]){
        System.out.println(Player.playerCount);
        Player one = new Player("Tommy");
        System.out.println(Player.playerCount);
    }
}
