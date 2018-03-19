// UnitTestBST.cpp : Defines the entry point for the console application.
//


#include "./../inc/CNode.h"
#include "./../inc/CBinarySearchTree.h"
#include "./../inc/CUserInterface.h"
#include "gtest/gtest.h"

#include "MockCNode.h"
#include "MockCBinarySearchTree.h"
#include "MockCDisplay.h"

using namespace krian_bst;

using ::testing::Mock;

//__declspec(dllexport) int PullInMyLibrary() { return 0; }
#if 1


TEST(testInsertNode_BasicFunction, UT_BST)
{
    CBinarySearchTree bst;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";

    pNode = new CNode( "node0", 'b' );
    EXPECT_EQ( true,  bst.InsertNewNode( pNode ));
    EXPECT_EQ( 1, bst.GetTotalNodes() );

    //bst.DeleteTree();

    for( int i = 1; i <= 10; i++ )
    {
        sprintf_s( szName, "node%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }

    //cu.GenerateDOT_File(&bst);

    //cu.m_pDisplay = &myDisplay;

    EXPECT_EQ( 11, bst.GetTotalNodes() );
}
#endif

#if 1
TEST(testInsertNode_NegativeCase, UT_BST)
{
    CBinarySearchTree bst;

    EXPECT_EQ(false,  bst.InsertNewNode( NULL ));
    EXPECT_EQ( 0, bst.GetTotalNodes() );

}

TEST(testInsertNode_DuplicateCase, UT_BST)
{
    CBinarySearchTree bst;
    CNode *pNode = NULL;

    for( int i = 1; i <= 10; i++ )
    {
        pNode = new CNode( "node1", 'b' );
        bst.InsertNewNode( pNode );
    }
     
    EXPECT_EQ( 1, bst.GetTotalNodes() );

}


TEST(testSearchNamePrefix_Test1, UT_BST)
{
    CBinarySearchTree bst;
    CUserInterface cu;
    MockCDisplay myDisplay;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";

    pNode = new CNode( "ram", 'b' );
    EXPECT_EQ( true,  bst.InsertNewNode( pNode ));

    pNode = new CNode( "adam", 'b' );
    EXPECT_EQ( true,  bst.InsertNewNode( pNode ));

    pNode = new CNode( "banu", 'b' );
    EXPECT_EQ( true,  bst.InsertNewNode( pNode ));

    pNode = new CNode( "babu", 'b' );
    EXPECT_EQ( true,  bst.InsertNewNode( pNode ));

    pNode = new CNode( "arun", 'b' );
    EXPECT_EQ( true,  bst.InsertNewNode( pNode ));

    cu.m_pDisplay = &myDisplay;

    EXPECT_EQ( 2,  bst.SearchNamePrefix( 'a' ));

    EXPECT_EQ( 2,  bst.SearchNamePrefix( 'b' ));

    EXPECT_EQ( 0,  bst.SearchNamePrefix( 'x' ));

    EXPECT_CALL( myDisplay, DisplayText(testing::StrEq("adam") ) );
    EXPECT_CALL( myDisplay, DisplayText(testing::StrEq("arun") ) );
    bst.SearchNamePrefix( 'a' );

}


TEST(testSearchNamePrefix_Test2, UT_BST)
{
    CBinarySearchTree bst;
    CUserInterface cu;
    MockCDisplay myDisplay;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";


    for( int i = 1; i <= 20; i++ )
    {
        sprintf_s( szName, "node%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }

    for( int i = 1; i <= 20; i++ )
    {
        sprintf_s( szName, "test%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }

    cu.m_pDisplay = &myDisplay;

    EXPECT_EQ( 20,  bst.SearchNamePrefix( 'n' ));

    EXPECT_EQ( 20,  bst.SearchNamePrefix( 't' ));
}

TEST(testSearchSize_Basic, UT_BST)
{
    CBinarySearchTree bst;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";

    for( int i = 1; i < 10; i++ )
    {
        sprintf_s( szName, "node%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }

    //cu.GenerateDOT_File(&bst);

    EXPECT_EQ( 4, bst.SearchSize(5) );
}


TEST(testSearchColorSpot_Test1, UT_BST)
{

    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";


    for( int i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "node%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }
    cu.m_pDisplay = &myDisplay;

    EXPECT_EQ( 1, bst.SearchColorSpots('b') );
    //EXPECT_CALL( myDisplay, DisplayText(testing::StartsWith("node")) )
      //  .Times(3);
    bst.SearchColorSpots('a');
}

TEST(testSearchColorSpot_Test2, UT_BST)
{

    CBinarySearchTree bst;

    EXPECT_EQ( 0, bst.SearchColorSpots('b') );
    EXPECT_EQ( 0, bst.SearchColorSpots('r') );
    EXPECT_EQ( 0, bst.SearchColorSpots('g') );
    EXPECT_EQ( 0, bst.SearchColorSpots('o') );
}


TEST(testSearchColorSpot_Test3, UT_BST)
{

    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";
    int i;


    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "b%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "a%d", i);
        pNode = new CNode( szName, 'r' );
        bst.InsertNewNode( pNode );
    }

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "c%d", i);
        pNode = new CNode( szName, 'g' );
        bst.InsertNewNode( pNode );
    }
    
    //cu.GenerateDOT_File(&bst);

    cu.m_pDisplay = &myDisplay;

    bst.SearchColorSpots('a');
    EXPECT_EQ( 1, bst.SearchColorSpots('b') );
    EXPECT_EQ( 1, bst.SearchColorSpots('r') );
    EXPECT_EQ( 1, bst.SearchColorSpots('g') );
    //bst.DeleteTree();
}


TEST(testSearchColorSpot_Test5, UT_BST)
{

    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";

    for( int i = 1; i < 3; i++ )
    {
        sprintf_s( szName, "b%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }

    for( int i = 1; i < 3; i++ )
    {
        sprintf_s( szName, "a%d", i);
        pNode = new CNode( szName, 'r' );
        bst.InsertNewNode( pNode );
    }

    for( int i = 1; i < 3; i++ )
    {
        sprintf_s( szName, "c%d", i);
        pNode = new CNode( szName, 'g' );
        bst.InsertNewNode( pNode );
    }
    
    //cu.GenerateDOT_File(&bst);

    cu.m_pDisplay = &myDisplay;

    EXPECT_EQ( 0, bst.SearchColorSpots('b') );
    EXPECT_EQ( 0, bst.SearchColorSpots('r') );
    EXPECT_EQ( 0, bst.SearchColorSpots('g') );
}



TEST(testSearchColorSpot_Test6, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";
    int i;


    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "b%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "a%d", i);
        pNode = new CNode( szName, 'r' );
        bst.InsertNewNode( pNode );
    }

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "c%d", i);
        pNode = new CNode( szName, 'g' );
        bst.InsertNewNode( pNode );
    }
    
    //cu.GenerateDOT_File(&bst);

    cu.m_pDisplay = &myDisplay;

    EXPECT_EQ( 3, bst.SearchColorSpots('a') );
}


TEST(testTotalNode_Test1, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";
    int i;

    EXPECT_EQ( 0, bst.GetTotalNodes());

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "b%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }    

    EXPECT_EQ( 3, bst.GetTotalNodes());

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "b%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    } 

    EXPECT_EQ( 3, bst.GetTotalNodes());
}


TEST(testTotalNode_DuplicateCase, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";
    int i;


    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "b%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }    

    EXPECT_EQ( 3, bst.GetTotalNodes());

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "b%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    } 

    EXPECT_EQ( 3, bst.GetTotalNodes());
}

TEST(testTotalNode_Test3, UT_BST)
{

    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";
    int i;


    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "b%d", i);
        pNode = new CNode( szName, 'b' );
        bst.InsertNewNode( pNode );
    }

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "a%d", i);
        pNode = new CNode( szName, 'r' );
        bst.InsertNewNode( pNode );
    }

    for( i = 1; i < 4; i++ )
    {
        sprintf_s( szName, "c%d", i);
        pNode = new CNode( szName, 'g' );
        bst.InsertNewNode( pNode );
    }
    

    EXPECT_EQ( 9, bst.GetTotalNodes());
}


TEST(testDeleteTree_Empty, UT_BST)
{
    CBinarySearchTree bst;
    CNode *pNode = NULL;

    bst.DeleteTree();
}


TEST(GenerateRandomTree, UT_BST)
{
    CBinarySearchTree bst;
    CNode *pNode = NULL;
    CUserInterface cu;

    bst.GenerateRandomTree(10);
    //cu.GenerateDOT_File(&bst);

    EXPECT_EQ( 10, bst.GetTotalNodes() );
}

TEST(GenerateRandomTree_LargeSize, UT_BST)
{
    CBinarySearchTree bst;
    CNode *pNode = NULL;
    CUserInterface cu;

    bst.GenerateRandomTree(1000);
    //cu.GenerateDOT_File(&bst);

    EXPECT_EQ( 1000, bst.GetTotalNodes() );
}

#endif
using ::testing::InSequence;

TEST(DisplayTree_Inorder, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";
   

    pNode = new CNode( "b", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "a", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "c", 'b' );
    bst.InsertNewNode( pNode );

    cu.m_pDisplay = &myDisplay;

   
    {
        InSequence dummy;

        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("a")));
        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("b")));
        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("c")));

        bst.DisplayTree(0);

    }

}

TEST(DisplayTree_Preorder, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";
   

    pNode = new CNode( "b", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "a", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "c", 'b' );
    bst.InsertNewNode( pNode );

    cu.m_pDisplay = &myDisplay;

    //EXPECT_CALL(myDisplay, DisplayText(testing::StartsWith("b1"))).Times(3);
   
    {
        InSequence dummy;

        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("b")));
        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("a")));
        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("c")));
    }

    bst.DisplayTree(1);
}

TEST(DisplayTree_Postorder, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;
    char szName[MAX_STR_SIZE] = "node";
   

    pNode = new CNode( "b", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "a", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "c", 'b' );
    bst.InsertNewNode( pNode );

    //EXPECT_CALL(myDisplay, DisplayText(testing::StartsWith("b1"))).Times(3);
   
    //cu.GenerateDOT_File(&bst);
    cu.m_pDisplay = &myDisplay;

    {
        InSequence dummy;

        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("c")));
        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("a")));
        EXPECT_CALL(myDisplay, DisplayText(testing::StrEq("b")));
    }

    bst.DisplayTree(2);
}
#if 1

TEST(testSearchColorSpot_Basic2, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;

    pNode = new CNode( "ram", 'g' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "devi", 'g' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "bob", 'g' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "adri", 'g' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "eduard", 'b' );
    bst.InsertNewNode( pNode );

    cu.m_pDisplay = &myDisplay;

    EXPECT_EQ( 1, bst.SearchColorSpots('g') );

    //EXPECT_CALL( myDisplay, DisplayText("ram") )
      //  .Times(1);
     
    bst.SearchColorSpots('g');
}
#endif
TEST(testSearchColorSpot_Test7, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;

    pNode = new CNode( "ram", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "devi", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "arumugam", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "eduard", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "tiru", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "subra", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "uri", 'b' );
    bst.InsertNewNode( pNode );


    //cu.GenerateDOT_File(&bst);

    cu.m_pDisplay = &myDisplay;
 
    EXPECT_EQ( 2, bst.SearchColorSpots('a') );

    EXPECT_EQ( 1, bst.SearchColorSpots('r') );
    EXPECT_EQ( 1, bst.SearchColorSpots('b') );


    EXPECT_CALL( myDisplay, DisplayText(testing::HasSubstr("devi") ) );

    bst.SearchColorSpots('r');

    EXPECT_CALL( myDisplay, DisplayText(testing::HasSubstr("subra") ) );

    bst.SearchColorSpots('b');

    //EXPECT_CALL( myDisplay, DisplayText("ram") )
      //  .Times(1);
}


TEST(testSearchColorSpot_Test8, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;

    pNode = new CNode( "ram", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "devi", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "arumugam", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "eduard", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "tiru", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "subra", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "uri", 'b' );
    bst.InsertNewNode( pNode );


    //cu.GenerateDOT_File(&bst);

    cu.m_pDisplay = &myDisplay;
 
    EXPECT_EQ( 1, bst.SearchColorSpots('a') );

    EXPECT_CALL( myDisplay, DisplayText(testing::HasSubstr("tiru") ) );

    bst.SearchColorSpots('r');
}


TEST(testSearchColorSpot_Test9, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;

    pNode = new CNode( "ram", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "devi", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "arumugam", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "eduard", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "tiru", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "subra", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "uri", 'r' );
    bst.InsertNewNode( pNode );


    //cu.GenerateDOT_File(&bst);

    cu.m_pDisplay = &myDisplay;
 
    EXPECT_EQ( 1, bst.SearchColorSpots('a') );
    EXPECT_EQ( 0, bst.SearchColorSpots('b') );
    EXPECT_EQ( 0, bst.SearchColorSpots('g') );
    
    EXPECT_CALL( myDisplay, DisplayText(testing::HasSubstr("uri") ) );

    bst.SearchColorSpots('r');

    //EXPECT_CALL( myDisplay, DisplayText("ram") )
      //  .Times(1);
}

TEST(testSearchColorSpot_Test10, UT_BST)
{
    CBinarySearchTree bst;
    MockCDisplay myDisplay;
    CUserInterface cu;
    CNode *pNode = NULL;

    pNode = new CNode( "ram", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "devi", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "arumugam", 'r' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "eduard", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "tiru", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "subra", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "vetri", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "uri", 'b' );
    bst.InsertNewNode( pNode );

    pNode = new CNode( "www", 'b' );
    bst.InsertNewNode( pNode );
    //cu.GenerateDOT_File(&bst);

    cu.m_pDisplay = &myDisplay;
 
    EXPECT_EQ( 2, bst.SearchColorSpots('a') );

    EXPECT_EQ( 1, bst.SearchColorSpots('r') );
    EXPECT_EQ( 1, bst.SearchColorSpots('b') );

    {
        InSequence dummy;
        EXPECT_CALL( myDisplay, DisplayText(testing::HasSubstr("ram") ) );
        EXPECT_CALL( myDisplay, DisplayText(testing::HasSubstr("vetri") ) );
    }

    bst.SearchColorSpots('r');
    bst.SearchColorSpots('b');

}


#if 0
TEST(testDeleteTree, UT_BST)
{
    CBinarySearchTree bst;
    CNode *pNode = NULL;


    pNode = new CNode( "node1", 'b' );
    bst.InsertNewNode( pNode );

    bst.DeleteTree();

    EXPECT_EQ( 0, bst.GetTotalNodes() );
}



#endif

int _tmain(int argc, _TCHAR* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}