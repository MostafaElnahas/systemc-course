#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

SC_MODULE(toplevel)
{

    placechannel idle;

   subnet s1,s2;


    SC_CTOR(toplevel) : idle(2),s1("s1"),s2("s2")
    {
        s1.in.bind(idle);
        s1.out.bind(idle);
        s2.in.bind(idle);
        s2.out.bind(idle);
        SC_THREAD(PROCESS);
    }
    void PROCESS()
    {

        while (true)
        {

wait(10, SC_NS);
s1.ACT.fire();
wait(10, SC_NS);
s1.ACT.fire();
wait(10, SC_NS);
s1.RD.fire();
wait(10, SC_NS);
s1.WR.fire();
wait(10, SC_NS);
s1.PRE.fire();
wait(10, SC_NS);
s1.ACT.fire();
wait(10, SC_NS);
s2.ACT.fire();
wait(10, SC_NS);
s2.ACT.fire();
wait(10, SC_NS);
s1.PRE.fire();
wait(10, SC_NS);
s2.PRE.fire();
wait(10, SC_NS);
sc_stop();
        }
    }
};

int sc_main(int, char **)
{
    toplevel top("toplevel");

    sc_start();
    return 0;
}
