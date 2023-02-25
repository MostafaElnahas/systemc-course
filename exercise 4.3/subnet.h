#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

SC_MODULE(subnet)
{
sc_port<placeInterface> in;
sc_port<placeInterface> out;

    placechannel active;

    transition<1, 1, 0> WR;
    transition<1, 1, 0> RD;
    transition<1, 1, 1> ACT;
    transition<1, 1, 0> PRE;

    SC_CTOR(subnet) : active(0), WR("WR"), RD("RD"), PRE("PRE"), ACT("ACT"),in("in"),out("out")
    {
        ACT.in.bind(in);
        ACT.inhibitors.bind(active);
        ACT.out.bind(active);
        PRE.in.bind(active);
        PRE.out.bind(out);
        WR.in.bind(active);
        WR.out.bind(active);
        RD.in.bind(active);
        RD.out.bind(active);

    }
    
};
#endif // SUBNET_H
