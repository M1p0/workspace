import java.util.*;
public class scanner
{
    public static void main(String[] args)
    {
        String str;
        int num_int;
        double num_double;
        Scanner input=new Scanner(System.in);
        str=input.nextLine();
        num_int=input.nextInt();
        num_double=input.nextDouble();
        System.out.println(str+num_int+num_double);

    }
}