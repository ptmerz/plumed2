//#include "PlumedMain.h"
#include "ExchangePatterns.h"

#define length(a) ( sizeof ( a ) / sizeof ( *a ) )

using namespace std;

namespace PLMD{

void ExchangePatterns::setSeed(int seed)
{
  random.setSeed(seed);
}

void ExchangePatterns::getList(int *ind, int nrepl)
{
  //int nrepl = length(ind);
  //int nrepl = comm.Get_size();
  /* in principle here we can add a switch(patter) case in order to get a list of exchanges dependent on a specific pattern */
  for(int i=0;i<nrepl;i++) {
    int stat=1;
    while(stat) {
      stat=0;
      ind[i] = random.RandU01()*nrepl;
      for(int j=0;j<i;j++) if(ind[i]==ind[j]) stat=1;
    }
  }
}

}
