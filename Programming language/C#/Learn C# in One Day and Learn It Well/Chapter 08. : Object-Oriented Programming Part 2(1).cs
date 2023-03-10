
๐ต Inheritance : ์์
 
      Inheritance is one of the key concepts of object-oriented programming.
      Simply stated, inheritance allows us to create a new class from an existing
      class so that we can effectively reuse existing code.

---------------
 
using System; 

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
}

class NormalMember : Member    // Member ํด๋์ค๋ฅผ ์์๋ฐ๊ฒ ๋ค๋ ๋ป.    โ ์ฌ๊ธฐ์ Memberํด๋์ค๋ฅผ ๋ถ๋ชจํด๋์ค(๊ธฐ๋ฐํด๋์ค) 
{                                                                        NormalMemberํด๋์ค๋ฅผ ์์ํด๋์ค(ํ์ํด๋์ค)๋ผ๊ณ  ํ๋ค.
    public NormalMember()
    {
        Console.WriteLine("Child constructor with no parameter");
    }
}
class C_sharp_book
{
    public static void Main()
    {
        NormalMember normalMember = new NormalMember();
    }
}

์คํ๊ฒฐ๊ณผ: 
           Parent Constructor with no parameter       // ์คํ๊ฒฐ๊ณผ๋ฅผ ๋ณด๋ฉด ๋ถ๋ชจ ํด๋์ค์ ์์ฑ์๊ฐ ๋จผ์  ์คํ๋๋ค.
           Child constructor with no parameter
 
---------------  
                 ๐๐ ์ด์  ์๋ ์ฝ๋๋ฅผ ํ๋ฒ ๋ด๋ณด์ ๋ง์ฝ ๋ถ๋ชจ ํด๋์ค์ ์์ฑ์์ ๋งค๊ฐ๋ณ์๊ฐ ๋ค์ด์๋ค๋ฉด ์ฝ๋๋ฅผ ์ด๋ป๊ฒ ์์ฑํด์ผํ ๊น????
                 
                       ๊ทธ๊ฑด ๋ฐ๋ก base ํค์๋๋ฅผ ์ฌ์ฉํ๋ ๊ฒ์ด๋ค.
using System; 

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: " 
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }

    public Member(string pName, int pMemberID, int pMemberSince)   // ๋งค๊ฐ๋ณ์ ์ ๋ฌ๋ฐ์
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks) : base ("์ ํ์ฑ", 1, 2022)    // base ํค์๋๋ฅผ ์ฌ์ฉํ์ฌ ๋งค๊ฐ๋ณ์ ์ ๋ฌ
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
}
class C_sharp_book
{
    public static void Main()
    {
        NormalMember normalMember = new NormalMember("Special Rate");
        Console.WriteLine(normalMember.ToString());
    }
}
--------------------------
                   ๐๐ ์ด ๋ฐฉ๋ฒ ์ธ์๋ ์๋์ ์ฝ๋์ฒ๋ผ ์์ฑ์ด ๊ฐ๋ฅํ๋ค.
                   
                   โ ์๋ณด๋ฉด name, memberID, memeberSince๋ ๋งค๊ฐ๋ณ์๋ก ์ ๋ฌ๋ฐ๊ณ  ์ ๋ฌ ๋ฐ์ ๊ฒ์ ๋ถ๋ชจํด๋์ค์ ์์ฑ์์ ์ ๋ฌํด ์ค๋ค.
 
 class NormalMember : Member
{                          
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {                                                            
        Console.WriteLine("Remarks = {0}", remarks);        
    }                                        
}                           
class C_sharp_book
{
    public static void Main()
    {
        NormalMember normalMember = new NormalMember("Special Rate", "์ ํ์ฑ", 1, 2022);
        Console.WriteLine(normalMember.ToString());
    }
}
 
 
 
---------------------- ์์ฑ๋ ์ฝ๋

using System; 

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: " 
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }
    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
    public Member(string pName, int pMemberID, int pMemberSince)
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
    public void CalculateAnnualFee()
    {
        annualFee = 100 + 12 * 30;
    }
}
class VIPMember : Member
{
    public VIPMember(string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Child Constructor with 3 parameters");
    }
    public void CalculateAnnualFee()
    {
        annualFee = 1200;
    }
}

class C_sharp_book
{
    public static void Main()
    {
        NormalMember mem1 = new NormalMember("Special Rate", "์ ํ์ฑ", 1, 2022);
        mem1.CalculateAnnualFee();
        VIPMember mem2 = new VIPMember("์ด๋ณ๊ฑด", 2, 2023);
        mem2.CalculateAnnualFee();
        Console.WriteLine(mem1.ToString());
        Console.WriteLine(mem2.ToString());
    }
}

์คํ๊ฒฐ๊ณผ: 
             Parent Constructor with 3 parameters
             Remarks = Special Rate
             Parent Constructor with 3 parameters
             Child Constructor with 3 parameters

             Name: ์ ํ์ฑ
             Member ID: 1
             Member Since: 2022
             Total AnnualFee: 460

             Name: ์ด๋ณ๊ฑด
             Member ID: 2
             Member Since: 2023
             Total AnnualFee: 1200

-------------------------------------

๐ต Polymorphism : ๋คํ์ฑ

    --> ๋คํ์ฑ์ ํํ๋ ๊ฐ์ง๋ง ์์ธํ ๋ณด๋ฉด ๊ทธ ํํ์ ๊ณ ์ ํ ํน์ง์ ๊ฐ์ง๋ ๊ฒ์ ๋งํ๋ค.
    
        ์๋์ ์ฝ๋๋ค์ ๋ด๋ณด์...!!!!!!!!

------------------------------
                          *์ฐ์  Main() ๋ฉ์๋์ Memberํ(class) ๋ฉ์๋๋ฅผ ์ ์ธํ๋ค.
using System; 

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: " 
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }
    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
    public Member(string pName, int pMemberID, int pMemberSince)
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
    public void CalculateAnnualFee()
    {
        annualFee = 100 + 12 * 30;
    }
}
class VIPMember : Member
{
    public VIPMember(string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Child Constructor with 3 parameters");
    }
    public void CalculateAnnualFee()
    {
        annualFee = 1200;
    }
}

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
            m.CalculateAnnualFee();                <---  ๐๐ ํ์ง๋ง ์ฌ๊ธฐ์ ์ค๋ฅ๊ฐ ๋จ๊ฒ ๋๋ค.
            Console.WriteLine(m.ToString());
        }
    }
}                               โ ์ค๋ฅ๊ฐ ๋จ๋ ์ด์ ๋ Member ํ์ผ๋ก ์ ์ธ๋ ๋ฐฐ์ด์ธ clubMembers์๋ 
                                   CalculateAnnualFee() ๋ฉ์๋๊ฐ ์ ์ธ๋์ด ์์ง ์๊ธฐ ๋๋ฌธ์ด๋ค.
                                   ๋ฌผ๋ก  ์์ ํด๋์ค์ธ NormalMember์ VIPMember์๋ ์ ์ธ์ด ๋์ด์๋ค.
                                   ์ด ๋ฌธ์ ๋ฅผ ํด๊ฒฐํ๊ธฐ ์ํด์ Member ํด๋์ค์ CalculateAnnualFee() ๋ฉ์๋๋ฅผ ์ ์ธํด์ฃผ๋ฉด ๋๋ค.
 
 
----------------------------
                                 *CalculateAnnualFee() ๋ฉ์๋ ์ ์ธ
using System;

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: "
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }
    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
    public Member(string pName, int pMemberID, int pMemberSince)
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
    public void CalculateAnnualFee()
    {
        annualFee = 0;                   <---  ๐๐ ์ด๋ ๊ฒ CalculateAnnualFee() ๋ฉ์๋๋ฅผ ์ ์ธํด์ค๋ค. 
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
    public void CalculateAnnualFee()
    {
        annualFee = 100 + 12 * 30;
    }
}
class VIPMember : Member
{
    public VIPMember(string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Child Constructor with 3 parameters");
    }
    public void CalculateAnnualFee()
    {
        annualFee = 1200;
    }
}

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
    }
}
                                                     โ ์คํ๊ฒฐ๊ณผ๋ฅผ ๋ณด๋ฉด ์ ์ ์๋ฏ์ด ๋ชจ๋  Total AnnualFee๊ฐ 0์ผ๋ก ์ถ๋ ฅ์ด๋๋ค.
์คํ๊ฒฐ๊ณผ :                                               ๊ทธ๋ ๋ค๋ฉด ์ด ๋ฌธ์ ๋ฅผ ์ด๋ป๊ฒ ํด๊ฒฐํด์ค ์ ์์๊น???
            Remarks = Normal Rate                        ์๋์ ์ฝ๋๋ฅผ ๋ด๋ณด์.
            Parent Constructor with 3 parameters
            Remarks = Normal Rate
            Parent Constructor with 3 parameters
            Child Constructor with 3 parameters
            Parent Constructor with 3 parameters
            Child Constructor with 3 parameters

            Name: James
            Member ID: 1
            Member Since: 2010
            Total AnnualFee: 0

            Name: Andy
            Member ID: 2
            Member Since: 2011
            Total AnnualFee: 0

            Name: Bill
            Member ID: 3
            Member Since: 2011
            Total AnnualFee: 0

            Name: Carol
            Member ID: 4
            Member Since: 2012
            Total AnnualFee: 0

            Name: Evelyn
            Member ID: 5
            Member Since: 2012
            Total AnnualFee: 0
 
----------------------------------------------
 
using System;

class Member
{
    protected int annualFee;
    private string name;
    private int memberID;
    private int memberSince;

    public override string ToString()
    {
        return "\nName: " + name + "\nMember ID: " + memberID + "\nMember Since: "
                + memberSince + "\nTotal AnnualFee: " + annualFee;
    }
    public Member()
    {
        Console.WriteLine("Parent Constructor with no parameter");
    }
    public Member(string pName, int pMemberID, int pMemberSince)
    {
        Console.WriteLine("Parent Constructor with 3 parameters");
        name = pName;
        memberID = pMemberID;
        memberSince = pMemberSince;
    }
    public virtual void CalculateAnnualFee()       // ๐๐ ์ฑํฐ 7์์ ๋ดค๋ virtual ํค์๋์ด๋ค. 
    {                                                      ์์ํด๋์ค์์ ์ด ํจ์๋ฅผ ์ค๋ฒ๋ผ์ด๋ฉ์ด ๊ฐ๋ฅํ๋๋ก ํ์ฉํ๋ค.
        annualFee = 0;
    }
}

class NormalMember : Member
{
    public NormalMember(string remarks, string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Remarks = {0}", remarks);
    }
    public override void CalculateAnnualFee()         // ๐๐ override๋ฅผ ์ฌ์ฉํ์ฌ ํจ์๋ฅผ ์ฌ์ ์
    {
        annualFee = 100 + 12 * 30;
    }
}
class VIPMember : Member
{
    public VIPMember(string name, int memberID, int memberSince) : base(name, memberID, memberSince)
    {
        Console.WriteLine("Child Constructor with 3 parameters");
    }
    public override void CalculateAnnualFee()       // ๐๐ override๋ฅผ ์ฌ์ฉํ์ฌ ํจ์๋ฅผ ์ฌ์ ์
    {
        annualFee = 1200;
    }
}

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
    }
}


์คํ๊ฒฐ๊ณผ:                                         โ ์ด์  ๊ฐ์์ ๋งค๋ ์๊ธ์ด ์ ๋๋ก ์ถ๋ ฅ๋๋ค.
         Child Constructor with 3 parameters

         Name: James
         Member ID: 1
         Member Since: 2010
         Total AnnualFee: 460

         Name: Andy
         Member ID: 2
         Member Since: 2011
         Total AnnualFee: 460

         Name: Bill
         Member ID: 3
         Member Since: 2011
         Total AnnualFee: 460

         Name: Carol
         Member ID: 4
         Member Since: 2012
         Total AnnualFee: 1200

         Name: Evelyn
         Member ID: 5
         Member Since: 2012
         Total AnnualFee: 1200
         
                                                ์ด๊ฒ์ด ๋ฐ๋ก ๋คํ์ฑ์ ํ์ด๋ค!!! (์ฌ์ค ์์ง ์๋ฌด๋ฐ ๋๋์์)
         
 
