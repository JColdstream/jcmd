#include <iostream>
#include <vector>
#include "forcefields/lj_cut.h"
#include "atoms.h"

int main() {

  lj_cut lj;
  Atoms atoms;

  printf("Hello world\n");
  atoms.add_atom(0.0, 0.0, -1.0);
  atoms.add_atom(0.0, 0.0,  1.0);
  printf("x = %4.2f\n", atoms.x[0][2]);
  // x.push_back({0,0,-1.0});
  // x.push_back({0,0,1.0});
  // printf("x = %4.2f\n", x[0][2]);

  // v.push_back({0,0,-1.0});
  // v.push_back({0,0,1.0});

  // f.push_back({0,0,-1.0});
  // f.push_back({0,0,1.0});

  lj.force(0,1,atoms.x,atoms.f,2.5);

  return 0;
}


