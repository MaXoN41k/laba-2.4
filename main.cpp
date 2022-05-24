#include <iostream>
#include <locale.h>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

// Проверка суммы векторов
void testsum()
{
  TVector<double> B(10, 2.0);
  TVector<double> C(10, 6.0);
  C[2] = 4;
  TVector<double> D(10);
  D = C + B;
  cout << "D=" << D;
}

//Тест умножения векторов
void testmult()
{
  double data[3] = { 1,2,3 };
  TVector<double> B(3, data);
  TVector<double> D(3);

  D = B * 2;
  cout << "D=" << D;
}

//Тест сравнения двух векторов
void testravno()
{
  double data1[3] = { 1,2,3 };
  TVector<double> B1(3, data1);

  double data2[3] = { 1,2,3 };
  TVector<double> B2(3, data2);

  double data3[2] = { 1,2};
  TVector<double> B3(2, data3);

  cout << (B1 == B2);
}

//Тест ввода вектора с клавиатуры и вывода его на консоль
void testinput()
{
  TVector<double> B1;
  cin >> B1;
  cout << "B1=" << B1;
}

//Тест вывода матрицы на консоль
void testmatrixoutput()
{
  TMatrix<int> M(2, 3,0);
  cout << M;
}

//Тест векторного умножения, в результате которого получается матрица
void testmultvector()
{
  double data1[2] = { 1,2 };
  TVector<double> B1(2, data1);

  double data2[3] = { 1,2,3 };
  TVector<double> B2(3, data2);

  B1.SetTran(true);
  TMatrix<double> M1(2,3,0);

  M1.MultVect(B1,B2);

  cout << M1;
}

//Тест матричного умножения
void testmultomatrix()
{
  TMatrix<int> M1(2, 2,0);
  TMatrix<int> M2(2, 3,0);
  stringstream str;

  str << "2 2 2 3 4 5 ";
  str >> M1;
  cout << M1;

  str << "2 3 1 3 6 5 2 4 ";
  str >> M2;
  cout << M2;
  
  TMatrix<int> M3(2, 3,0);
  M3 = M1 * M2;

  TMatrix<int> check(2, 3,0);
  str << "2 3 17 12 24 29 22 44 ";
  str >> check;

  cout << M3 << endl;

  if (check == M3)
  {
    cout << "ok";
  }
  else
  {
    cout << "ne ok(";
  }
}

//Тест матрично-векторного умножения
void testmultvectmatrix()
{
  TMatrix<int> M1(2,3,0);
  TVector<int> V1(2);

  stringstream str;
  str << "2 3 1 2 3 4 5 6 ";
  str >> M1;

  str << "3 1 2 3 ";
  str >> V1;
  V1.SetTran(true);

  TMatrix<int> M3(2,1,0);
  M3.MultVectMatrix(V1, M1);

  cout << M3;
}

//Тест нахождения числа вхождений заданного значения в вектор или матрицу
void testcountinclude()
{
  int count;
  TMatrix<int> V1(2,3,0);
  stringstream str;
  str << "2 3 2 2 1 3 2 3  ";
  str >> V1;

  count = V1.CountIncludeMatrix(2);
  cout << count;
}

//Проверка времени работы алгоритма
void testtime()
{
  clock_t t1, t2;
  int n = 100;
  for (int i = 100; i <= 500; i += 25)
  {
    TMatrix<int> A(i, i, 99);
    TMatrix<int> B(i, i, 99);

    t1 = clock();
    A * B;
    t2 = clock();

    cout << "Time:" << (t2 - t1)<< " ms"<<endl;
  }

}

int main()
{
  setlocale(LC_ALL, "Rus");
  try
  {
    //testmultvectmatrix();
    //testinput();
    //testmatrixoutput();
    //testmult();
    //testmultomatrix();
    //testmultvector();
    //testsum();
    //testravno();
    //testcountinclude();
    testtime();

  }
  catch (exception&ex) 
  {
    cout << ex.what();
  }
  return 0;
}