#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class TVector
{
protected:
  T* data;
  int len;
  bool tran;
public:
  TVector(int n, T v);
  TVector(const TVector<T>& p);
  TVector(int length = 1,T* mas = nullptr);
  ~TVector();

  int GetLen() const;
  void SetTran(bool t);
  bool GetTran() const;
  int CountIncludeVector(T ch);

  T& operator[](int i);
  TVector<T>& operator = (const TVector<T>& p);
  TVector<T> operator + (const TVector<T>& p);
  TVector<T> operator - (const TVector<T>& p);
  TVector<T> operator / (const TVector<T>& p);
  TVector<T> operator * (const T n);
  TVector<T> operator / (const T n);
  bool operator == (const TVector<T>& p);
  TVector<T> operator * (const TVector<T>& p);
};

//Конструктор инициализатор, принимающий на вход длину и символ, которым необходимо заполнить вектор
template<class T>
inline TVector<T>::TVector(int n, T v)
{
  if (n > 0)
  {
    data = new T[n];
    len = n;
    tran = false;
    for (int i = 0; i < n; i++)
      data[i] = v;
  }
  else
  {
    throw out_of_range("out of range");
  }
}

//Конструктор копирования, принимающий на вход ссылку на вектор
template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  data = new T[p.len];
  len = p.len;
  tran = p.tran;
  for (int i = 0; i < p.len; i++)
    data[i] = p.data[i];
}

//Конструктор, собирающий вектор по длинне и переданному массиву шаблонного типа
template<class T>
inline TVector<T>::TVector(int length,T* mas)
{ 
  if (length <= 0)
  {
    throw out_of_range("out of range");
  }
  len = length;
  tran = false;
  data = new T[len];
  if (mas != nullptr)
  {
    for (int i = 0; i < len; i++)
      data[i] = mas[i];
  }
}

//Деструктор, очищающий выделенную память
template<class T>
inline TVector<T>::~TVector()
{
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
}

//Метод, возвращающий длину вектора
template<class T>
inline int TVector<T>::GetLen() const
{
  return len;
}

//Метод, изменяющий значение транспонированности вектора
template<class T>
inline void TVector<T>::SetTran(bool t)
{
  tran = t;
}

//Метод, возвращяющий значение транспонированности вектора
template<class T>
inline bool TVector<T>::GetTran() const
{
  return tran;
}

//Метод для подсчёта количества вхождения элемента в вектор
template<class T>
inline int TVector<T>::CountIncludeVector(T ch)
{
  int count = 0;
  for (int i = 0; i < len; i++)
  {
    if (data[i] == ch)
    {
      count++;
    }
  }
  return count;
}

//Перегрузка оператора [], принимающая на вход номер ячейки вектора
template<class T>
inline T& TVector<T>::operator[](int i)
{
  if (i >= 0 && i < len)
  {
    return data[i];
  }
  else
  {
    stringstream info;
    info << "opreator [] i=" << i << " len=" << len;
    throw out_of_range(info.str());
  }
}

//Перегрузка оператора =, принимающая на вход ссылку на вектор
template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
  data = new T[p.len];
  len = p.len;
  tran = p.tran;
  for (int i = 0; i < p.len; i++)
    data[i] = p.data[i];
  return *this;
}

//Перегрузка оператора +, принимающая на вход ссылку на вектор
template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
  TVector<T> res(len);
  if (len != p.len)
  {
    throw out_of_range("different sizes");
  }
  for (int i = 0; i < len; i++)
    res[i] = data[i] + p.data[i];
  return res;
}

//Перегрузка оператора -, принимающая на вход ссылку на вектор
template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
  TVector<T> res(len);
  if (len != p.len)
  {
    throw out_of_range("different sizes");
  }
  for (int i = 0; i < len; i++)
    res[i] = data[i] - p.data[i];

  return res;
}

//Перегрузка оператора /, принимающая на вход ссылку на вектор
template <class T>
inline TVector<T> TVector<T>::operator /(const TVector<T>& p)
{
  TVector<T> res(len);
  if (len != p.len)
  {
    throw out_of_range("different sizes");
  }
  for (int i = 0; i < len; i++)
    res[i] = data[i] / p.data[i];

  return res;
}

//Перегрузка оператора *, принимающая на вход шаблонный скаляр
template<class T>
inline TVector<T> TVector<T>::operator*(const T n)
{
  TVector<T> res(len);

  for (int i = 0; i < len; i++)
    res[i] = data[i] * n;

  return res;
}

//Перегрузка оператора /, принимающая на вход шаблонный скаляр
template<class T>
inline TVector<T> TVector<T>::operator/(const T n)
{
  TVector<T> res(len);

  for (int i = 0; i < len; i++)
    res[i] = data[i] / n;

  return res;
}

//Перегрузка оператора ==, принимающая на вход ссылку на вектор
template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
  if (len != p.len || tran != p.tran)
    return false;
  for (int i = 0; i < len; i++)
    if (!(data[i] == p.data[i]))
      return false;
  return true;
}

//Перегрузка оператора *, принимающая на вход ссылку на вектор
template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
  if (len == p.len && tran == p.tran && tran == true)
  {
    TVector<T> res(len);
    for (int i = 0; i < len; i++)
      res[i] = data[i] * p.data[i];
    return res;
  }
  if (len == p.len && p.tran == true && tran == false)
  {
    TVector<T> res(1,0);
    for (int i = 0; i < len; i++)
      res[0] = res[0] + (data[i] * p.data[i]);
    return res;
  }
}

//Перегрузка оператора <<, принимающая на вход поток и ссылку на вектор
template<class T>
ostream& operator<<(ostream& ostr, TVector<T>& p)
{
  for (int i = 0; i < p.GetLen(); i++)
    ostr << p[i] << "\t";
  return ostr;
}

//Перегрузка оператора >>, принимающая на вход поток и ссылку на вектор
template<class T>
istream& operator>>(istream& istr, TVector<T>& p)
{
  int length;
  istr >> length;
  TVector<T> res(length);
  for (int i = 0; i < length; i++)
  {
    istr >> res[i];
  }
  p = res;
  return istr;
}
