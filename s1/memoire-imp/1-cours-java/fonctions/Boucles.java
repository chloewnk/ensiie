public class Boucles{
    public void table(int n){
        for (int i = 0; i<=n; i++){
            System.out.println(i*n);
        }
    }
    public double log (int n, int d){
        double res = Math.log(n) / Math.log(d);
        return res;
    }
    public static void main(String[] args){
        Boucles b = new Boucles();
        b.table(5);
        double res = b.log(5,3);
        System.out.println(res);

    }
}