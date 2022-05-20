#pragma once
#include "Vector.h"

template<class A>
class TMatrix: public TVector<TVector<A>>
{
protected:
  int len2;
public:
  TMatrix(int numrow, int numcol);
  TMatrix();

  int GetLen2();

  void MultVect(TVector<A>& p1, const TVector<A>& p2);
  void MultVectMatrix(TVector<A>& p, TMatrix<A>& m);
  int CountIncludeMatrix(A ch);

  bool operator == (const TMatrix<A>& p);
  TMatrix<A> operator + (const TMatrix<A>& p);
  TMatrix<A> operator - (const TMatrix<A>& p);
  TMatrix<A> operator * (const TMatrix<A>& p);
  TMatrix<A> operator = (const TMatrix<A>& p);
};

template<class A>
inline TMatrix<A>::TMatrix(int numrow, int numcol) : TVector<TVector<A>> ::TVector(numrow)
{
  len2 = numcol;
  for (int i = 0; i < numrow; i++)
  {
    TVector<A> a(numcol);
    data[i] = a;
    for (int j = 0; j < numcol; j++)
    {
      data[i][j] = 0;
    }
  }
}

template<class A>
inline TMatrix<A>::TMatrix():TMatrix<A> (1,1)
{
}

template<class A>
inline int TMatrix<A>::GetLen2()
{
  return len2;
}

template<class A>
inline void TMatrix<A>::MultVect(TVector<A>& p1, const TVector<A>& p2)
{
  if ((!p1.GetTran()) || p2.GetTran())
  {
    throw out_of_range("wrong transponation");
  }
  TMatrix<A> M1(p1.GetLen(), 1);
  for (int row = 0; row < p1.GetLen(); row++)
  {
    M1[row][0] = p1[row];
  }

  TMatrix<A> M2(1, p2.GetLen());
  M2[0] = p2;

  *this = M1*M2;
}

template<class A>
inline void TMatrix<A>::MultVectMatrix(TVector<A>& p, TMatrix<A>& m)
{
  if (p.GetTran())
  {
    if (p.GetLen() != m.GetLen2())
    {
      throw out_of_range("diferent sizes");
    }
    TMatrix<A> M1(p.GetLen(), 1);
    for (int row = 0; row < p.GetLen(); row++)
    {
      M1[row][0] = p[row];
    }
    *this = m * M1;
  }
  else
  {
    if (p.GetLen() != m.GetLen())
    {
      throw out_of_range("diferent sizes");
    }
    TMatrix<A> M2(1, p.GetLen());
    M2[0] = p;
    *this = M2 * m;
  }
}

template<class A>
inline int TMatrix<A>::CountIncludeMatrix(A ch)
{
  int count=0;
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len2; j++)
    {
      if (data[i][j] == ch)
      {
        count++;
      }
    }
  }
  return count;
}

template<class A>
inline bool TMatrix<A>::operator==(const TMatrix<A>& p)
{
  return TVector<TVector<A>>::operator==(p);
}

template<class A>
inline TMatrix<A> TMatrix<A>::operator+(const TMatrix<A>& p)
{
  if (len == p.len && len2 == p.len2)
  {
    TMatrix<A> res(len, len2);
    for (int i = 0; i < len; i++)
    {
      for (int j = 0; j < len2; j++)
      {
        res[i][j] = data[i][j] + p.data[i][j];
      }
    }
    return res;
  }
  else
  {
    throw out_of_range("different sizes");
  }
  
}

template<class A>
inline TMatrix<A> TMatrix<A>::operator-(const TMatrix<A>& p)
{
  if (len == p.len && len2 == p.len2)
  {
    TMatrix<A> res(len, len2);
    for (int i = 0; i < len; i++)
    {
      for (int j = 0; j < len2; j++)
      {
        res[i][j] = data[i][j] - p.data[i][j];
      }
    }  
    return res;
  }
  else
  {
    throw out_of_range("different sizes");
  }

}

template<class A>
inline TMatrix<A> TMatrix<A>::operator*(const TMatrix<A>& p)
{
  if (len2 == p.len)
  {
    TMatrix<A> res(len, p.len2);
    for (int i = 0; i < len; i++)
    {
      for (int j = 0; j < p.len2; j++)
      {
        res[i][j] = 0;
        for (int t = 0; t < len2; t++)
        {
          res[i][j] += data[i][t] * p.data[t][j];
        }
      }
    }
    return res;
  }
  else
  {
    throw out_of_range("different sizes*");
  }
}
template<class A>
inline TMatrix<A> TMatrix<A>::operator=(const TMatrix<A>& p)
{
  TVector<TVector<A>>::operator = (p);
  return *this;
}

template<class A>
ostream& operator <<(ostream& ostr, TMatrix<A>& p)
{
  for (int i = 0; i < p.GetLen(); i++)
  {
    auto v = p[i];
    for (int j = 0; j < p.GetLen2(); j++)
    {
      ostr << p[i][j] << "\t";
    }
    ostr<< endl;
  }
  return ostr;
}

template<class A>
istream& operator >>(istream& istr, TMatrix<A>& p)
{
  int numrow;
  int numcol;
  istr >> numrow >> numcol;
  TMatrix<A> res(numrow, numcol);
  for (int row = 0; row < numrow; row++)
  {
    for (int col = 0; col < numcol; col++)
    {
      istr >> res[row][col];
    }
  }
  p = res;
  return istr;
}
