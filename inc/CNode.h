
#ifndef _CNODE_H_
#define _CNODE_H_

#include "stdafx.h"
#include "string.h"

namespace krian_bst
{

#define MAX_STR_SIZE 255

    class CNode
    {
    private:
        char m_szName[MAX_STR_SIZE];
        char m_cColor;
        int  m_nSize;

        CNode();

    public:
        CNode* m_pLeftBranch;
        CNode* m_pRightBranch;

        static CNode* GetNewNode();
        static CNode* GetRandomNewNode();

        int GetSize();
        void SetSize( int size );

        char* GetName();
        char GetColor();
        void Display();

        bool operator < (CNode);
        bool operator > (CNode);
        void operator = (CNode);
    };

}
#endif //_CNODE_H_