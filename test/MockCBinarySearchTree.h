

#ifndef _MOCK_CBINARY_SEARCH_TREE_H_

#define _MOCK_CBINARY_SEARCH_TREE_H_

//#include "stdafx.h"

#include "gmock/gmock.h"
#include "MockCNode.h"
#include "CBinarySearchTree.h"

namespace krian_bst
{

    class MockCBinarySearchTree: public CBinarySearchTree
    {
    public:
        //MOCK_METHOD0( MockCBinarySearchTree(), void());
        //~MockCBinarySearchTree()
        MOCK_METHOD1(  GenerateRandomTree, void(int nNodes) );
        MOCK_METHOD1(  InsertNewNode,  bool(MockCNode* pNewNode));
        MOCK_METHOD1( DisplayTree, void(int nTypeTraversal));
        MOCK_METHOD1( SearchNamePrefix,  void(char cNamePrefix) );
        MOCK_METHOD1( SearchSize, void( int nSize) );
        MOCK_METHOD1( SearchColorSpots, void( char cColor) );
    };

}

#endif //_MOCK_CBINARY_SEARCH_TREE_H_