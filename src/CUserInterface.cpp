
#include "stdafx.h"
#include "CNode.h"
#include "CBinarySearchTree.h"
#include "CDisplay.h"
#include "CDisplayConsole.h"
#include "CDisplayGraphics.h"
#include "CGenerateDotFile.h"

#include "CUserInterface.h"

#include <iostream>
using namespace std;

namespace krian_bst
{

    CDisplay* CUserInterface::m_pDisplay = NULL;

    CUserInterface::CUserInterface():m_nUserOption(0)
    {
        m_pDisplay = new CDisplayConsole();
    }


    void CUserInterface::DisplayNode( CNode *pNode )
    {
        if( NULL != m_pDisplay )
            m_pDisplay->DisplayNode( pNode );
    }

    void CUserInterface::DisplayOptions()
    {
        cout<< endl << "1 - Insert Node"<< endl;
        cout<< "2 - Generate Random Tree"<< endl;
        cout<< "3 - Display Tree - Inorder"<< endl;
        cout<< "4 - Display Tree - Preorder"<< endl;
        cout<< "5 - Display Tree - Postorder"<< endl;
        cout<< "6 - Search Node starting with character" << endl;
        cout<< "7 - Search Node with Size" << endl;
        cout<< "8 - Search node for Color Spot" << endl;
        cout<< "9 - Generate DOT File" <<endl;
        cout<< "10 - Quit" << endl;
    }


    bool CUserInterface::GetUserInput()
    {
        bool bExitProgram = false;

        DisplayOptions();

        cin >> m_nUserOption;

        switch( m_nUserOption )
        {

        case 1:
            m_bst.InsertNewNode( CNode::GetNewNode() );
            break;

        case 2:
            int nNodes;
            cout << "Enter number of nodes for Random tree";
            cin >> nNodes;
            m_bst.GenerateRandomTree ( nNodes );
            break;

        case 3:
            m_pDisplay->SetMarker( "IN ORDER traversal Begins" );
            m_bst.DisplayTree( 0 );
            m_pDisplay->SetMarker( "IN ORDER traversal Ends" );
            break;

        case 4:
            m_pDisplay->SetMarker( "PRE ORDER traversal Begins" );
            m_bst.DisplayTree( 1 );
            m_pDisplay->SetMarker( "PRE ORDER traversal Ends" );
            break;

        case 5:
            m_bst.DisplayTree( 2 );
            break;

        case 6:
            {
                char cSearchLetter;
                cout<<"Enter starting letter for the search ";
                cin>>cSearchLetter;
                m_bst.SearchNamePrefix(cSearchLetter);
                break;
            }

        case 7:
            {
                int nSearchSize;
                cout<<"Enter the Upper limit size to search tree";
                cin>>nSearchSize;
                m_bst.SearchSize(nSearchSize);
                break;
            }

        case 8:
            {
                char cColor;
                cout << "Enter the Color Spot to Search r - red  g - green b - blue";
                cin >> cColor;
                m_bst.SearchColorSpots(cColor);
                break;
            }

        case 9:
            {
                GenerateDOT_File();
                break;
            }
        case 10:
            bExitProgram = true;
            break;

        default:
            cout<< "Invalid Option try again" <<endl;
        }

        return bExitProgram;
    }


    void CUserInterface::GenerateDOT_File()
    {
        delete m_pDisplay;
        m_pDisplay->m_DisplayMode = 2;

        m_pDisplay = new CGenerateDotFile;
        //do inorder traversal
        m_bst.DisplayTree( 1 );

        delete m_pDisplay;
        m_pDisplay = new CDisplayConsole();

    }


    void CUserInterface::Process()
    {
        bool bExitProgram;

        do
        {
            bExitProgram = GetUserInput();

            if( true == bExitProgram )
            {
                delete m_pDisplay;
                break;
            }

        }while(true);
    }

}
