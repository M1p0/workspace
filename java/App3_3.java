import java.util.*;

public class App3_3
{
    public static void main(String[] args)
    {
        int num;
        while(true)

        {
            System.out.print("请输入一个50到100之间的数:");
            Scanner input=new Scanner(System.in);
            num=input.nextInt();
            if (num>=50&&num<=100)
                break;
        }
        for (int i=1;i<=num ;i++ )
        {
            System.out.print(i+"\t");
        }

    }
}