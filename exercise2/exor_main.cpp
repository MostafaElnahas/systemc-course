#include <systemc.h>

#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int, char**)
{
    sc_signal<bool> sigA, sigB, sigZ;
    
 sc_clock clk("clk", 10, SC_NS,0.5, 1, SC_NS);

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);
    Stim1.clk(clk);

    exor DUT("exor");
    DUT.A(sigA);
    DUT.B(sigB);
    DUT.Z(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);
    mon.clk(clk);

 sc_trace_file* Tf;
  Tf = sc_create_vcd_trace_file("traces");
sc_trace(Tf, clk, "clk");
  sc_trace(Tf, sigA  , "A" );
  sc_trace(Tf, sigB  , "B" );
  sc_trace(Tf, sigZ  , "F" );
  sc_trace(Tf, DUT.A, "S1");
  sc_trace(Tf, DUT.B, "S2");
  sc_trace(Tf, DUT.Z, "S3");

    sc_start();  // run forever
  sc_close_vcd_trace_file(Tf);

    return 0;
}
