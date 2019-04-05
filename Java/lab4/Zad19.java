package lab4;

import java.util.NoSuchElementException;
import java.util.Scanner;
import static java.lang.System.out;

public class Zad19 {
    public static void main(String[] args){

        try {
            Scanner scn = new Scanner(System.in);
        }
        catch(NoSuchElementException | IllegalStateException ex){
            out.println(ex.getMessage());
        }
        catch(Exception | Error ex2){
            System.exit(0);
        }
    }
}

