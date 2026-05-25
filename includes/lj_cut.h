#ifndef __LJ_CUT__
#define __LJ_CUT__

#include "src/atoms.h"

class lj_cut
{
  public:
    void force(int i, int j, Atoms atoms, double rcut);
};

#endif
