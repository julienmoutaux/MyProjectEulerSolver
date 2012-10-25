#include "Exercise33.h"

void Exercise33::Solve()
{
    int resNumFinal = 1;
    int resDenomFinal = 1;
    for(int i1 =1; i1<10; i1++)
        for(int i2=1; i2<10; i2++)
            for(int j1=1; j1<10; j1++)
                for(int j2=1; j2<10; j2++)
                {
                    if(i1 == j1 || i1 == j2 || i2 == j1 || i2 == j2)
                    {
                        int val1 = i1 *10 + i2;
                        int val2 = j1 *10 + j2;
                        if (val2 > val1)
                        {
                            int valR1;
                            int valR2;
                            if(i1 == j1)
                            {
                                valR1 = i2;
                                valR2 = j2;
                            } else if (i1 == j2 )
                            {
                                valR1 = i2;
                                valR2 = j1;
                            } else if (i2 == j1 )
                            {
                                valR1 = i1;
                                valR2 = j2;
                            } else if (i2 == j2 )
                            {
                                valR1 = i1;
                                valR2 = j1;
                            }
                            int val1Red;
                            int val2Red;
                            int valR1Red;
                            int valR2Red;
                            Simplify(val1,val2,&val1Red,&val2Red);
                            Simplify(valR1,valR2,&valR1Red,&valR2Red);
                            if(val1Red == valR1Red && val2Red == valR2Red)
                            {
                                resNumFinal *= val1;
                                resDenomFinal *= val2;
                                cout<<val1<<"/"<<val2<<" can be simplified by "<<valR1<<"/"<<valR2<<endl;
                            }
                        }
                    }
                }
    int denomSimpl,numSimpl;
    Simplify(resNumFinal,resDenomFinal,&numSimpl,&denomSimpl);
    cout<<"The simplified product is "<<numSimpl<<"/"<<denomSimpl<<endl;
}

void Exercise33::Simplify(int nominator,int denominator,int * resNum,int * resDenom)
{
    (*resNum) = nominator;
    (*resDenom) = denominator;
    for(int i=denominator-1; i>1; i--)
    {
        if ((nominator %i == 0) && (denominator % i == 0))
        {
            (*resNum) = nominator/i;
            (*resDenom) = denominator/i;
            return;
        }
    }
}

void Exercise33::SetDefaultValues()
{

}

Exercise33::Exercise33()
{

}

Exercise33::~Exercise33()
{

}

