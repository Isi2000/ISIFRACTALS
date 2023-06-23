#include<vector>
#include<iostream>


class complex
{
private:
  double r; //real part
  double i; //img part
public:
 complex(double R, double I): r{R}, i{I} {};

  double mod_2()
  {
    return (r*r + i*i);
  };  
};

class BOARD
{
  
}
  
