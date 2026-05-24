#include <iostream>
#include <vector>

#include "atoms.h"

void Atoms::add_atom(double rx, double ry, double rz, double vx, double vy, double vz, double fx, double fy, double fz){
  x.push_back( { rx, ry, rz } );
  v.push_back( { vx, vy, vz } );
  f.push_back( { fx, fy, fz } );
}
