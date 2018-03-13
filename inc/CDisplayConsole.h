

#ifndef _CDISPLAY_CONSOLE_H_
#define _CDISPLAY_CONSOLE_H_

#include "string.h"
#include "stdafx.h"
#include <iostream>
#include "CDisplay.h"
#include "CNode.h"

namespace krian_bst
{
    class CDisplayConsole: public CDisplay
    {
    public:
        virtual void DisplayNode( CNode *pNode)
        {
            cout << endl << "Node Name" << pNode->GetName();
            cout << endl << "Node Color" << pNode->GetColor();
            cout << endl << "Node Size" << pNode->GetSize();
        }

        virtual void SetMarker( char *pText )
        {
            cout<< "****" << pText << "****" << endl;
        }
    };
}

#endif //_CDISPLAY_CONSOLE_H_
