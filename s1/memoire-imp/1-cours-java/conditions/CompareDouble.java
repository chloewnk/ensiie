public class CompareDouble{
    public static void main (String[] args){
        double x1 , y2 ;
        x1 = 1/34028234.0;
        y2 = ((1/34028234.0) + 3) - 3;

        
        if ((Math.abs(x1)-Math.abs(y2))<=0.001){
            System.out.println("Egaux");
        } else {
            System.out.println("pas égaux");
        }
    }
}