#ifndef KPN_H
#define KPN_H

#include <systemc.h>

SC_MODULE(kpn)
{
private:
    sc_fifo<unsigned int> a, b, c, d;
    unsigned int e;

public:
    SC_CTOR(kpn) : a(10), b(10), c(10), d(10) // : ADD THINGS HERE
    {
        c.write(0);
        b.write(1);
        SC_THREAD(add);
        // sensitive <<a<<c;
        SC_THREAD(delay);
        //   sensitive<<d;
        SC_THREAD(split);
        // sensitive<<b;
    }

private:
    void delay();
    void add();
    void split();
};

#endif // KPN_H
