import java.lang.Math;
public class Gravite{

    public double calcul (int m1, int m2, int d){
        double g = 6.67*Math.pow(10,-11);
        double equation = g*m1*m2/Math.pow(d,2);
        return equation;
    }
    public static void main(String[]args){
        Gravite g = new Gravite();
        double res = g.calcul(40,17,8);
        System.out.println(res);

    }
}