#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

SC_MODULE(exor){

public:
sc_in<bool>(A);
sc_in<bool>(B);
sc_out<bool>(Z);
sc_signal<bool>h1,h2,h3;
nand n1,n2,n3,n4;
SC_CTOR(exor):A("A"),B("B"),Z("Z"),n1("n1"),n2("n2"),n3("n3"),n4("n4")
{
n1.A(A);
n1.B(B);
n1.Z(h1);

n2.A(A);
n2.B(h1);
n2.Z(h2);

n3.A(B);
n3.B(h1);
n3.Z(h3);

n4.A(h2);
n4.B(h3);
n4.Z(Z);

}




};
#endif // EXOR_H
