/*
* Author: KESSA RYCHLICK
* Project: Polynomial
* Purpose: Make a polynomial class
* Notes: Use term stuff to add to polynomial
*
*/
#include <iostream>
#include "TermPoly.h"
#include "PolyPoly.h"
#include "TestPoly.h"

using namespace std;



const int SIZE1 = 4;
const int SIZE2 = 3;

int main()
{
//    double a1[5] = {9,2,7,2};
//    double a2[2] = {3,2};
//
//
//    Poly p1(a1, 4);
//    Poly p2(a2, 1);
    
    
    
    Term t1(5,4);
    cout << "T1: " << t1;
    cout << endl;


    Term t2(3,10);
    cout << "T2: " << t2;
    cout << endl;

    cout << "===================================================================" << endl ;


    testAdd();
    testSubtract();
    testMultiply();
    testDivide();



    double a1[SIZE1+1] = {-7,0,3,4,5}; //3 + 2x^1
    double a2[SIZE2+1] =  {0,4,9}; // 4 + 1x^1

    Poly p1(a1, SIZE1);
    Poly p2(a2, SIZE2);


    cout << p1;
    cout << "& ";
    cout << p2;
    cout << endl ;


    cout << "=============================== ADD ===============================" << endl ;
    cout << p1;
    cout << "+ ";
    cout << p2;
    cout << "= ";
    Poly a = p1 + p2;
    cout << a;
    cout << endl;

    
    
    
    
    cout << "============================== print ==============================" << endl ;
    
    double z1[SIZE1+1] = {-7,0,-3,4,5}; //3 + 2x^1
   
    Poly o1(z1, SIZE1);
    cout << o1;
    cout << endl ;


    cout << "=============================== END ===============================" << endl ;

      
      
    
}
