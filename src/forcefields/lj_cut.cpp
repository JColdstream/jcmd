#include <iostream>
#include <vector>

#include "atoms.h"
#include "lj_cut.h"

void lj_cut::force(int i, int j, Atoms atoms, double rcut){
  double dx, dy, dz;
  double rsq, rsqinv, r6inv;
  double fx, fy, fz, fprefactor;
  double sigma, epsilon;
  // lj parameters
  sigma = 1;
  epsilon = 1;

  dx = atoms.x[i][0] - atoms.x[j][0];
  dy = atoms.x[i][1] - atoms.x[j][1];
  dz = atoms.x[i][2] - atoms.x[j][2];
  rsq = dx * dx + dy * dy + dz * dz;
  if ( rsq < rcut*rcut ){
    rsqinv = 1/rsq;
    r6inv = rsqinv * rsqinv * rsqinv;
    

    fprefactor = 24 * epsilon * rsqinv * r6inv * (2 * r6inv - 1);
    fx = dx * fprefactor;
    fy = dy * fprefactor;
    fz = dz * fprefactor;

    // update force of particle i
    atoms.f[i][0] += fx;
    atoms.f[i][1] += fy;
    atoms.f[i][2] += fz;

    // update force of particle j
    atoms.f[j][0] -= fx;
    atoms.f[j][1] -= fy;
    atoms.f[j][2] -= fz;

    printf("fx = %4.2f\n", fx);
    printf("fy = %4.2f\n", fy);
    printf("fz = %4.2f\n", fz);
  }

}

