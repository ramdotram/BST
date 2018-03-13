
#include "stdafx.h"
#include "CNode.h"
#include <iostream>
using namespace std;

namespace krian_bst
{

CNode::CNode():
m_cColor('b'), m_nSize(1),
    m_pLeftBranch(NULL), m_pRightBranch(NULL)
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
    /*Function implementation shall be done in future*/
#if 0
    CNode *pNode = new CNode();

    if( NULL == pNode )
    {
        printf("Memory allocation failure");
    }
#endif
    return NULL;
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

}
