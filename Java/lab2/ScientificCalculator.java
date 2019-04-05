package lab2;

class ScientificCalculator  {

    final int stala; // ZAD 2 C

    private Calculator calc;
    ScientificCalculator ( ) {
        calc = new Calculator();
        stala = 3+2;    // ZAD 2 C
        //stala = 3+2;    // ZAD 2 A
    }
    public int factorial(int b) throws Exception {
        if(b<0) throw new Exception("Factorial not applicable for negatives");
        if(b==0) return 1;
        //return calc.multiply(b, factorial(b-1)); // odp A
        return b * factorial(b-1);
    }
    public int sumTo(int b) throws Exception {
        if(b<0) throw new Exception("Sum To not applicable for negatives");
        if(b==0) return 0;
        //return calc.add(b, sumTo(b-1)); // Odp B
        return b + sumTo(b-1);
    }
    // ZAD 1 Odp C:
    public int add(int a, int b) {
        return calc.add(a, b);
    }
    // ZAD 1 Odp D:
    public int subtract(int a, int b) {
        return calc.subtract(a, b);
    }
    // ZAD 1 Odp E:
    /*
    public int getVersion() {
        return calc.version;
    }
    */
    public static void main(String[] args){
       // final int DUPSKOPANAJ;


        ScientificCalculator obiekt = new ScientificCalculator();
    }
}


/*
ZAD 1:

Odp A: "multiply ma dostęp prywatny więc się nie możemy do niej odwołać"
Odp B: "Nie podkreśla błędu"
Odp C: "Nie podkreśla błędu"
Odp D: "Nie podkreśla błędu"
Odp D: "version ma dostęp prywatny"


ZAD 2:

Odp A: "Prawda: Nie można modyfikować {linia - 11}"
Odp B: "Falsz: Klasowe zmienne STATYCZNE finalne powinny być pisane z WIELKICH LITER"
Odp C: "PRAWDA: Zmienna finalna musi być zainicjowana, ale nie musi to następować w tej samej lini {linia - 5, 10}, W debugu wartość przed inicjalizacją wynosi 0, Static wymaga inicjalizacji w tej samej lini"
Odp D: "?"
 */