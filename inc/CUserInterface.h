

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
        void ProcessDisplayOption( int nDisplayOption);
    public:
        CUserInterface();
        static CDisplay *m_pDisplay;
        void Process();
        static void DisplayNode( CNode *pnode );

    };

}
#endif //_CUSER_INTERFACE_H_
