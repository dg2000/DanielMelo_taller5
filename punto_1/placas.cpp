#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;



int main()
{
  double L = 5.0;

  double l = 2.0;

  double d = 1.0;

  double h = 5.0/512.0;

  double Vo = 50.0;

  double pi = 3.14159;

  int nx = L/h + 1;

  int nt = 2.0*pow(L/h, 2.0);

  double w = 2.0/(2.0 + pow( 4.0 - pow(cos(pi/(nx+1.0))  +  cos(pi/(nx-1.0)), 2.0), 0.5) );

  double** nuevo = new double*[nx];

  double** Ex = new double*[nx-2];	  

  double** Ey = new double*[nx-2];


  //double** segundo_viejo = new double*[nx];

  for(int i = 0; i < nx; i++)
    {
      nuevo[i] = new double[nx];
     
      for(int j = 0; j < nx; j++)
	{
	  nuevo[i][j] = 0.0;
	}
    }
  
  int t = 0;

  bool vale_la_pena = true;

  while(t < nt)
    {
      //w = 2.0*w/w ;
      w  = 1.7;
      nt = 20000;
      
      for(int x = 1; x < nx-1; x++)
	{
	  for(int y = 1; y < nx-1; y++)
	    {

	      double r = (nuevo[x+1][y] + nuevo[x-1][y] + nuevo[x][y+1] + nuevo[x][y-1])/4.0     - nuevo[x][y];
		  
	      nuevo[x][y] = nuevo[x][y] + w*r ;

	      vale_la_pena = (pow(r, 2.0) <= 3.0) && vale_la_pena;
	      
	      if( y*h >= 1.5 && y*h <= 3.5)
		{
		  if(pow((x*h - 2.0), 2.0)  <= 0.0001)
		    {
		      nuevo[x][y] = Vo;
		      //original[x][y] = Vo;
		    }
	      
		  else if(pow(x*h - 3.0, 2.0) <= 0.0001)
		    {
		      nuevo[x][y] = -Vo;
		      //original[x][y] = -Vo;
		    }
		}	      
	    }
	}
      vale_la_pena = !vale_la_pena;
      
      t++;
    }

  for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < nx; j++)
	{
	  cout << nuevo[i][j] << " "  ;
	}

      cout << endl;
    }

 

 
  return 0;
}
