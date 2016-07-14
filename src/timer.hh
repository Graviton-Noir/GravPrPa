#ifndef _TIMER_HH_
#define _TIMER_HH_

#include <chrono>

using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;

struct scoped_timer
{
  scoped_timer(double& s)
    : seconds(s)
    , t0(steady_clock::now())
    {}

  ~scoped_timer()
  {
    auto tmp = duration_cast<nanoseconds>(steady_clock::now() - t0);
    seconds = tmp.count();
    std::cout << "Time : " << seconds << " ms" << std::endl;
  }

  double&                     seconds;
  steady_clock::time_point    t0;
};

#endif
