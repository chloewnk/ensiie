public class Triangle{
    public void affiche (int n){
        int taille = 2*n-1;
        for(int i = 0; i<taille; i++){
            System.out.print("*");
        }
        System.out.println("");
        for (int i = 0 ; i<n; i++){
            System.out.print("*");
            for (int j = 0 ; j<n-i-2; j++){
                System.out.print(" ");
            }
            System.out.println("*");
        }
    }
    public static void main(String[] args){
        Triangle t = new Triangle();
        t.affiche(4);
    }
}