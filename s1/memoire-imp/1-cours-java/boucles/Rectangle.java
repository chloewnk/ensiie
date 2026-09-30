public class Rectangle {
    public static void main (String[]args){
        String argument = args[0];
        int n = Integer.parseInt(argument);
        for (int i = 0 ; i<n ; i++){
            System.out.print("*");
        }
        System.out.println(" ");
        for (int i = 0 ; i <(n-2) ; i++){
            System.out.print("*");
            for (int y = 0 ; y<(n-2); y++){ 
                System.out.print(" ");
            }
            System.out.println("*");
        }
        for (int i = 0 ; i<n ; i++){
            System.out.print("*");
        }

    }
}