import java.lang.Math;
public class Puissance {
    public static void main (String[]args){
        int i = 0;
        int n = 1548;
        while (!(Math.pow(i,3) <= n && n < Math.pow(i+1,3))){
            i++;
        }
        System.out.println(i);
    }
}