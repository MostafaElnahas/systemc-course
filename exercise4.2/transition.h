#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"
template <unsigned int N = 1, unsigned int M = 1>
SC_MODULE(transition)
{
public:
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    SC_CTOR(transition) {}
    void fire()
    {
        int sum = 0;
        for (unsigned int i = 0; i < N; i++)
        {

            if (in[i]->testTokens() > 0)
            {
                sum = sum + 1;
            }
            else
                sum = sum - 1;
        }


        if (sum == N)
        {

            for (unsigned int i = 0; i < N; i++)
            {
                in[i]->removeTokens(1);
            }
            for (unsigned int i = 0; i < M; i++)
            {
                out[i]->addTokens(1);
            }
            std::cout << this->name() << ": Fired" << std::endl;
        }
        else
        {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }
        sum = 0;
    }
};

#endif // TRANSITION_H
