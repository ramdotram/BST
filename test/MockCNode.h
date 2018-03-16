
#ifndef _MOCK_CNODE_H_
#define _MOCK_CNODE_H_

//#include "stdafx.h"
#include "string.h"
#include "gmock/gmock.h"

namespace krian_bst
{

#define MAX_STR_SIZE 255

    class MockCNode : public CNode
    {

        MOCK_METHOD0(GetSize, int());
        MOCK_METHOD1(SetSize, void(int size));
        MOCK_METHOD0(GetName, char*());
        MOCK_METHOD0(GetColor, char());
        MOCK_METHOD0(Display, void());
#if 0 
        bool operator < (CNode);
        bool operator > (CNode);
        void operator = (CNode);
#endif
    };

}
#endif //_MOCK_CNODE_H_