
#include "stdafx.h"
#include "CNode.h"
#include "CDisplayFile.h"

namespace krian_bst
{

    CDisplayFile::CDisplayFile()
    {
        //file open
        m_file.open( "d:\\BST.txt" );
    }

    void CDisplayFile::SetMarker( char *pText )
    {
        m_file<< "****" << pText << "****" << endl;
    }


    void CDisplayFile::DisplayNode( CNode *pNode)
    {
        m_file<< "Node name" << pNode->GetName() << endl;
        m_file<< "\t Node Color" << pNode->GetColor() << endl;
        m_file<< "\t Node Size" << pNode->GetSize() << endl;
    }

}
