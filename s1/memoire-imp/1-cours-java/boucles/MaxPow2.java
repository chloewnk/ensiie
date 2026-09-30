public class MaxPow2{
    public static void main(String[] args){
        double pow = 0;
        double max = 2147483647;
        for (int n = 0; n<= max ; n++){
            pow = n*n;
            if(pow!=max){
                break;
            } else{
                System.out.println("ok");
            }

        }
    }
}