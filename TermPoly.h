//  Term.hpp
//  Polynomials
#ifndef Term_hpp
#define Term_hpp

#include <stdio.h>
#include <iostream>

#include "NodePoly.h"
#include "SortedLinkList.h"

using namespace std;


struct Term
{
public:
    
    double _coef;
    int _exp;

    Term();
    Term(double coef, int exp);
    friend bool operator == (const Term& lhs, const Term& rhs);
    friend bool operator != (const Term& lhs, const Term& rhs);
    friend bool operator > (const Term& lhs, const Term& rhs);
    friend bool operator < (const Term& lhs, const Term& rhs);

    //used in Poly division operator
    friend Term operator / (const Term& lhs, const Term& rhs);
    friend Term operator + (const Term& lhs, const Term& rhs);
    friend Term operator - (const Term& lhs, const Term& rhs);
    friend Term operator * (const Term& lhs, const Term& rhs);
    
    
    
    friend ostream& operator << (ostream& outs, const Term& t);
    friend istream& operator >>(istream& ins, Term& t);
    
    
    Term& operator += (const Term& rhs);
    Term& operator -= (const Term& rhs);
    Term& operator *= (const Term& rhs);
    Term& operator /= (const Term& rhs);
    
    Term operator -() const; //unary operator
    
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Term::Term()
{
    _coef = 0.0 ;
    _exp =  0 ;
}

Term::Term(double coef, int exp)
{
    _coef = coef ;
    _exp =  exp ;
    
    //T + T
}
bool operator == (const Term& lhs, const Term& rhs)
{
    if (lhs._exp == rhs._exp)
    {
        return true;
    }
    return false;
    
}
bool operator != (const Term& lhs, const Term& rhs)
{
    if (lhs._exp != rhs._exp)
    {
        return true;
    }
    return false;
}
bool operator > (const Term& lhs, const Term& rhs)
{
    if (lhs._exp > rhs._exp)
    {
        return true;
    }
    return false;
}

bool operator < (const Term& lhs, const Term& rhs)
{
    if (lhs._exp < rhs._exp)
    {
        return true;
    }
    return false;
}

//used in Poly division operator
Term operator / (const Term& lhs, const Term& rhs)
{
    // n1 = n1 / n2;
    //n2 cant be 0
    //double coef, int exp
    
    double result;
    
    if(rhs._coef == 0)
        cout << "Denominator = 0 /n" ;
    
        result = lhs._coef / rhs._coef;
        
    return Term(result, lhs._exp - rhs._exp);
}


Term operator + (const Term& lhs, const Term& rhs)
{
    double result;
   // Term res = Term(lhs._coef, lhs._coef);
      
    if(lhs._coef == rhs._coef )
          result = lhs._coef + rhs._coef;
    else
        result = lhs._coef ;
    
    return Term(result, lhs._exp);
}

Term operator - (const Term& lhs, const Term& rhs)
{
    double result;
        if(lhs._coef == rhs._coef )
          result = lhs._coef - rhs._coef;
    else
        result = lhs._coef ;
    
    return Term(result, lhs._exp);
}

Term operator * (const Term& lhs, const Term& rhs)
{
    //not right
    
    double result = lhs._coef * rhs._coef;
    return Term(result, lhs._exp + rhs._exp);
}


















ostream& operator << (ostream& outs, const Term& t)
{
    if(t._exp == 0 && t._coef != 0)
    {
        outs << t._coef << " " ;
        return outs;
    }
    else if(t._coef != 0 )
    {
        outs<< " + " << t._coef << "x^" << t._exp << " " ;
        return outs;
    }
    
    return outs;
}


istream& operator >>( istream& ins, Term& t )
{
    char x;
    
    cout << "Poly: Enter like (3x6 for 3x^6) ";
    ins >> t._coef >> x >> t._exp;
    return ins;
}










Term& Term::operator += (const Term& rhs)
{
    if( rhs._exp == _exp )
     _coef += rhs._coef;
    
    return *this;
//    *this = *this + rhs;
//    return *this;
}

Term& Term::operator -= (const  Term& rhs)
{
    if( rhs._exp == _exp )
     _coef -= rhs._coef;
    
    return *this;
}

Term& Term::operator *= (const Term& rhs)
{
    *this = *this * rhs;
    return *this;
}

Term& Term::operator /= (const Term& rhs)
{
    if(rhs._coef == 0)
    {
        cout << "Denominator = 0 /n";
        *this = Term(0,0);
        return *this;
    }
    _coef /= rhs._coef;
    
    if(_exp >= rhs._exp)
        _exp -= rhs._exp;
    return *this;
}

Term Term::operator - () const
{
    Term result(*this);
    return result *= (-result);
}

#endif /* TermPoly_h */
