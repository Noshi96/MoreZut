package lab4;

public class zad11 {
    public static int y;
    public static void foo(int x) {
        System.out.print("foo ");
        y = x;
    }
    public static int bar(int z) {
        System.out.print("bar ");
        return y = z;
    }
    public static void main(String [] args ) {
        int t = 0;
        assert t > 0 : bar(7);
        //assert t > 1 : foo(8); /* Line 18 */
        System.out.println("done ");
    }
}