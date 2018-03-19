
#ifndef _CNODE_H_
#define _CNODE_H_

//#include "stdafx.h"
#include "string.h"
#include <cstring>
 
#include <vector>
using namespace std;
#include <atlstr.h> 

namespace krian_bst
{

#define MAX_STR_SIZE 255

    class CNode
    {
    private:
        char m_szName[MAX_STR_SIZE];
        char m_cColor;
        int  m_nSize;
        int  m_unNodeID;
        CNode();

    public:
        std::vector<unsigned int> m_AdjacentColorsNodeIDs;
        std::vector<CString> m_AdjacentColorsNodeNames;

        CNode(char*, char);
        CNode* m_pLeftBranch;
        CNode* m_pRightBranch;
        ~CNode()
        {
        }

        static CNode* GetNewNode();
        static CNode* GetRandomNewNode();

        bool SetNodeID( unsigned int );
        unsigned int GetNodeID();

        int GetSize();
        void SetSize( int size );
        void UpdateAdjacentColorNodes();
        char* GetName();
        char GetColor();
        void Display();

        bool operator < (CNode);
        bool operator > (CNode);
        void operator = (CNode);

    };

}
#endif //_CNODE_H_