C#은 다음과 같은 약속을 따르는 메서드를 최초로 실행될 메서드라고 규정한다.

1. 메서드 이름은 반드시 Main이다.
2. 정적 메서드여야 한다.
3. Main 메서드가 정의된 클래스의 이름은 제한이 없다. 하지만 2개 이상의 클래스에서 Main 메서드를 정의하고 있다면
   C# 컴파일러에게 클래스를 지정해야 한다.
4. Main 메서드의 반환값은 void 또는 int만 허용된다.
5. Main 메서드의 매개변수는 없거나 string 배열만 허용된다.
