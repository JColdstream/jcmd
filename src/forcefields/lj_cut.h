#ifndef __LJ_CUT__
#define __LJ_CUT__

class lj_cut
{
  public:
    void force(int i, int j, std::vector< std::vector<double> > x, std::vector< std::vector<double> > f, double rcut);
};

#endif
