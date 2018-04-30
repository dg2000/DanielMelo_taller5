#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

double dp1dt( double e, double q1)
{

  double num = -2.0*q1;

  double den = pow(4.0*q1*q1  + e*e, 1.5);

  return num/den;
}


double dp2dt( double e, double q1, double q2)
{

  double num1 = q1 - q2;

  double den1 = pow( (q1-q2)*(q1-q2) + e*e/4.0 , 1.5);

  double num2 = -(q1 + q2);

  double den2 = pow( (q1+q2)*(q1+q2)  +  e*e/4.0 , 1.5);

  double A = num1/den1;

  double B = num2/den2;
  

  return A + B;
}    


int  main()
{

  double e = 1.0/1000.0;

  double a = 1.0/( pow(2.0, 1.5) );

  double h = 0.006;

  double T = 3000.0;

  int N = T/h;

  double t = 0.0;

  double q1 = a;

  double q2 = -a;

  double p1 = 0.0;

  double p2 = 0.0;

  for (int i = 0; i < N; i++)
    {

      double antiguo = q1;

      
      //Para q1
      double a1 = p1;
      double b1 = p2;
      double c1 = dp1dt( e, q1);
      double d1 = dp2dt( e, q1, q2);


      //Segundo paso
      double a2 = p1 + c1*h/2.0;
      double b2 = p2 + d1*h/2.0;
      double c2 = dp1dt( e, q1 + a1*h/2.0);
      double d2 = dp2dt( e, q1 + a1*h/2.0, q2 + b1*h/2.0);

      
      //Tercer paso
      double a3 = p1 + c2*h/2.0;
      double b3 = p2 + d2*h/2.0;
      double c3 = dp1dt( e, q1 + a2*h/2.0);
      double d3 = dp2dt( e, q1 + a2*h/2.0, q2 + b2*h/2.0);


      //Cuarto paso
      double a4 = p1 + c3*h;
      double b4 = p2 + d3*h;
      double c4 = dp1dt( e, q1 + a3*h);   
      double d4 = dp2dt( e, q1 + a3*h, + b3*h);

      
      t = t + h;

      p1 = p1 + h*(c1 + 2.0*c2 + 2.0*c3 + c4)/6.0;
      p2 = p2 + h*(d1 + 2.0*d2 + 2.0*d3 + d4)/6.0;

      q1 = q1 + h*(a1 + 2.0*a2 + 2.0*a3 + a4)/6.0;
      //cout << t << " " << q1 << " " << q2 << " " << p1 << " " << p2 <<  endl;
      q2 = q2 + h*(b1 + 2.0*b2 + 2.0*b3 + b4)/6.0;

      if( (antiguo < 0.0 && q1 > 0.0) || (antiguo > 0.0 && q1 < 0.0) )
      {
        cout << q2 << " " << p2 << endl;
      }
      
    }
}

      
					       
