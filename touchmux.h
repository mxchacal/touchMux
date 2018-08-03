#ifndef TOUCHMUX_H
#define TOUCHMUX_H

class touchMux {
public:
  touchMux(int sig0, int sig1, int sig2, int sig3, int readpin);

  int   read(int pin);
  bool  touched(int pin);
  void  setTreshold(int treshold);
  void  autoTreshold();

private:
  char sig0_, sig1_, sig2_, sig3_, readpin_;
  int treshold_;
};

#endif
