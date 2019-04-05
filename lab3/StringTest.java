package lab3;

public class StringTest {
    public static void main(String[] args) {
        String s1 = "Anthony";
        String s2 = "Anthony";
        String s3 = new String("Muller");
        String s4 = new String("Muller");

        if (s1 == s2) {
            System.out.print("Anthony");
        }

        if (s3 == s4) {
            System.out.print("Muller");
        }
    }
}