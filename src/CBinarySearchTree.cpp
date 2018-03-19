
//#include "stdafx.h"
#include "string.h"
#include "CBinarySearchTree.h"
#include <iostream>
#include "CUserInterface.h"

namespace krian_bst
{


    CNode* CBinarySearchTree::InsertNode( CNode* pNode,  CNode* pNewNode)
    {
        if( NULL != pNewNode )
        {
            if(pNode == NULL)
            {
                m_unTotalNodes++;
                pNode = pNewNode;
                pNode->SetNodeID( m_unTotalNodes );
                pNode->m_pLeftBranch = pNode->m_pRightBranch = NULL;
            }
            /* operator overloading - see implementation in CNode class*/
            else if(*pNewNode < *pNode)
            {
                pNode->m_pLeftBranch = InsertNode(pNode->m_pLeftBranch, pNewNode );
                if( NULL != pNode->m_pLeftBranch )
                {
                    /*Set size whenever nee node added to branch*/
                    pNode->SetSize( pNode->m_pLeftBranch->GetSize() + 1);
                    pNode->UpdateAdjacentColorNodes();
                }
            }
            else if(*pNewNode > *pNode)
            {
                pNode->m_pRightBranch = InsertNode(pNode->m_pRightBranch, pNewNode);
                if( NULL != pNode->m_pRightBranch )
                {
                    /*Set size whenever nee node added to branch*/
                    pNode->SetSize( pNode->m_pRightBranch->GetSize() + 1);
                    pNode->UpdateAdjacentColorNodes();
                }
            }
            else
            {
                /*If node name already exist then update the existing node*/
                *pNode = *pNewNode;
                pNode->UpdateAdjacentColorNodes();
            }
        }

        return pNode;
    }


    CNode* CBinarySearchTree::DeleteTree(CNode* pNode)
    {
        if(pNode == NULL)
            return NULL;

        DeleteTree(pNode->m_pLeftBranch);
        DeleteTree(pNode->m_pRightBranch);
        m_unTotalNodes--;
        delete pNode;

        return NULL;
    }


    void CBinarySearchTree::TraverseInOrder(CNode* pNode)
    {
        if( NULL == pNode )
        {
            return;
        }

        TraverseInOrder( pNode->m_pLeftBranch );
        m_pCurrentNode = pNode;
        CheckSearchCriteria(); //this function takes care of business logics
        TraverseInOrder( pNode->m_pRightBranch );
    }



    void CBinarySearchTree::TraversePreOrder(CNode* pNode)
    {

        if( NULL == pNode )
        {
            return;
        }    

        m_pCurrentNode = pNode;

        CheckSearchCriteria();
        TraverseInOrder( pNode->m_pLeftBranch );
        TraverseInOrder( pNode->m_pRightBranch );
    }


    void CBinarySearchTree::TraversePostOrder(CNode* pNode)
    {

        if( NULL == pNode )
        {
            return;
        }    

        TraverseInOrder( pNode->m_pRightBranch );
        TraverseInOrder( pNode->m_pLeftBranch );

        m_pCurrentNode = pNode;

        CheckSearchCriteria();
    }


    void CBinarySearchTree::CheckSearchCriteria()
    {
        if( 0 != m_SearchColor )
        {
	          CheckAllColorSpot();


        }
        else if( 0 != m_cNameSearchPrefix )
        {
            CheckNamePrefix();
        }
        else if( 0 != m_nSearchSize )
        {
            if( m_pCurrentNode->GetSize() > m_nSearchSize )
            {
                m_NameSearchList.push_back( CString( m_pCurrentNode->GetName() ) );
            }
        }

        if( true == m_bDisplayTree )
        {
            //m_pCurrentNode->Display();
            CUserInterface::m_pDisplay->DisplayNode(m_pCurrentNode);
            CUserInterface::m_pDisplay->DisplayText(m_pCurrentNode->GetName()); 
        }
    }

    void CBinarySearchTree::CheckNamePrefix()
    {
        char *pszName;

        pszName = m_pCurrentNode->GetName();

        if( (pszName[0] == m_cNameSearchPrefix) )//&& (m_pCurrentNode->GetSize() > m_nSearchSize))
        {
            m_NameSearchList.push_back( CString( pszName ) );
        }
    }

    void CBinarySearchTree::CheckSize()
    {
        char *pszName;

        if( m_pCurrentNode->GetSize() > m_nSearchSize )
        {
            pszName = m_pCurrentNode->GetName();
            m_NameSearchList.push_back( CString( pszName ) );
        }
    }


    void CBinarySearchTree::DisplayColorSpot()
    {
        CString myString;
   
        //cout << "\n Display Color Spot start " << m_CurrentSearchColor;
        for( unsigned int i = 0; i < m_ColorSpotController.GetColorSpotCount(m_SearchColor); i++)
        {
            m_ColorSpotController.GetColorSpotIndex( m_SearchColor, i, myString);
            CUserInterface::m_pDisplay->DisplayText( (char*) myString.GetString() );
        }

        cout<<"\nDisplay Color Spot end";
    }

    void CBinarySearchTree::DisplayNames()
    {
        CString myString;

        for( unsigned int i = 0; i < m_NameSearchList.size(); i++)
        {
            myString = m_NameSearchList[i];
            //cout << "Node:"<< (char*) myString.GetString()<<endl;
            CUserInterface::m_pDisplay->DisplayText( (char*) myString.GetString() );
        }

        cout<< "Display name starting with character ends"<<endl;
    }


    void CBinarySearchTree::CheckAllColorSpot()
    {
        m_ColorSpotController.CheckColorSpot( m_pCurrentNode );
    }

    bool CBinarySearchTree::InsertNewNode( CNode *pNewNode)
    {
        bool status = false;

        if( NULL != pNewNode )
        {
            m_pRootNode = InsertNode( m_pRootNode, pNewNode );
            status = true;
        }

        return status;
    }

    void CBinarySearchTree::DisplayTree( int nTypeTraversal)
    {
        ResetSearches();

        m_bDisplayTree = true;

        switch( nTypeTraversal )
        {
        case 0:
            TraverseInOrder(m_pRootNode );
            break;

        case 1:
            TraversePreOrder(m_pRootNode);
            break;

        case 2:
            TraversePostOrder(m_pRootNode);
            break;

        default:
            m_bDisplayTree = false;
            break;
        }

    }


    int CBinarySearchTree::SearchNamePrefix( char cNamePrefix )
    {
        ResetSearches();
        m_NameSearchList.clear();
        m_cNameSearchPrefix = cNamePrefix;
        TraverseInOrder(m_pRootNode );

        cout << endl << "Display name starting with character " << m_cNameSearchPrefix<<endl;
        DisplayNames();

        return m_NameSearchList.size();
    }

    int CBinarySearchTree::SearchSize( int nSize )
    {
        ResetSearches();
        m_NameSearchList.clear();

        m_nSearchSize = nSize;        

        TraverseInOrder(m_pRootNode );

        cout << endl << "Display name pNode size greater than " << nSize<<endl;
        DisplayNames();

        return m_NameSearchList.size();
    }

    int CBinarySearchTree::SearchColorSpots( char cColor )
    {
        ResetSearches();
        m_nColorSpotCount = 0;
        m_SearchColor = cColor;
        //TraverseInOrder(m_pRootNode );
        //m_ColorSpotController.ClearBuffers();
        TraversePreOrder(m_pRootNode );
        //m_ColorSpotController.ClearBuffers();

        m_nColorSpotCount = m_ColorSpotController.GetColorSpotCount();

        if( 'a' != cColor )
        {
            m_nColorSpotCount = m_ColorSpotController.GetColorSpotCount(cColor);
            DisplayColorSpot();
        }

        return m_nColorSpotCount;
    }


    void CBinarySearchTree::ResetSearches()
    {
        m_cNameSearchPrefix = 0;
        m_SearchColor = 0;
        m_nSearchSize = 0;
        m_bDisplayTree = false;
        m_nColorSpotCount = 0;
    }


    int CBinarySearchTree::GenerateRandomTree( int nNodes )
    {
        CNode *pRandomNode;

        for( int i = 0; m_unTotalNodes < nNodes; i++ )
        {
            pRandomNode = CNode::GetRandomNewNode();
            if( NULL != pRandomNode )
                m_pRootNode = this->InsertNode( m_pRootNode, pRandomNode );

        }

        return m_pRootNode->GetSize();
    }

    bool CBinarySearchTree::DeleteTree()
    {
        bool bRetVal = false;

        if( NULL != m_pRootNode )
        {
            DeleteTree( m_pRootNode );
        }

        return bRetVal;
    }

    int CBinarySearchTree::GetTotalNodes()
    {
        return m_unTotalNodes;
    }
}