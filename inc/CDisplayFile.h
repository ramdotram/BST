

#ifndef _CDISPLAY_FILE_H_
#define _CDISPLAY_FILE_H_

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "string.h"
#include "CDisplay.h"
#include "CNode.h"

using namespace std;

namespace krian_bst
{
    class CDisplayFile: public CDisplay
    {
        ofstream m_file;
    public:
        CDisplayFile();
        virtual void DisplayNode( CNode *pNode);
        virtual void SetMarker( char *pText );
    };
}

#endif //_CDISPLAY_FILE_H_
