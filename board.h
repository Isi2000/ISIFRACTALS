#include<vector>
#include<iostream>


class complex
{
public:
  double r; //real part
  double i; //img part
  complex(double r_, double i_): r{r_}, i{i_} {}
  double mod_2()
  {
    return (r*r + i*i);
  };
};
bool E(complex a, complex b)
{
  bool res = false;
  if (a.r == b.r and a.i == b.i)
    {
      res = !res;
    }
  return res;
}

complex coordinate_change(int n, int d)
{
  //n is the position in the vector, d is the dim of the board
  //function that associates a coodinate system to an int
  complex c(0,0);
   //type conversions are ugly, but int division is efficient
   int _i = c.i;
   int _r = c.r;
   _i = n / d;
   _r = n % d;

   double i_ = _i;
   double r_ = _r;
   c.i = (i_/d)*2.26 - 1.13;
   c.r = (r_/d)*2.48 - 2;
   return c;
};

complex next_s(complex z0, complex c) 
    // this function calculates the number of iterations for each pixel
  {
    //maybe implement mod in struct
    //use the recursive formula:
    complex z(0,0);
    z.i = 2*z0.i*z0.r + c.i;
    z.r = z.r*z.r - z.i*z.i + c.r;
    return z;
  };

int num_iter(complex z, complex c, int max_iter)
{
    int iter = 0;
    while (iter<max_iter && z.mod_2()<4)
      {
	z = next_s(z, c);
	++iter;
      }
    return iter;
};



class BOARD
{
private:
  int m_dim;
  std::vector<int> m_board;
public:
  BOARD(int dim): m_dim{dim}, m_board(m_dim*m_dim, 256)
  {
  }

  
  void print_board() {
    for (int i = 0; i < m_dim * m_dim; ++i)
      {
      std::cout << m_board[i] << ' ';
      if (i % (m_dim - 1) == 0) {
        std::cout << '\n';
      }
    }
  };
  

  void board_iter()
  {
    //around z = 0,0
    complex z(0,0);
    for (int i=0; i<m_dim*m_dim; ++i)
      {
	std::cout<< 256 - num_iter(z ,coordinate_change(i, m_dim), 256) << ' ';
	if (i%(m_dim-1) == 0)
	  {
	    std::cout<<'\n';
	  }
      }

  };
};
