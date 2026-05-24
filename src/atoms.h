#ifndef __ATOMS__
#define __ATOMS__

#include <vector>

class Atoms
{
  public:
     std::vector<std::vector<double>> x;
     std::vector<std::vector<double>> v;
     std::vector<std::vector<double>> f;

     void add_atom(double rx, double ry, double rz, double vx=0, double vy=0, double vz=0, double fx=0, double fy=0, double fz=0);

};

#endif
