#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

class placeInterface:  public sc_interface
{
public:
    virtual void addTokens(unsigned int n) = 0;
    virtual void removeTokens(unsigned int n) = 0;
    virtual unsigned int testTokens() = 0;
};

class placechannel : public placeInterface
{

   private:
    unsigned int tokens;

public:
placechannel(unsigned int Tokens):tokens(Tokens){}

    void addTokens(unsigned int n)
    {
        tokens = tokens + n;
    }

    void removeTokens(unsigned int n)
    {
        tokens = tokens - n;
    }

    unsigned int testTokens()
    {

        return tokens;
    }
};

#endif // PLACE_H
