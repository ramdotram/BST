

#ifndef _CBINARY_SEARCH_TREE_H_

#define _CBINARY_SEARCH_TREE_H_

#include "stdafx.h"
#include "string.h"
#include "CNode.h"
#include <cstring>
 
#include <vector>
using namespace std;
#include <atlstr.h> 
#include "CNode.h"
#include "CBinarySearchTree.h"

namespace krian_bst
{

    class CBinarySearchTree
    {
        CNode *m_pRootNode;
        CNode *m_pCurrentNode;
        char  m_cNameSearchPrefix;
        int   m_nSearchSize;
        char  m_CurrentSearchColor;
        bool  m_bDisplayTree;

        std::vector<CString> m_ColorSpotList;
        std::vector<CString> m_NameSearchList;

        CNode* DeleteTree(CNode* pNode);
        CNode* InsertNode(CNode* pNode, CNode* pNewNode);

        void TraverseInOrder(CNode* pNode);
        void TraversePreOrder(CNode* pNode);
        void TraversePostOrder(CNode* pNode);

        void CheckSearchCriteria();
        void CheckColorSpots();
        void CheckNamePrefix();
        void CheckSize();

        void DisplayColorSpot();
        void DisplayNames();
        void ResetSearches();

    public:
        CBinarySearchTree():m_pRootNode(NULL), m_CurrentSearchColor(0), 
            m_cNameSearchPrefix(0), m_nSearchSize(0), m_bDisplayTree(false)
        {

        }

        ~CBinarySearchTree()
        {
            DeleteTree( m_pRootNode );
        }

        void CreateRandoneTree()
        {
        }

        bool InsertNewNode( CNode* pNewNode);
        void DisplayTree(int nTypeTraversal);
        void SearchNamePrefix( char cNamePrefix );
        void SearchSize( int nSize );
        void SearchColorSpots( char cColor );
    };

}

#endif //_CBINARY_SEARCH_TREE_H_