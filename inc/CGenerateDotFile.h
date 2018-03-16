

#ifndef _CGENERATE_DOT_FILE_H_
#define _CGENERATE_DOT_FILE_H_

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "string.h"
#include "CDisplay.h"
#include "CNode.h"

using namespace std;


namespace krian_bst
{
    class CGenerateDotFile: public CDisplay
    {
        ofstream m_file;
        void DisplayColor( CNode *pNode);
    public:
        CGenerateDotFile();
        virtual void DisplayText( char *pText )
        {
            //do nothing
        }
        virtual void DisplayNode( CNode *pNode);
        virtual void SetMarker( char *pText );
        virtual ~CGenerateDotFile();
    };
}

#endif //_CGENERATE_DOT_FILE_H_
