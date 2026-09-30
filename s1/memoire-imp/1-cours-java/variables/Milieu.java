public class Milieu {
    public static void main(String[] args){
        float x1 = 0.1f;
        float x2 = 0.2f;
        float y1 = 0.3f;
        float y2 = 0.4f;

        System.out.println("Points 1 : ("+x1+","+y1+")");
        System.out.println("Points 2 : ("+x2+","+y2+")");

        float milieuX = (x1+x2)/2;
        float milieuY = (y1+y2)/2;
        System.out.println("Milieu: ("+milieuX+","+milieuY+")");



    }
}