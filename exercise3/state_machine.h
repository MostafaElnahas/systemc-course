#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>
SC_MODULE(stateMachine)
{
public:
        sc_in<char> input;
        sc_in<bool> clk;
        enum base
        {
                Start,
                G,
                GA,
                GAA,
                GAAG
        };
        base state;

        SC_CTOR(stateMachine) : input("input"), clk("clk"), state()
        {
                SC_METHOD(process)
                {
                        sensitive << input << clk.pos();
                        dont_initialize();
                }
        }

        void process()
        {
                switch (state)
                {
                case (Start):

                        if (input == 'G')
                        {
                                state = G;
                        }
                        else if (input == 'A' || 'T' || 'C')
                                state = Start;

                        break;

                case (G):
                        state = G;
                        if (input == 'A')
                        {
                                state = GA;
                        }
                        else if (input == 'G')
                        {
                                state = G;
                        }
                        else if (input == 'T' || 'C')

                                state = Start;

                        break;
                case (GA):
                        if (input == 'A')
                        {
                                state = GAA;
                        }

                        else if (input == 'G')
                        {

                                state = G;
                        }
                        else if (input == 'T' || 'C')

                                state = Start;

                        break;
                case (GAA):

                        state = GAA;
                        if (input == 'G')
                        {

                                state = GAAG;
                        }
                        else if (input == 'A' || 'T' || 'C')

                                state = Start;

                        break;

                case (GAAG):
                        state = GAAG;

                        cout << "GAAG" << endl;

                        if (input == 'A' || 'T' || 'C')
                        {

                                state = Start;
                        }
                        if (input == 'G')
                        {

                                state = G;
                        }
                        break;
                }
        }
   
};

#endif // STATE_MACHINE_H
