#ifndef TOOLS_H
#define TOOLS_H


namespace Tools
{
    template<class D,class B>
    class IsDerivedFrom
    {
        private:
            class YES{char a[1];};
            class NO{char a[2];};

            static YES Test(B*);
            static NO Test(...);

            public:
            enum {IsDerived = sizeof(Test(static_cast<D*>(0))) == sizeof(YES)};
    };

    template<class T,class B>
    class HeritageChecker
    {
        private:
            typedef char _assertType[IsDerivedFrom<T,B>::IsDerived?1:-1];
    };
}

#endif // TOOLS_H
