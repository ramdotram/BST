

#ifndef _CDISPLAY_H_
#define _CDISPLAY_H_

#include "string.h"
#include "stdafx.h"

namespace krian_bst
{
    class CDisplay
    {
    public:
        int m_DisplayMode;
        CDisplay():m_DisplayMode(1) 
        {
        }
        virtual void DisplayNode( CNode *pNode) = 0;
        virtual void SetMarker( char *pText ) = 0;
    };

}
#endif //_CDISPLAY_H_
