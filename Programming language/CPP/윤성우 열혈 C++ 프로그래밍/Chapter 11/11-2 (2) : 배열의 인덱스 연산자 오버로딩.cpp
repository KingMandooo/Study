π’ κ°μ²΄μ μ μ₯μ μν λ°°μ΄ ν΄λμ€μ μ μ

  μμ λ³΄μΈ μμ λ€μ κΈ°λ³Έμλ£ν λμμ λ°°μ΄ ν΄λμ€μλ€.
  μ΄λ²μλ κ°μ²΄ λμμ λ°°μ΄ ν΄λμ€λ₯Ό κ³΅λΆν΄λ³΄μ.
  
  
  
     μ΄ λ κ°μ§ ννλ‘ μ μν΄λ³΄κ² λ€.
  
              - Point κ°μ²΄μ μ£Όμ κ°μ μ μ₯νλ λ°°μ΄ κΈ°λ°μ ν΄λμ€
              - Point κ°μ²΄λ₯Ό μ μ₯νλ λ°°μ΄ κΈ°λ°μ ν΄λμ€ 
  
---------------------------------------------------------------------

π Point κ°μ²΄λ₯Ό μ μ₯νλ λ°°μ΄ κΈ°λ°μ ν΄λμ€ π
              
#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class BoundCheckPointArray
{
private:
	Point* arr;
	int arrlen;
	BoundCheckPointArray(const BoundCheckPointArray& copy) {}
	BoundCheckPointArray operator= (const BoundCheckPointArray& ref) {}
public:
	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr = new Point[len];
	}
	Point& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of boud exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	Point& operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of boud exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointArray() { delete[] arr; }
};

int main()
{
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);          // β arr.operator[](0)μ λ°νκ°μ΄ Point κ°μ²΄μ΄λ€. λ°λΌμ "(λ°νλ Point κ°μ²΄) = Point(3, 4);"
	arr[1] = Point(5, 6);          //    μ΄λ κ² νμ΄λ³΄λ©΄ λΉμ°ν Point ν΄λμ€μμ λν΄νΈ λμμ°μ°μκ° μ€νλλ€.
	arr[2] = Point(7, 8);          //    μ΄λ λ κ°μ²΄κ°μ λ©€λ² λ λ©€λ²μ λ³΅μ¬κ° μΌμ΄λλ€.

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];
}


π Point κ°μ²΄μ μ£Όμ κ°μ μ μ₯νλ λ°°μ΄ κΈ°λ°μ ν΄λμ€ π

#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointArray
{
private:
	POINT_PTR* arr;    // μ΄μ€ν¬μΈν°
	int arrlen;
	BoundCheckPointArray(const BoundCheckPointArray& copy) {}
	BoundCheckPointArray operator= (const BoundCheckPointArray& ref) {}
public:
	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of boud exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR& operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of boud exception" << endl;
			exit(1);
		}
		return arr[idx];                     // μ£Όμκ°μΌλ‘ λ°ν
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointArray() { delete[] arr; }
};

int main()
{
	BoundCheckPointArray arr(3);
	arr[0] = new Point(3, 4);      // ν¬μΈν°μ΄λ―λ‘ μ£Όμκ°μ κ°λ¦¬μΌμΌ ν΄μ 
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << *(arr[i]);

	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}

---------------------------------------------------------------------

π  λ¬Έμ  11-2(1)
  
#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend ostream& operator<<(ostream& os, const Point* pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}
ostream& operator<<(ostream& os, const Point* pos)
{
	os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
	return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointArray
{
private:
	POINT_PTR* arr;
	int arrlen;
	BoundCheckPointArray(const BoundCheckPointArray& copy) {}
	BoundCheckPointArray operator= (const BoundCheckPointArray& ref) {}
public:
	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of boud exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR& operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of boud exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointArray() { delete[] arr; }
};

int main()
{
	BoundCheckPointArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];

	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}


π  λ¬Έμ  11-2(2)   κ°μ΄λ ΅λ€???
  
#include <iostream>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& copy) {}
	BoundCheckIntArray operator= (const BoundCheckIntArray& ref) {}
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of boud exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int& operator[] (int idx) 
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of boud exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray() { delete[] arr; }
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2DIntArray
{
private:
	BoundCheckIntArray** arr;
	int arrlen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}

public:
	BoundCheck2DIntArray(int col, int row) : arrlen(col)
	{
		arr = new BoundCheckIntArrayPtr[col];
		for (int i = 0; i < col; i++)
			arr[i] = new BoundCheckIntArray(row);
	}
	BoundCheckIntArray& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return *(arr[idx]);
	}
	~BoundCheck2DIntArray()
	{
		for (int i = 0; i < arrlen; i++)
			delete arr[i];
		delete[] arr;
	}
};

int main()
{
	BoundCheck2DIntArray arr2d(3, 4);

	for (int n = 0; n < 3; n++)
		for (int m = 0; m < 4; m++)
			arr2d[n][m] = n + m;
	       // (arr2d.operator[](n))[m];
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
			cout << arr2d[n][m] << ' ';
		cout << endl;
	}
	 
	return 0;
}
