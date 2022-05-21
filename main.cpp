#include <iostream>
#include <locale.h>
#include <sstream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

void testsum()
{
  TVector<double> B(10, 2.0);
  TVector<double> C(10, 6.0);
  C[2] = 4;
  TVector<double> D(10);
  D = C / B;
  cout << "D=" << D;
}

void testmult()
{
  double data[3] = { 1,2,3 };
  TVector<double> B(3, data);
  TVector<double> D(3);

  D = B / 2;
  cout << "D=" << D;
}
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

void testinput()
{
  TVector<double> B1;
  cin >> B1;
  cout << "B1=" << B1;
}

void testmatrixoutput()
{
  TMatrix<int> M(2, 3);
  cout << M;
}

void testmultvector()
{
  double data1[2] = { 1,2 };
  TVector<double> B1(2, data1);

  double data2[3] = { 1,2,3 };
  TVector<double> B2(3, data2);

  B1.SetTran(true);
  TMatrix<double> M1(2,3);

  M1.MultVect(B1,B2);

  cout << M1;
}

void testmultomatrix()
{
  TMatrix<int> M1(2, 2);
  TMatrix<int> M2(2, 3);
  stringstream str;

  str << "2 2 2 3 4 5 ";
  str >> M1;
  cout << M1;

  str << "2 3 1 3 6 5 2 4 ";
  str >> M2;
  cout << M2;
  
  TMatrix<int> M3(2, 3);
  M3 = M1 * M2;

  TMatrix<int> check(2, 3);
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

void testmultvectmatrix()
{
  TMatrix<int> M1(2,3);
  TVector<int> V1(2);

  stringstream str;
  str << "2 3 1 2 3 4 5 6 ";
  str >> M1;

  str << "3 1 2 3 ";
  str >> V1;
  V1.SetTran(true);

  TMatrix<int> M3(2,1);
  M3.MultVectMatrix(V1, M1);

  cout << M3;
}

void testcountinclude()
{
  int count;
  TMatrix<int> V1(2,3);
  stringstream str;
  str << "2 3 2 2 1 3 2 3  ";
  str >> V1;

  count = V1.CountIncludeMatrix(2);
  cout << count;
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
    testcountinclude();
  }
  catch (exception&ex) 
  {
    cout << ex.what();
  }
  return 0;
}
