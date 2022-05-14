#pragma once
#include "Vector.h"

template<class A>
class TMatrix: public TVector<TVector<A>>
{
protected:
  int len2;
public:
//  TMatrix(int n = 1);
  TMatrix(int n1, int n2);

  int GetLen2();
//  A& operator [](int i);
};
//
//template<class A>
//inline TMatrix<A>::TMatrix(int n) : TVector<TVector<A>> ::TVector(n)
//{
//}
//
template<class A>
inline TMatrix<A>::TMatrix(int n1, int n2)
{
  len = n1;
  len2 = n2;
  TVector<TVector<A>> MMM(n2);
  for (int i = 0; i < n2; i++)
  {
    TVector<A> a(n1,nullptr);
    cout << "a=" << a <<"\n";
    MMM[i] = a;
  }
  cout << "MMM= " << MMM <<"\n";
  *this  MMM;
}

template<class A>
inline int TMatrix<A>::GetLen2()
{
  return len2;
}

//template<class A>
//inline A& TMatrix<A>::operator[](int i)
//{
//  return data[i];
//}
//

template<class A>
ostream& operator <<(ostream& ostr, TMatrix<A>& p)
{
  cout << "len1=" << p.GetLen() << "len2=" << p.GetLen2() << "\n";
  for (int i = 0; i < p.GetLen(); i++)
  {
    auto v = p[i];
    cout << "vlen= "<<v.GetLen()<<"\n";
    for (int j = 0; j < p.GetLen2(); j++)
    {
      ostr << p[i][j] << "aaa\t";
    }
    ostr << "ddd" << endl;
  }
  return ostr;
}
