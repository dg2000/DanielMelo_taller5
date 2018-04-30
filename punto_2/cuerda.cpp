#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;



int main()
{

  double T;
  T = 40.0;

  double p;
  p = 10.0;

  double max;
  max = 200.0;

  double c;
  c = pow(T/p, 0.5);

  double dt;
  dt = 0.01;

  double dx;
  dx = c*dt;//pow(D*dt, 0.5);

  double L;
  L = 100.0 ;

  int nx;
  nx = (L/dx) +1 ;

  double numerador;
  numerador = dt*dt*c*c/(dx*dx);

  int nt;
  nt = 200.0/dt;

  int i;

  int t;

  int z;

  double a;

  double* nuevo; 
  nuevo = new double[nx];

  double* viejo; 
  viejo = new double[nx];

  double* segundo_viejo; 
  segundo_viejo = new double[nx];

  double* original;
  original = new double[nx];

  double** fotos;
  fotos = new double*[nt+1];

  int j;

  for( i = 0; i < nt+1; i++)
    {
      fotos[i] = new double[nx];
      
    }

  for( i = 0; i < nx; i++)
    {
     
      fotos[0][i] = i*dx;
    }

  for ( i = 0; i < nx; i++)
    {
      if(i*dx < 0.8*L)
	{
	  viejo[i] = i*dx*1.25/L;
	  original[i] = i*dx*1.25/L;
	}
      else
	{
	  viejo[i] = 5.0 - 5.0*i*dx/L;
	  original[i] = 5.0 - 5.0*i*dx/L;
	}
      
    }

  nuevo[0] = 0.0;
  nuevo[nx-1] = 0.0;

  for( t = 0; t < nt; t++)
    {
      int i;
      double a;
      
      for( i = 0; i < nx; i++)
	{
	  fotos[t+1][i] = viejo[i];
	   
	} 
      
      if(t==0)
	{
	  for( i = 1; i < nx-1; i++)
	    {
	      a  = numerador*(viejo[i+1] + viejo[i-1] - 2.0*viejo[i]);

	      nuevo[i] = (a + 2.0*viejo[i])/2.0;
	    }

	}
      else
	{
	  for( i = 1; i < nx-1; i++)
	    {
	      a  = numerador*(viejo[i+1] + viejo[i-1] - 2.0*viejo[i]);
	      
	      nuevo[i] = a + 2.0*viejo[i] - segundo_viejo[i];
	      
	    }

	}
	  
      
      for( i = 1; i < nx-1; i++)
	{
	  segundo_viejo[i] = viejo[i];
	  
	  viejo[i] = nuevo[i];

	}
      
    }
 
  for( z = 0; z < nx; z++)
    {
      
      for( i = 0; i < nt+1; i+=120)
	{
	  
	  cout << fotos[i][z] << " "; 
	}
      
      cout << endl;
    }

  return 0;
}
