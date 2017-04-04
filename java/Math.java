import java.util.*;

   //public class math()
   // {
   //     int division(int a,int b)
   //     {
   //         return a/b;
   //     }
   //    float division(float a,float b)
   //     {
   //         return a/b;
   //     }
   // }

public class Math
{

    public static void main(String[] args)
    {
       float division(float a,float b)
        {
            return a/b;
        }

        float result;
        String sourceStr;
        Scanner input=new Scanner(System.in);
        sourceStr=input.nextLine();
        String[] strArray=sourceStr.split("/");
        resylt=division(Double.parseDouble(strArray[0])+Double.parseDouble(strArray[1]));
        System.out.println("="+result);
    }
}