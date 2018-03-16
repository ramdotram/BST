
//#include "stdafx.h"
#include <iostream>
#include "CNode.h"
#include "CGenerateDotFile.h"

namespace krian_bst
{

    CGenerateDotFile::CGenerateDotFile()
    {
        char szFileName[MAX_STR_SIZE] = { 0 };
        cout << "Enter DOT file name";
        cin>>szFileName;

        /*Open file in write mode*/
        m_file.open( szFileName );

        /*Error/Exception handling if file ope failure*/
        m_file << "digraph G {\n";
    }

    void CGenerateDotFile::SetMarker( char *pText )
    {
        //m_file<< "****" << pText << "****" << endl;
    }

    void CGenerateDotFile::DisplayColor( CNode *pNode)
    {
        char cColor = pNode->GetColor();
        char *pColor;

        if( NULL != pNode )
        {
            switch( cColor )
            {
            case 'r':
                pColor = "red";
                break;
            case 'b':
                pColor = "blue";
                break;
            case 'g':
                pColor = "green";
                break;
            }
            m_file<< endl << pNode->GetName() << "[color =" << pColor <<"];" ;
        }
        
    }

    void CGenerateDotFile::DisplayNode( CNode *pNode)
    {
        if( NULL != pNode )
        {
            DisplayColor(pNode);
            if( NULL != pNode->m_pLeftBranch )
            {
                m_file<< endl << pNode->GetName() << "->" << pNode->m_pLeftBranch->GetName() <<";";
            }

            if( NULL != pNode->m_pRightBranch )
            {
                m_file<< endl << pNode->GetName() <<  "->" << pNode->m_pRightBranch->GetName()<<";";
            }
        }
    }

    CGenerateDotFile::~CGenerateDotFile()
    {
        m_file << " \n}";
        m_file.flush();
        m_file.close();
    }

}
