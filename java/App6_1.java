class Student
{
    private String name;
    private int age;

    public Student()
    {
        System.out.println("无参数");
    }

    public Student(int data)
    {
        age=data;
        System.out.println("一个参数");
    }

    public Student(String data)
    {
        name=data;
        System.out.println("一个参数");
    }


    public Student(int data1,String data2)
    {
        age=data1;
        name=data2;
        System.out.println("两个参数");
    }

}


public class App6_1
{
    public static void main(String[] args)
    {
        Student stu=new Student(1,"lx");
    }




}