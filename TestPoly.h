#ifndef TestPoly_h
#define TestPoly_h

#include "TermPoly.h"
#include "PolyPoly.h"

void test_div(const Poly& p, const Poly& q)
{
       Poly r = p / q;
       cout<<p << " / " << q ;
       cout<<"      = "<< r <<endl;
       cout<<"  rem = "<<p % q<<"  " <<endl <<endl;
       //if r = p / q then r * q + p % q should be equal to p:
       if( ( (r * q) + (p % q) ) == p)
       {
           cout << "VERIFIED" << endl;
       }
       else
       {
           cout<< endl << "   ***VERIFICATION FAILED"<<endl;
           cout<<"   r * q: " << r * q<<endl;
           cout<<"   p % q: " << p % q<<endl;
           cout<<"   r * q + p % q: "<<r * q + p % q<<"=/="<<p<<endl;
       }
}


void test_add(const Poly& p, const Poly& q)
{
       Poly r = p + q;
       cout << p << " + " << q << endl;
       cout << "      = " << r;
}


void test_all()
{
    char choice;   // Command entered by the user
    int num, exp;
    double value;
    
    //P: [+3.0X^3 +2.0X^2 +X +5.0 ]
    // 5.0, 1.0, 2.0, 3.0
    //Q: [+4.0X^4 +3.0X^3 +2.0X^2 +X +5.0 ]
    //5.0, 1.0, 2.0, 3.0, 4.0
    const int sizeA1 = 4;
    const int sizeA2 = 5;
    
    double a1[sizeA1] = {5.0, 1.0, 2.0, 3.0};
    double a2[sizeA2] = {5.0, 1.0, 2.0, 3.0, 4.0};

    Poly p1(a1, sizeA1 - 1);
    Poly p2(a2, sizeA2 - 1);

    
    do
    {
        cout << endl;
        cout << "===================== Start =====================" << endl << endl ;
        cout << p1;
        cout << " &  ";
        cout << p2;
        cout << endl ;
        cout << "            [ + ] =      Add polynomials" << endl;
        cout << "            [ - ] = Subtract polynomiasl" << endl;
        cout << "            [ * ] = Multiply polynomials" << endl;
        cout << "            [ / ] =   Divide polynomials" << endl;
        cout << "            [ % ] = Remainder polynomial" << endl;
        cout << "            [ A ] =    Change polynomial" << endl;
        cout << "            [ E ] =                 Exit" << endl;
        
        
        
        cout << "Enter choice: ";
        cin >> choice;
        Poly r;
        int order ;
        double coef;

        Term t(coef, order);
        
        switch (choice)
        {
            case '+': // add polynomials 1 and 2
                cout << "====================== ADD ======================" << endl ;
                cout << p1;
                cout << " + ";
                cout << p2;
                cout << " = ";
                r = p1 + p2;
                cout << r;
                break;
            case '-':
                cout << "==================== SUBTRACT ====================" << endl ;
                cout << p1;
                cout << " + ";
                cout << p2;
                cout << " = ";
                cout << p1 - p2;
                break;
            case '*':
                cout << "==================== MULTIPLY ====================" << endl ;
                cout << p1;
                cout << " + ";
                cout << p2;
                cout << " = ";
                cout << p1 * p2;
                break;
            case '/':
                cout << "==================== DIVIDE ====================" << endl ;
                cout << p1;
                cout << " + ";
                cout << p2;
                cout << " = ";
                cout << p1 / p2;
                break;
            case '%':
                cout << "=================== REMAINDER ===================" << endl ;
                cout << p1;
                cout << " + ";
                cout << p2;
                cout << " = ";
                cout << p1 %
                p2;
                break;
            case 'A':
            case 'a':
                cout << "================= ADD in Term ===================" << endl ;
                cout<< "Entry: ";
                cin >> p2;
                cout << p2 ;
//                cin >> coef;
//                cout<< "Order: ";
//                cin >> order;
//                int order ;
//                double coef;
//                Term t(coef, order);
                break;
            case 'E':
            case 'e':
                cout << "====================== EXIT =====================" << endl ;
                exit(1);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    while ((choice != 'Q'));
}



void test()
{
    char choice;   // Command entered by the user
    int num, exp;
    double value;
    
    //P: [+3.0X^3 +2.0X^2 +X +5.0 ]
    // 5.0, 1.0, 2.0, 3.0
    //Q: [+4.0X^4 +3.0X^3 +2.0X^2 +X +5.0 ]
    //5.0, 1.0, 2.0, 3.0, 4.0
    const int sizeA1 = 4;
    const int sizeA2 = 5;
    
    double a1[sizeA1] = {5.0, 1.0, 2.0, 3.0};
    double a2[sizeA2] = {5.0, 1.0, 2.0, 3.0, 4.0};

    Poly p1(a1, sizeA1 - 1);
    Poly p2(a2, sizeA2 - 1);


   
}

void testAdd()
{
      double a1[4] = {2,1};
      double a2[2] = {2,1};
      
      Poly p1(a1, 1);
      Poly p2(a2, 1);
      
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
}

void testMultiply()
{
      double a1[4] = {2,1};
      double a2[2] = {2,1};
      
      
      Poly p1(a1, 1);
      Poly p2(a2, 1);
      
      cout << "=============================== MUL ===============================" << endl ;
      cout << p1;
      cout << "* ";
      cout << p2;
      cout << "= ";
      Poly m = p1 + p2;
      cout << m;
      cout << endl;
}

void testSubtract()
{
    double a1[4] = {2,1};
    double a2[2] = {2,1};
    
    
    Poly p1(a1, 1);
    Poly p2(a2, 1);
    
    
    cout << "=============================== SUB ===============================" << endl ;
    cout << p1;
    cout << "- ";
    cout << p2;
    cout << "= ";
    Poly s = p1 - p2;
    cout << s;
    cout << endl;


}



void testDivide()
{
      double a1[4] = {2,1};
      double a2[2] = {2,1};
      
      
      Poly p1(a1, 1);
      Poly p2(a2, 1);
     
      cout << "=============================== DIV ===============================" << endl ;
      cout << p1;
      cout << "/ ";
      cout << p2;
      cout << "= ";
      Poly r = p1 / p2;
      cout << r;
      cout << endl;
    
    
    double d1[4] = {-20,7,6};
    double d2[2] = {5,2};


    Poly b1(d1, 3);
    Poly b2(a2, 1);

    cout << "=============================== DI2 ===============================" << endl ;
    cout << b1;
    cout << "/ ";
    cout << b2;
    cout << "= ";
    Poly l = b1 / b2;
    cout << l;
    cout << endl;

    
    
    
    cout << "===================================================================" << endl ;
}



#endif /* TestPoly_h */
