
//#include "stdafx.h"
#include <iostream>
#include "BstUtility.h"
#include <cstring>
#include <algorithm>    // std::sort
 
#include <vector>
using namespace std;
#include <atlstr.h> 
#include "CNode.h"


namespace krian_bst
{

    CNode::CNode(char *pName, char cColor): m_nSize(1), m_unNodeID(1)
    {
         strcpy_s( m_szName, pName );
         m_cColor = cColor;
    }

    CNode::CNode():
    m_cColor('b'), m_nSize(1),
        m_pLeftBranch(NULL), m_pRightBranch(NULL), m_unNodeID(1)
    {
        strcpy_s( m_szName, "");
    }


    CNode* CNode::GetNewNode()
    {
        CNode *pNode = new CNode();

        //todo memory allocation - exception handling 
        if( NULL != pNode )
        {

            cout<< "Enter Node name";
            cin >> pNode->m_szName;

            cout<< "Enter Node Color";
            cin >> pNode->m_cColor;
        }
        else
        {
            printf("Memory allocation failure");
        }

        return pNode;
    }


    CNode* CNode::GetRandomNewNode()
    {
        std::string szRandName;
        CNode *pNode = new CNode();

        if( NULL != pNode )
        {
            szRandName = randomString( 10 ); //max string is 10 characters now
            strcpy_s( pNode->m_szName, szRandName.c_str() );
            pNode->m_cColor = randomColor();
        }

        return pNode;
    }


    void CNode::SetSize( int size )
    {
        m_nSize = size;
    }


    int CNode::GetSize()
    {
        return m_nSize;
    }

    char CNode::GetColor()
    {
        return m_cColor;
    }

    char* CNode::GetName()
    {
        return m_szName;
    }

    void CNode::Display()
    {
        printf("\n Node Name - %s, Node Color - %c, Node Size - %d", m_szName, m_cColor, m_nSize);
    }

    bool CNode::operator < (CNode node)
    {
        int val;
        bool retVal = false;

        val = strcmp( m_szName, node.GetName() );

        if( val < 0 )
        {
            retVal = true;
        }

        return retVal;
    }

    bool CNode::operator > (CNode node)
    {
        int val;
        bool retVal = false;

        val = strcmp( m_szName, node.GetName() );

        if( val > 0 )
        {
            retVal = true;
        }

        return retVal;
    }

    void CNode::operator = (CNode node)
    {

        m_cColor = node.GetColor();
        strcpy_s( m_szName, node.m_szName);
        //no change in size

        return;
    }

    bool CNode::SetNodeID( unsigned int unNodeID )
    {
        m_unNodeID = unNodeID;
        m_AdjacentColorsNodeIDs.push_back( m_unNodeID );
        m_AdjacentColorsNodeNames.push_back( m_szName );

        return true;
    }

    unsigned int CNode::GetNodeID( )
    {
        return m_unNodeID;
    }

    void CNode::UpdateAdjacentColorNodes( )
    {
        CNode *ptr;
        m_AdjacentColorsNodeIDs.clear();
        m_AdjacentColorsNodeIDs.push_back( m_unNodeID );
        m_AdjacentColorsNodeNames.clear();
        m_AdjacentColorsNodeNames.push_back( m_szName );
        if( m_pLeftBranch )
        {
            if( m_cColor == m_pLeftBranch->GetColor() )
            {
                m_AdjacentColorsNodeIDs.insert( m_AdjacentColorsNodeIDs.end(), m_pLeftBranch->m_AdjacentColorsNodeIDs.begin(), m_pLeftBranch->m_AdjacentColorsNodeIDs.end() );
                std::sort( m_AdjacentColorsNodeIDs.begin(), m_AdjacentColorsNodeIDs.end() );
                m_AdjacentColorsNodeNames.insert( m_AdjacentColorsNodeNames.end(), m_pLeftBranch->m_AdjacentColorsNodeNames.begin(), m_pLeftBranch->m_AdjacentColorsNodeNames.end() );
            }
        }

        if( m_pRightBranch )
        {
            if( m_cColor == m_pRightBranch->GetColor() )
            {
                m_AdjacentColorsNodeIDs.insert( m_AdjacentColorsNodeIDs.end(), m_pRightBranch->m_AdjacentColorsNodeIDs.begin(), m_pRightBranch->m_AdjacentColorsNodeIDs.end() );
                std::sort( m_AdjacentColorsNodeIDs.begin(), m_AdjacentColorsNodeIDs.end() );
                m_AdjacentColorsNodeNames.insert( m_AdjacentColorsNodeNames.end(), m_pRightBranch->m_AdjacentColorsNodeNames.begin(), m_pRightBranch->m_AdjacentColorsNodeNames.end() );
            }
        }
    }

}
