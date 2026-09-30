public class Cylindre {
    public double perimetre (double r) {
        double calc = 2*Math.PI*r;
        return calc;
    }
    public double aire (double r){
        Cylindre c = new Cylindre();
        double calc = (c.perimetre(r))/(2*Math.PI);
        return calc;
    }
    public double volume (double r, double h){
        Cylindre c = new Cylindre();
        double calcAire = 2*c.aire(r)+c.perimetre(r);
        double calcVolume = c.aire(r)*h;
        return calcVolume;
    }
    public static void main (String[] args){
        Cylindre c = new Cylindre();
        double res = c.volume(18,30);
        System.out.println(res);

    }
}