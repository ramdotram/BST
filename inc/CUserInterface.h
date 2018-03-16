

#ifndef _CUSER_INTERFACE_H_
#define _CUSER_INTERFACE_H_

#include "string.h"
#include "CDisplay.h"

namespace krian_bst
{
    class CUserInterface
    {
        CBinarySearchTree m_bst;
        int m_nUserOption;

        void DisplayOptions();
        bool GetUserInput();
    public:
        CUserInterface();
        static CDisplay *m_pDisplay;
        void Process();
        static void DisplayNode( CNode *pNode );
        static void DisplayText( char*pName );
        void GenerateDOT_File( CBinarySearchTree *pTree);
    };

}
#endif //_CUSER_INTERFACE_H_
