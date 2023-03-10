* C#μ Main() λ©μλ
   -->   If we want, we can change the name of the Program class to something else, but the Main()
         method must be called Main(). The Main() method must be present in all C# programs.
         
  π΅ Fields : A field is simply a variable that is declared inside a class.
  
        private string nameOfStaff;
        private const int hourlyRate = 30;
        private int hWorked;                      νμ¬ μ΄λ κ² μΆκ°νλ€.
        
        π  μ±μμλ μ μ°λ¦¬κ° μ κ·Ό μ μ΄μμΈ privateλ₯Ό μ¬μ©ν μ΄μ μ λν΄ μ€λͺν΄μ€λ€.

        Notice that there is a word private in front of each declaration statement?
        This is known as an access modifier. Access modifiers are like gate
        keepers, they control who has access to that field (i.e. who can read and 
        modify the value of that field).           
                                                     // i.e. : λ€μ λ§ν΄μ
                                                     
        There are two reasons why we do not want the three fields to be accessible outside the class.
        
     1. The first reason is that there is no need for other classes to know about those fields.
        // μ²« λ²μ§Έ μ΄μ λ λ€λ₯Έ ν΄λμ€μμ μ΄κ³³ ν΄λμ€μ νλλ₯Ό μ νμκ° μλ€.
        
        * μΊ‘μνμ λν κ°λ΅ν μ€λͺ
        This is known as encapsulation. Encapsulation enables an object to hide
        data and behaviour from other classes that do not need to know about them.
        This makes it easier for us to make changes to our code in future if
        necessary. We can safely change the value of hourlyRate inside Staff class
        without affecting other classes.
        
        // Encapsulation : μΊ‘μν    (μΊ‘μνλ μλμ±μ ν¬ν¨νκ³  μμ)
        
     2. The second reason for declaring a field as private is that we do not want 
        other classes to freely modify them. 
        This helps to prevent the fields from being corrupted.
        // privateλ‘ μ μΈν λ λ²μ§Έ μ΄μ λ, λ€λ₯Έ ν΄λμ€μμ μ΄κ²λ€μ μμ λ‘­κ² μμ νλ κ²μ μμΉ μκΈ° λλ¬Έμ΄λ€.
           μ΄κ²μ νλκ° λΆν¨λλ κ²μ λ°©μ§ν΄μ€λ€.
        
        
  π΅ Properties 
      
    --> A property is commonly used to provide access to a private field in cases where the field is needed by other classes.
    
   β μ¬κΈ°μ λλ μλ¬Έμ ) private μ κ·Ό μ νμλ₯Ό μ¬μ©νμΌλ©΄μ μ νλ‘νΌν°λ₯Ό μ¬μ©ν΄μ μ κ·Όμ΄ κ°λ₯νλλ‘ νλ κ±ΈκΉ???
     
        This may sound like a contradiction. Earlier, we mentioned that we use private fields so that other
        classes do not have access to them. If that is the case, why are we allowing
        access to them via properties?            
                                               * contradiction λ» : λͺ¨μ
  
        μ¬κΈ°μ λν μλ¬Έμ μ΄μ§ μλ €μ€λ€.
        
        One of the main reasons is that using properties gives us greater control
        over what rights other classes have when assessing these private fields.
        Weβll see how to do that later.  
        // νλ‘νΌν°λ₯Ό μ¬μ©νλ©΄ μ°λ¦¬λ μ»€λ€λ κΆνμ μ»λλ€.  private νλλ₯Ό ν λΉν  λ λ€λ₯Έ ν΄λμ€λ€μ΄ κ°μ§λ κΆνμ λ§μ΄λ€.
  
--------------------

   // A property contains two special methods known as accessors. The first accessor is a getter and the second is a setter.
   
using System;

class circle
{
    private int x;
    private int y;
    private double radius;

    public int X   // νλ‘νΌν° μ΄λ¦ : X
    {
        get { return x; }
        set { x = value; }      // value is a keyword when it used inside a setter.
    }

    public int Y  // νλ‘νΌν° μ΄λ¦ : Y
    {
        get { return y; }
        set { y = value; }
    }

    public double Radius  // νλ‘νΌν° μ΄λ¦ : Radius
    {
        get { return radius; }
        set { radius = value; }
    }
}
class C_sharp_book
{
    public static void Main()
    {
        circle c1 = new circle();
        circle c2 = new circle();

        c1.X = 13;
        c1.Y = 50;
        c1.Radius = 10.62;

        c2.X = 10;
        c2.Y = 15;
        c2.Radius = 20.52;

        Console.WriteLine("c1μ μ€μ¬μ : {0}, {1}\nc1μ λ°μ§λ¦: {2}", c1.X, c1.Y, c1.Radius);
        Console.WriteLine("---------------------------------------");
        Console.WriteLine("c2μ μ€μ¬μ : {0}, {1}\nc2μ λ°μ§λ¦: {2}", c2.X, c2.Y, c2.Radius);
    }
}
--------------------  
                                    μ΄λ κ² μ€μΌ μλ μλ€. 
using System;

class circle
{                             // λ°λ‘ private νλλ₯Ό μ μΈν΄μ£Όμ§ μμλ λλ€.
    public int X 
    {
        get;            // μλκ΅¬ν νλ‘νΌν°λΌκ³  νλ€. (Auto-implemented Properties)
        set;
    }

    public int Y
    {
        get;
        set;
    }

    public double Radius
    {
        get;
        set;
    }
}
class C_sharp_book
{
    public static void Main()
    {
        circle c1 = new circle();
        circle c2 = new circle();

        c1.X = 13;
        c1.Y = 50;
        c1.Radius = 10.62;

        c2.X = 10;
        c2.Y = 15;
        c2.Radius = 20.52;

        Console.WriteLine("c1μ μ€μ¬μ : {0}, {1}\nc1μ λ°μ§λ¦: {2}", c1.X, c1.Y, c1.Radius);
        Console.WriteLine("---------------------------------------");
        Console.WriteLine("c2μ μ€μ¬μ : {0}, {1}\nc2μ λ°μ§λ¦: {2}", c2.X, c2.Y, c2.Radius);
    }
}
  
           νλ‘νΌν°μ λνμ¬ λμμ΄ λλ λΈλ‘κ·Έ : https://dev-junwoo.tistory.com/93#3.%20Private%20Set%20/%20init
                                                 https://constructionsite.tistory.com/38
  
-------------------------------------
   
  π΅ Overloading
  
        --> μ€λ²λ‘λ©μ νλμ λ©μλ μ΄λ¦μΌλ‘ μ¬λ¬ λ©μλλ₯Ό κ΅¬ννλ κ²μ λ§νλ€.
   
          1. ν¨μμ μ΄λ¦μ κ°κ² νλ€.
          2. κ°κ° ν¨μμ λ§€κ°λ³μλ₯Ό λ€λ₯΄κ² νλ€.
  
 using System;

class calculator
{
    static public int add(int a, int b)
    {
        return a + b;
    }
    static public int add(int a, int b, int c)
    {
        return a + b + c;
    }
    static public double add(double a, double b)
    {
        return a + b;
    }

}
class C_sharp_book
{
    public static void Main()
    {
        Console.WriteLine(calculator.add(5, 3));
        Console.WriteLine(calculator.add(2, 1, 50));
        Console.WriteLine(calculator.add(3.13, 4.52));
    }
} 
  
  
  π΅ The ToString() method
  
      -->  The ToString() method is a special method that returns a string that represents the current class.
           // ToString() λ©μλλ νμ¬μ ν΄λμ€λ₯Ό λννλ λ¬Έμμ΄μ λ°ννλ νΉλ³ν λ©μλμ΄λ€.
          
    (* Objectλ λͺ¨λ  ν΄λμ€μ μ΅μμ ν΄λμ€μ΄λ€. C#μ κ±°μ λͺ¨λ  μλ£νμ System.Objectλ‘ λΆν° μμλ°λλ€.)
                                  
      β C#μλ System λ€μμ€νμ΄μ€ μμ  "public class Object"λ‘ Object ν΄λμ€κ° μ μλμ΄ μλλ°
      
          μ΄ μμλ μ¬λ¬ λ©μλλ€μ΄ μλ€.
            
            1  Equals(Object)

            2	Equals(Object,Object)

            3	Finalize()

            4	GetHashCode()

            5	GetType()

            6	MemberwiseClone()

            7	ReferenceEquals(Object,Object)

            8	ToString()
                                             μ΄λ κ² λ§μ΄λ€.
     
          μ΄ μ±μμλ κ·Έμ€ νλμΈ ToString() λ©μλλ₯Ό μκ°μμΌμ€λ€.
   
                                                       λμλλ λΈλ‘κ·Έ: https://kangworld.tistory.com/190 
  
       β Override : λ΄κ° μ΄ν΄ν λ°λ‘λ λΆλͺ¨ ν΄λμ€λ‘λΆν° μμλ°μ λ©μλλ₯Ό λ€μ μ¬μ μνκ³  μΆμ λ
                      μ€λ²λΌμ΄λλ₯Ό μ¬μ©νλ κ²μΌλ‘ λ³΄μΈλ€.
      
          *Override λ»: to decide against or refuse to accept a previous decision, an order, a person, etc.:
-------------------------           
using System; 
class Minus
{
    public int minus(int a, int b)
    {
        return a - b;
    }
}
class Add
{
    public int add(int a, int b)
    {
        return a + b + c;
    }
    public override string ToString()       // μ€λ²λΌμ΄λ©
    {
        return "This is Overriding";
    }
}
class C_sharp_book
{
    public static void Main()
    {
        object a = 5;
        Console.WriteLine(a);
        object b = "Hello";
        Console.WriteLine(b);

        Add add = new Add();
        Minus minus = new Minus();

        Console.WriteLine(add);                 // "This is Overriding" μΆλ ₯
        Console.WriteLine(add.ToString());      // "This is Overriding" μΆλ ₯
        Console.WriteLine(minus);               // "Minus" μΆλ ₯
        Console.WriteLine(minus.ToString());    // "Minus" μΆλ ₯
    }
}
-------------------------  
  
 β Overriding ν λ€λ₯Έ μμ
 
using System; 
class Minus
{
    public virtual int minus(int a, int b)  // virtual ν΄λμ€λ μμ ν΄λμ€μμ μ΄ ν¨μλ₯Ό μ¬μ μνλλ‘ νμ©ν΄μ£Όλ ν€μλμ΄λ€.
    {
        return a - b;
    }
}
class Add : Minus
{
    public int c;
    public override int minus(int a, int b)
    {
        return a - b + c;
    }
    public int add(int a, int b)
    {
        return a + b + c;
    }
    public override string ToString()
    {
        return "This is Overriding";
    }
}
class C_sharp_book
{
    public static void Main()
    {
        Add add = new Add();
        Minus minus = new Minus();

        add.c = 5;

        Console.WriteLine(minus.minus(100, 88));   // 12 μΆλ ₯
        Console.WriteLine(add.minus(100, 88));     // 17 μΆλ ₯
    } 
}
  
  
  π΅ Constructors (μμ±μ)
       
      --> It is the first method that is called whenever we create a object from our class. 
          // μμ±μλ μ°λ¦¬κ° ν΄λμ€λ‘λΆν° κ°μ²΄λ₯Ό νΈμΆν  λ μΈμ λ νΈμΆλλ μ²« λ²μ§Έ λ©μλμ΄λ€.
   
            A constructor always has the same name as the class 
            and does not return any value. We do not need to use the void keyword
            when declaring a constructor.

            Declaring a constructor is optional. If you do not declare your own
            constructor, C# creates one for you automatically. The default constructor
            simply initializes all the fields in the class to default values, which is
            normally zero for numeral fields and empty string for string fields.

--------------------------- 
using System; 

class SayHello
{
    public SayHello()
    {
        Console.WriteLine("Hello");
    }
}
class C_sharp_book
{
    public static void Main()
    {
        SayHello hello = new SayHello();   // "Hello" μΆλ ₯
    }
---------------------------  

using System; 

class SayHello
{
    public SayHello(string MyName)
    {
        Console.WriteLine("Hello "+ MyName);
    }
}
class C_sharp_book
{
    public static void Main()
    {
        SayHello hello = new SayHello("μ νμ±");  // "Hello μ νμ±" μΆλ ₯
    }
}
----------------------------
   
  π΅ Static Keyword

         Previously, we looked at how we can use the Staff class to create our
         staff1, staff2 and staff3 objects. However, there are some classes or
         class members that can be accessed without the need to create any objects.
         These are known as static classes or class members and are declared using
         the static keyword.
            
using System; 

class ThisIsStatic
{
    public static int a;
    public static int pro { get; set; }

    public static double Func(double a, double b)
    {
        return a + b;
    }
}
class C_sharp_book
{
    public static void Main()
    {
        Console.WriteLine("a = " + ThisIsStatic.a);    // 0 μΆλ ₯
        ThisIsStatic.a = 5;
        Console.WriteLine("a = " + ThisIsStatic.a);    // 5μΆλ ₯

        ThisIsStatic.pro = 3;
        Console.WriteLine("pro = " + ThisIsStatic.pro);  // 3 μΆλ ₯ 

        Console.WriteLine("Func() = " + ThisIsStatic.Func(3.15, 152.35));  // 155.5 μΆλ ₯
    }
}


   
  π΅ Using Arrays and Lists
     
-------------     
using System;

class Array
{
    public static void A(int[] a)
    {
        for (int i = 0; i < a.Length; i++)
        {
            Console.Write(a[i]);
        }
    }
}
class C_sharp_book
{
    public static void Main()
    {
        int[] a = { 1, 2, 3, 4, 5, 6, 7 };

        Array.A(a);   // 1234567 μΆλ ₯
    }
}
-------------     
                   β Listλ ν¬κΈ°λ₯Ό μ νμ§ μμ λ°°μ΄μ΄λΌκ³  μκ°νλ©΄ λλ€. λμ μΌλ‘ ν¬κΈ°λ₯Ό μ‘°μ ν  μ μλ€.
using System; 

class MyList
{
    public static void A(List<int> a)
    {
        for (int i = 0; i < 10; i++)
        {
            a.Add(i + 1);     //  i + 1κ°μ μ μ₯ν΄μ€λ€.
            Console.Write(a[i]);  // 12345678910 μΆλ ₯
        }

        foreach (int i in a)
        {
            Console.Write(i);  // 12345678910 μΆλ ₯
        }
    }
}
class C_sharp_book
{
    public static void Main()
    {
        List<int> mylist = new List<int>();
        MyList.A(mylist);
    }
}  

----------------------
 
using System;           β λ©μλμ λ°νκ°μ λ°°μ΄λ‘ μ μΈ
 
class MyArray
{
    public static int[] Array()
    {
        int [] array = new int[5];

        for(int i = 0; i < array.Length; i++)
        {
            array[i] = Convert.ToInt32(Console.ReadLine());    // λ°°μ΄μ κ°μ μλ ₯ν΄μ€
        }

        return array;  // λ°°μ΄μ λ°νν¨
    }
}
class C_sharp_book
{
    public static void Main()
    {
        int[] aa = MyArray.Array();       // aaμ κ°μ μ λ¬ν¨
       
        for(int i = 0; i < aa.Length;i++)
        {
            Console.WriteLine(aa[i]);   // 
        }    
    }
}
----------------------
 
using System;           β λ¦¬μ€νΈμ λ°νκ°μ λ°°μ΄λ‘ μ μΈ

class MyList
{
    public static List<int> List()      // λ¦¬μ€νΈλ₯Ό λ°νν΄μ£Όλ ν¨μ μ μΈ 
    {
        List<int> mylist = new List<int>();   
        int input = 0;

        for(int i = 0; i < 5; i++)
        {
            input = Convert.ToInt32(Console.ReadLine()); 
            mylist.Add(input);
        }

        return mylist;
    }
}
class C_sharp_book
{
    public static void Main()
    {
        List<int> list = MyList.List();    // listμ mylistκ° μ λ¬

        for(int i = 0; i < list.Count; i++)
        {
            Console.WriteLine(list[i]);
        }
    }
}
     
     

  π΅ Using params keyword
     
       --> params ν€μλλ₯Ό μ¬μ©νλ©΄ μμ μ΄ μνλ λ§νΌ, κ°μμ μ ν μμ΄ λ§€κ°λ³μλ₯Ό μ λ¬ ν  μ μλ€.
     
  -------------------------------------------------------------------------------------------------------------------------------   
     βΌ C# params κ·μΉ: 1. μ μΈλΆμμΒ params ν€μλλ νμ λ§¨ μμ μμΌν©λλ€.: 
                       2. κ°λ³μΈμ λ§€κ°λ³μλ₯Ό μ μΈν λλ [] λ₯Ό μ΄μ©ν΄μΒ 1μ°¨μ λ°°μ΄λ‘ μ μΈν΄μΌν©λλ€.: 
                       3. λ°μ΄ν° νμμ΄ μ λ§€ν λλ λͺ¨λ  ν΄λμ€μ μ΅μμ ν΄λμ€μΈ object ν΄λμ€ λ°°μ΄λ‘ ν΄λ λ©λλ€.Β 
                                           
                                              μΆμ²: https://blockdmask.tistory.com/317 [κ°λ°μ μ§λ§μ:ν°μ€ν λ¦¬]
   -------------------------------------------------------------------------------------------------------------------------------
           
      Next, letβs explore the params keyword. The params keyword is useful
      when we do not know the number of arguments a method has. For instance,
      we may have a method that prints a series of names, but we do not know
      how many names there are in advance. In cases like this, we can use an
      array as the parameter and add the params keyword in front of it.
     
---------------
using System; 

class ParamsFunc
{
    public static void PrintNames(params string[] names)  // params ν€μλλ₯Ό μ¬μ©νμ¬ stringνμ μ΄λ¦μ μ λ¬λ°μ
    {
        for (int i = 0; i < names.Length; i++)
        {
            Console.Write(names[i] + " ");
        }
        Console.WriteLine();
    }

}
class C_sharp_book
{
    public static void Main()
    {
        ParamsFunc.PrintNames("μ νμ±");
        ParamsFunc.PrintNames("μ νμ±", "μ΄λ³κ±΄");
        ParamsFunc.PrintNames("μ νμ±", "μ΄λ³κ±΄", "μ£ΌνΈλ―Ό");
    }
}
---------------

               β object ν΄λμ€λ₯Ό ν
using System; 

class ParamsFunc
{
    public static void PrintFile(params object[] file)
    {
        for (int i = 0; i < file.Length; i++)
        {
            Console.Write(file[i] + " ");
        }
        Console.WriteLine();
    }

}
class C_sharp_book
{
    public static void Main()
    {
        ParamsFunc.PrintFile("μ νμ±");
        ParamsFunc.PrintFile("μ νμ±", 171.3);
        ParamsFunc.PrintFile("μ νμ±", 171.3, 68);
    }
}
     
     
