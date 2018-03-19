
#ifndef _CCOLORSPOTCONTROLLER_H_
#define _CCOLORSPOTCONTROLLER_H_

//#include "stdafx.h"
#include "string.h"
#include <map>
#include <iterator>

using namespace std;

namespace krian_bst
{

#define MAX_STR_SIZE 255

    class CColorSpotController
    {
    private:
        CNode *m_pCureentNode;
        char m_CurrentSearchColor;
        map <CString, CString> m_BlueSpotList;
        map <CString, CString> m_RedSpotList;
        map <CString, CString> m_GreenSpotList;
        std::vector<CString> m_ColorSpotNameList;
        std::vector<unsigned int> m_ColorSpotIDList;
        bool AddColorSpot( char cColor, CString key, CString value);
        bool CreateSpot();
        bool ParseColorSpot( CString Value);
        bool IsDuplicateSpot(CString key, map <CString, CString> currentSpotList);
    public:
        bool CheckColorSpot(CNode* pNode);
        bool ClearBuffers();
        int GetColorSpotCount(char cColor);
        int GetColorSpotCount();
        bool GetColorSpotIndex( char cColor, int nIndex,  std::vector<CString> colorSpotNameList);
        bool GetColorSpotIndex( char cColor, int nIndex,  CString &colorSpots);
        //bool GetColorSpotIndex( int nIndex,  CString colorSpots);
        CColorSpotController();
    };

}
#endif //_CCOLORSPOTCONTROLLER_H_