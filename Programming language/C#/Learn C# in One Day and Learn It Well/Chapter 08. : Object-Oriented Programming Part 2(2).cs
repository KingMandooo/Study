
π΅ GetType() and typeof()
   
    --> The GetType() method returns the runtime type of an object.
    
        The typeof() method takes the name of a data type (e.g. int, float, or the
        name of a class) and returns the type of that name, which we can then
        compare with the result of the GetType() method on the left.
        
        μ λ¦¬νμλ©΄ GetType()λ μΈμ€ν΄μ€μ νμμ νΈμΆνκ³ , 
        typeof()λ ν΄λμ€μ νμμ νΈμΆνλ€.
        
---------------------------------------     
                                    * μμ ν΄λμ€λ€μ μλ΅.
class C_sharp_book
{
    public static void Main()
    {

        Member[] clubMembers = new Member[5];    // We declare an array of Member type and add 5 members.

        clubMembers[0] = new NormalMember("Special Rate", "James", 1, 2010);
        clubMembers[1] = new NormalMember("Normal Rate", "Andy", 2, 2011);
        clubMembers[2] = new NormalMember("Normal Rate", "Bill", 3, 2011);
        clubMembers[3] = new VIPMember("Carol", 4, 2012);
        clubMembers[4] = new VIPMember("Evelyn", 5, 2012);

        foreach (Member m in clubMembers)
        {
            m.CalculateAnnualFee();
            Console.WriteLine(m.ToString());
        }

        if (clubMembers[0].GetType() == typeof(VIPMember))    // NO μΆλ ₯
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
            
        Console.WriteLine(clubMembers[0].GetType());      // NormalMember μΆλ ₯
        Console.WriteLine(clubMembers[4].GetType());      // VIPMember μΆλ ₯
        Console.WriteLine(typeof(NormalMember));          // NormalMember μΆλ ₯
        Console.WriteLine(typeof(VIPMember));             // VIPMember μΆλ ₯
    }
}

------------------------

π΅ Abstract Classes and Methods

   --> μΆμ ν΄λμ€λ μΈμ€ν΄μ€λ₯Ό μμ±ν  μ μλ ν΄λμ€μ΄λ€.
       ν΄λμ€ μ μΈλ¬Έμ abstract μ§μ μλ₯Ό λΆμ΄λ©΄ μΆμ ν΄λμ€κ° λλ€.
       
       μΆμ λ©μλλ κ΅¬ν μ½λλ₯Ό κ°μ§μ§ μμ λ©μλλ₯Ό λ§νλ€.
       μΆμ λ©μλλ abstract μ§μ μλ₯Ό λΆμ΄κ³  λ§€κ°λ³μμ λ¦¬ν΄ νμμ κ°μ§μ§λ§
       λ³Έμ²΄λ κ°μ§μ§ μκ³  μΈλ―Έν΄λ‘ μΌλ‘ λλΈλ€.
   
       μΆμ λ©μλλ μ½λλ₯Ό μ μνμ§ μμΌλ―λ‘ νμ ν΄λμ€μμ μ¬μ μν΄μΌμ§λ§ νΈμΆμ΄ κ°λ₯νλ€.
       νμ ν΄λμ€μμ λ°λμ μ¬μ μν΄μΌ νλ―λ‘ virtualλ₯Ό λΆμ΄μ§ μμλ μλμΌλ‘ κ°μμ΄λ€.
   
       μΆμ λ©μλκ° νλλΌλ μ μΈλμ΄μμΌλ©΄ κ·Έ ν΄λμ€ λν λ¬΄μ‘°κ±΄ μΆμμ΄μ΄μΌνλ€.
   
-----------------------
   
using System;

abstract class MyAbstractClass                      // μΆμ ν΄λμ€ MyAbstractClass μ μΈ
{ 
    private string message = "Hello C#";
    public void PrintMessage()
    {
        Console.WriteLine(message);
    }
    public abstract void PrintMessageAbstract();     // μΆμ λ©μλ PrintMessageAbstract μ μΈ
}

class ClassA : MyAbstractClass                // μΆμ ν΄λμ€ MyAbstractClassλ₯Ό μμλ°μ
{
    public override void PrintMessageAbstract()       // μΆμ λ©μλ PrintMessageAbstract() μ€λ²λΌμ΄λ©
    {
        Console.WriteLine("C# is fun!!");
    }
}

class C_sharp_book
{
    public static void Main()
    {
        //MyAbstractClass abClass = new MyAbstractClass();    <-- ππ MyAbstractClassλ μΆμ ν΄λμ€μ΄λ―λ‘ κ°μ²΄λ₯Ό μμ±ν  μ μμ!!
        ClassA a = new ClassA();
        a.PrintMessage();
        a.PrintMessageAbstract();
    }
}


μΆλ ₯κ²°κ³Ό:
            Hello C#
            C# is fun!!

------------------------------

π΅ Interfaces

  --> μΈν°νμ΄μ€λ ν΄λμ€κ° μλλ―λ‘ λ€μ€ μμμ΄ κ°λ₯νλ€. 
      λ©μλλ§μ ν¬ν¨ν  μ μλ€. νμ§λ§ C#μμλ propertyκ° λ©μλλ‘ κ΅¬νλλ―λ‘ μΈν°νμ΄μ€μ ν¬ν¨μ΄ κ°λ₯νλ€.
      μμ ν΄λμ€μμ κ΅¬νν  λ, λ°λμ public μ κ·Ό μ νμλ₯Ό λͺμν΄μΌ νλ€.


using System;

class C_sharp_book
{
    public static void Main()
    {
        ClassA a = new ClassA();
        a.MyNumber = 5;
        a.IShapeMethod();
        a.MyRoomName = "SunFlower";
        a.IRoomMethod();
    }
}

interface IShape            // νμ¬ μΈν°νμ΄μ€λ€μ λ³΄λ©΄ μ μΈλ§ λμ΄μκ³  κ΅¬νμ λμ΄μμ§ μλ€. κ΅¬νμ μ΄ μΈν°νμ΄μ€λ₯Ό μμλ°μ ν΄λμ€μμ ν΄μ£Όλ©΄ λλ€.
{                              λ°λΌμ νμ¬ μΈν°νμ΄μ€μμ κ΅¬νλμ΄μλ νλμ λ©μλκ° λ§μ½ μμλ°μ ν΄λμ€μμ μλ€λ©΄ μ€λ₯λ₯Ό λ°μμν¨λ€.
    int MyNumber
    {
        get;
        set;
    }
    void IShapeMethod();
}

interface IRoom
{
    string MyRoomName
    {
        get;
        set;
    }
    void IRoomMethod();
}

class ClassA : IShape, IRoom    // ClassAμ μΈν°νμ΄μ€λ₯Ό λ€μ€ μμ
{  
    private int myNumber;
    private string myRoomName = "";
    public int MyNumber
    {
        get
        {
            return myNumber;
        }
        set
        {
            if (value < 0)
                myNumber = 0;
            else 
                myNumber = value;
        }
    }

    public string MyRoomName
    {
        get { return myRoomName; }
        set { myRoomName = value; }
    }

    public void IShapeMethod()                       // μΈν°νμ΄μ€λ‘ μμλ°μ λ©μλλ override ν€μλκ° νμμλ€.
    {
        Console.WriteLine("The number is {0}.", MyNumber);
    }
    public void IRoomMethod()
    {
        Console.WriteLine("The Room-Name is {0}.", MyRoomName);
    }
}






