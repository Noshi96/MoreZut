package lab3;

import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        outer: for( int i = 0 ; i < 100 ; i++ ) {
            for( int j = 0 ; j < 100 ; j++ ) {
                //TODO: Add a continuation of the outter loop
                if(j == 50) continue outer;
            }
        }
    }
}

