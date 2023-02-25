#include <unistd.h>
#include <systemc.h>

#include "kpn.h"

void kpn::delay()
{
    while (true)
    {
        c.write(d.read());
    }
}

void kpn::add()
{

    while (true)
    {

        b.write(a.read() + c.read());
    }
}

void kpn::split()
{

    for (unsigned int i = 0; i < 10; i++)
    {
        //THe error i made that i was reading twice from b.B was empty so it was getting blocked
        e = b.read();
        d.write(e);

        a.write(e);

        cout << e << endl;
    }
    sc_stop();
}
