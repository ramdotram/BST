
#include "stdafx.h"
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
                /*Root node empty case*/
                pNode = pNewNode;
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
                }
            }
            else if(*pNewNode > *pNode)
            {
                pNode->m_pRightBranch = InsertNode(pNode->m_pRightBranch, pNewNode);
                if( NULL != pNode->m_pRightBranch )
                {
                    /*Set size whenever nee node added to branch*/
                    pNode->SetSize( pNode->m_pRightBranch->GetSize() + 1);
                }
            }
            else
            {
                /*If node name already exist then update the existing node*/
                *pNode = *pNewNode;
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

        TraverseInOrder( pNode->m_pLeftBranch );
        TraverseInOrder( pNode->m_pRightBranch );
        m_pCurrentNode = pNode;

        CheckSearchCriteria();
    }


    void CBinarySearchTree::CheckSearchCriteria()
    {
        if( 0 != m_CurrentSearchColor )
        {
            CheckColorSpots();
        }

        if( 0 != m_cNameSearchPrefix )
        {
            CheckNamePrefix();
        }

        if( 0 != m_nSearchSize )
        {

        }

        if( true == m_bDisplayTree )
        {
            //m_pCurrentNode->Display();
            CUserInterface::m_pDisplay->DisplayNode(m_pCurrentNode); 
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

        cout << "\n Display Color Spot start " << m_CurrentSearchColor;
        for( unsigned int i = 0; i < m_ColorSpotList.size(); i++)
        {
            myString = m_ColorSpotList[i];
            cout << "Node"<< (char*) myString.GetString()<<endl;
        }

        cout<<"\nDisplay Color Spot end";
    }

    void CBinarySearchTree::DisplayNames()
    {
        CString myString;

        for( unsigned int i = 0; i < m_NameSearchList.size(); i++)
        {
            myString = m_NameSearchList[i];
            cout << "Node"<< (char*) myString.GetString()<<endl;
        }

        cout<< "Display name starting with character ends"<<endl;
    }


    void CBinarySearchTree::CheckColorSpots()
    {
        if( m_CurrentSearchColor != m_pCurrentNode->GetColor() )
        {
            if( m_ColorSpotList.size() >= 3 )
            {
                DisplayColorSpot();
            }
            m_CurrentSearchColor = m_pCurrentNode->GetColor();
            m_ColorSpotList.clear();
        }

        m_ColorSpotList.push_back( CString(m_pCurrentNode->GetName()) );
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


    void CBinarySearchTree::SearchNamePrefix( char cNamePrefix )
    {
        ResetSearches();
        m_NameSearchList.clear();
        m_cNameSearchPrefix = cNamePrefix;
        TraverseInOrder(m_pRootNode );

        cout << endl << "Display name starting with character " << m_cNameSearchPrefix<<endl;
        DisplayNames();
    }

    void CBinarySearchTree::SearchSize( int nSize )
    {
        ResetSearches();
        m_NameSearchList.clear();

        m_nSearchSize = nSize;        

        TraverseInOrder(m_pRootNode );

        cout << endl << "Display name pNode size greater than " << nSize<<endl;
        DisplayNames();
    }

    void CBinarySearchTree::SearchColorSpots( char cColor )
    {
        ResetSearches();
        m_ColorSpotList.clear();
        m_CurrentSearchColor = cColor;
        TraversePreOrder(m_pRootNode );
        DisplayColorSpot();
    }

    void CBinarySearchTree::ResetSearches()
    {
        m_cNameSearchPrefix = 0;
        m_CurrentSearchColor = 0;
        m_nSearchSize = 0;
        m_bDisplayTree = false;
    }

}