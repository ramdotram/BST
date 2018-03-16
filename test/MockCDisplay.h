

#ifndef _MOCK_CDISPLAY_H_
#define _MOCK_CDISPLAY_H_

#include "string.h"
//#include "stdafx.h"
#include "CDisplay.h"

namespace krian_bst
{
    class MockCDisplay: public CDisplay
    {
    public:
        MOCK_METHOD1( DisplayText, void( char *pText));
        MOCK_METHOD1( DisplayNode, void( CNode *pNode));
        MOCK_METHOD1(SetMarker, void( char *pText ));
        virtual ~MockCDisplay(){
        }
    };

}
#endif //_CDISPLAY_H_
