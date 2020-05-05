#ifndef PolyPoly_h
#define PolyPoly_h

#include <stdio.h>
#include <iostream>

#include "NodePoly.h"
#include "SortedLinkList.h"
#include "TermPoly.h"

using namespace std;

class Poly
{
public:
    Poly();
    Poly(double term_arra[], int order);

//delete these ?
    Poly(const Poly& other);                //copy constructor
    Poly& operator =( const Poly& rhs);      //assigment
    ~Poly();                                //destructor

//need to do
    
    Poly& operator *= (const Term& t);
    Poly& operator *= (const Poly& RHS);
    Poly& operator += (const Term& t);
    Poly& operator += (const Poly& RHS);
    Poly& operator -= (const Poly& RHS);
    
//all done
    friend bool operator == (const Poly& lhs, const Poly& rhs);
    friend bool operator != (const Poly& lhs, const Poly& rhs);
    friend bool operator >  (const Poly& lhs, const Poly& rhs);
    friend bool operator <  (const Poly& lhs, const Poly& rhs);

//take out this ?
    Term operator[](int order) const;
    
//done
    friend Poly operator + (const Poly& lhs, const Term& t);
    friend Poly operator + (const Poly& lhs, const Poly& rhs);

//do correct -
    friend Poly operator - (const Poly& p);
    friend Poly operator - (const Poly& lhs, const Poly& rhs);
//need to do
    //Poly operator -() const;

    
//done
    friend Poly operator * (const Poly& lhs, const Term& t);
    friend Poly operator * (const Poly& lhs, const Poly& rhs);

//take out ?
    friend Poly operator / (const Poly& lhs, const Poly& rhs);
    friend Poly operator % (const Poly& lhs, const Poly& rhs);

    friend ostream& operator << (ostream& outs, const Poly& p);
    friend istream& operator >> (istream& ins, Poly& p);

    int order() const {return _order;}

private:
    List<Term> _poly;
    void fix_order();           //get rid of highest terms with zero coefs
    int _order;
    double* _coefs;
};



int const SIZE = 4 ;


Poly::Poly()
{
    _order = 0;
    _coefs = new double[SIZE];
    for ( int i = 0; i < SIZE; i++ )
    {
       _coefs[i] = 0.0;
    }
}
Poly::Poly(double term_array[], int order)
{
    //account for x^0 with + 1 for overal order
    _poly = new List<Term>;
    
    _order = order ;
    _coefs = new double[order + 1];
    
    for ( int i = 0; i < order + 1; i++ )
    {
       _coefs[i] = term_array[i];
    }
}

//the BIG 3

//copy constructor
Poly::Poly(const Poly& other)
{//call allocate then copy
    //check to see if power entered is equal to power of _order
    
    _order = other._order ;
    int size = other._order;
    
    _coefs = new double[size + 1];
    // copy_list(_coefs, rhs._coefs, _order+1);
    for (int i = 0; i < _order + 1; i++)
    {
        _coefs[i] = other._coefs[i];
    }
}


//assignment
Poly& Poly::operator = (const Poly& rhs)
{
    //check for self reference
    if (this == &rhs)
    {
       return *this;
    }
    delete[] _coefs;
    _coefs = new double[rhs._order + 1];
    _order = rhs._order;
     assert(_coefs != nullptr && "i has to be b/w 0 & max");
    //copy_list(_coefs, rhs._coefs, _order+1);
    
    for (int i = 0; i < _order + 1; i++)
    {
       _coefs[i] = rhs._coefs[i];
    }
    return *this;
}

//destructor
Poly::~Poly()
{
    _order = 0;
    const bool debug = true;
//    if (debug) cout << "DESTRUCTOR FIRED: " << *_coefs << endl << endl << endl ;
    delete [] _coefs;
    _coefs = nullptr ;
}

Poly& Poly::operator *= (const Term& t)
{
    List<Term>::Iterator it ;

    for( it = _poly.Begin(); it != _poly.End(); it++)
    {
        *it *= t;
    }
    return *this;
}

Poly& Poly::operator *= (const Poly& RHS)
{
    List<Term>::Iterator it;
    Poly result = RHS;
    
    for( it = _poly.Begin(); it != _poly.End(); it++)
    {
      result *= (*it);
    }
    
    return *this;
}

Poly& Poly::operator += (const Term& t)
{
    List<Term>::Iterator it ;
    
    for( it = _poly.Begin(); it != _poly.End(); it++)
    {
        *it += t;
    }
      
    return *this;
}

Poly& Poly::operator += (const Poly& RHS)
{
    for(int i=0; i < RHS._order + 1; i++)
    {
        _coefs[i] += RHS._coefs[i];
    }
    return *this;
}


Poly& Poly::operator -= (const Poly& RHS)
{
    for(int i=0; i < RHS._order + 1; i++)
    {
        _coefs[i] -= RHS._coefs[i];
    }
    
    return *this;
}


bool operator == (const Poly& lhs, const Poly& rhs)
{
    if (lhs._order == rhs._order)
    {
        return true;
    }
    return false;
}


bool operator != (const Poly& lhs, const Poly& rhs)
{
    if (lhs._order != rhs._order)
    {
        return true;
    }
    return false;
}

bool operator > (const Poly& lhs, const Poly& rhs)
{
  if(lhs._order > rhs._order)
        return true;
    else
        return false;
    //lhs._order == rhs._order false
}

bool operator < (const Poly& lhs, const Poly& rhs)
{
    if(lhs._order < rhs._order)
        return true;
    else
        return false;
}

Term Poly::operator[]( int order ) const
{
    if( order < 0 || order > _order )
    {
      cout << "order to out of range. " << endl;
    }

    Term result (_coefs[order], order);
    return result ;
}


//====================================== NEW STUFF ================================\\








// The [] operator is gonna get the information for the term located in that position in the poly object.
//return the _coef and _exponent for the corresponding term.
Poly operator + (const Poly& lhs, const Poly& rhs)
{
    
    int size;
    Poly result ;
    Poly smaller = lhs ;
    
    if(lhs < rhs)
    {
        size = lhs.order(); //no change to order
        result = rhs ;
        smaller = lhs;
    }
    else
    {
        size = rhs.order();
        result = lhs ;
        smaller = rhs; //assers that the samller one is this
    }
    
    //start for loop backwards for small one
    for ( int i= size; i >= 0; i-- ) //backwards for loop starting at size to 0
    {
        result = result + smaller[i];
    }
    
    result.fix_order();
    return result ;
    
    
}

//For the poly + term. check term._exponent and then add the term._coef to the coef of the term that has the same exponent in the poly object



Poly operator + (const Poly& lhs, const Term& t)
{

    int size;
    Poly newCoef = lhs ; //size

    
    if(t._exp <= lhs.order() )
    {
        newCoef._coefs[t._exp] += t._coef;
        
        return newCoef;
    }
    
    //you said we would fix this later dont get mad
    double* coefCopy = new double[t._exp + 1] ;
    
    for(int i=0; i <t._exp + 1; i++)
    {
        coefCopy[i] = 0.0;
    }
    coefCopy[t._exp] += t._coef ;
    Poly copyed(coefCopy, t._exp);
    delete [] coefCopy;
    
    Poly result = newCoef + copyed;

    result.fix_order();
    return result ;

}


Poly operator - (const Poly& p)
{
    Poly result = p;
    for(int i = 0; i< p._order + 1; i++)
    {
        result._coefs[i] *= (-1);
    }
    return result;
}


Poly operator - (const Poly& lhs, const Poly& rhs)
{
    //lol
    return lhs + (-rhs);

}

Poly operator * (const Poly& lhs, const Term& t)
{
// need loop through an multiply _coef of same _order
// Similar to +(Poly, Term). You will need to reallocate the array.
    Poly result ;
    
    
    //because term is only 1 thing loop trhough size of order and multipy one single term to every term of lhs
    
    for(int i = lhs.order(); i >= 0; i-- )
    {
        Term lhsTerm = lhs[i]; //every term of lhs
        Term multResult(t._coef * lhsTerm._coef, t._exp + lhsTerm._exp);
        result = result + multResult;
    }
    return result;
}



Poly operator * (const Poly &lhs, const Poly& rhs)
{
    Poly result;
    
    for(int i = lhs.order(); i >= 0; i--)
    {
        //want lhs terms multipled by rhs
        result = result + rhs * lhs[i] ;
        
    }
    return result;
}


Poly operator / (const Poly& lhs, const Poly& rhs)
{
//    int sizeCounter = 0;
//    int size = lhs._order + 1 ;
    //size = largest term

    Poly resultQuotient;
    Poly remainder = lhs ;
    
    
    //remainer
    //

    while( remainder.order() >= rhs.order() )
    {
        // have multplication of term defined and poly
        // have subtraction of poly defined

        //remianer = poly
        //remainer.order = int
        //poly[int] = term
    
        Term stepTerm = remainder[remainder.order()] / rhs[rhs.order()]; //changing  => 2x^2
        // use Term to add to resultQuationed = poly
        resultQuotient = resultQuotient + stepTerm; //adding => 2x^2
        
        remainder = remainder - rhs * stepTerm ; // -7x^2 + 4x

    }
    return resultQuotient;
    
}

Poly operator % (const Poly& lhs, const Poly& rhs)
{
    Poly remainder = lhs - rhs * (lhs / rhs);
    //remainder need to be left over after deivide left by right
    //need that remainder minus start get left over
    return remainder;
}





ostream& operator << (ostream& outs, const Poly& p)
{
    int size = p._order ;
    cout << "[ " ;
    
    for(int i=0; i< size + 1; i++ )
    {
        outs  <<  p[p._coefs ,i]  ;
    }
    cout << "] ";
    
    return outs;
 
    /*
     
     int size = p._order ;
    cout << "[" ;
        
            for(int i=0; i< size + 1; i++ )
            {
                outs << " " <<  p._coefs[i]   << " " ;
            }
            cout << "] ";
            
            return outs;
     
     
     */
    
    
    
}

istream& operator >> (istream& ins, Poly& p)
{
    
    //enter coef, x then power
   // ins >> p._coefs >> x >> power >> p._order;
    
//
//   // while(p._coefs[p._order] != 0)
//   ins >> p._coefs[p._order] ;
//
//    return ins;
    char x;
    
    while( p._order != 0)
    {
        int exp = p._order ;
        int c = p._coefs[exp];
        ins >> c >> x >> exp ;
    }
    return ins;
}


void Poly::fix_order()
{
    
    for(int i = _order; i >= 0; i--)
    {
        
        if( _coefs[i] == 0.0 )
        {
            _order--;
        }
        else
            break;
    }

}






#endif /* PolyPoly_h */
