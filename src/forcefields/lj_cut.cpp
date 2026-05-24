#include <iostream>
#include <vector>

#include "lj_cut.h"

void lj_cut::force(int i, int j, std::vector< std::vector<double> > x, std::vector< std::vector<double> > f, double rcut){
  double dx, dy, dz;
  double rsq, rsqinv, r6inv;
  double fx, fy, fz, fprefactor;
  double sigma, epsilon;
  // lj parameters
  sigma = 1;
  epsilon = 1;

  dx = x[i][0] - x[j][0];
  dy = x[i][1] - x[j][1];
  dz = x[i][2] - x[j][2];
  rsq = dx * dx + dy * dy + dz * dz;
  if ( rsq < rcut*rcut ){
    rsqinv = 1/rsq;
    r6inv = rsqinv * rsqinv * rsqinv;
    

    fprefactor = 24 * epsilon * rsqinv * r6inv * (2 * r6inv - 1);
    fx = dx*fprefactor;
    fy = dy*fprefactor;
    fz = dz*fprefactor;

    // update forces
    f[i][0] += fx;
    f[i][1] += fy;
    f[i][2] += fz;

    // update forces of particle j
    f[j][0] -= fx;
    f[j][1] -= fy;
    f[j][2] -= fz;

    printf("fx = %4.2f\n", fx);
    printf("fy = %4.2f\n", fy);
    printf("fz = %4.2f\n", fz);
  }

}

