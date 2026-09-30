public class Positif {
    public static void main (String[] args){
    
        int a = -1;
        if (a>=0){
            System.out.println("Positif");
        }
        if (a<0){
            System.out.println("Négatif");
        }


        double x , y ;
        x = 340282346638528859811704183484516925440.0 - 1;
        y = 340282346638528859811704183484516925440.0 - 10;
        if (x==y){
            System.out.println("Egaux");
        } else {
            System.out.println("pas égaux");
        }

        double x1 , y2 ;
        x1 = 1/34028234.0;
        y2 = ((1/34028234.0) + 3) - 3;

        if (x1==y2){
            System.out.println("Egaux");
        } else {
            System.out.println("pas égaux");
        }

    }
}