public class TableDeMultiplication{
    public static void main(String[] args){
        String argument = args[0];
        System.out.println(argument);
        int nb = Integer.parseInt(argument);
        int res;

        for (int i = 0 ; i<=10; i++){
            res = i * nb;
            System.out.println(res+"\n");
        }
    }
}