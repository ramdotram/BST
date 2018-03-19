
//#include "stdafx.h"
#include "CNode.h"
#include <algorithm>    // std::sort
#include <iostream>
#include "BstUtility.h"
#include <vector>

#include "string.h"
#include <cstring>
#include <atlstr.h> 
#include "CColorSpotController.h"


using namespace std;
//using namespace stl;

namespace krian_bst
{

    CColorSpotController::CColorSpotController():m_CurrentSearchColor(0)
    {

    }

    bool CColorSpotController::CheckColorSpot(CNode* pNode)
    {
        if( NULL != pNode )
        {
            if( pNode->m_AdjacentColorsNodeIDs.size() >= 3 )
            {
                m_pCureentNode = pNode;
                m_CurrentSearchColor = pNode->GetColor();
                m_ColorSpotIDList = pNode->m_AdjacentColorsNodeIDs;
                m_ColorSpotNameList = pNode->m_AdjacentColorsNodeNames;
                //save the list
                CreateSpot();
            }
        }

        return true;
    }

    bool CColorSpotController::ClearBuffers()
    {
        if( m_ColorSpotNameList.size() >= 3 )
        {
            //save the list
            CreateSpot();
        }

        m_ColorSpotNameList.clear();
        m_ColorSpotIDList.clear();
        m_CurrentSearchColor = 0;

        return true;
    }

    bool CColorSpotController::CreateSpot()
    {
        CString tempKey;
        CString tempValue;
        CString temp;
        int i = 0;

        for (std::vector<unsigned int>::iterator it = m_ColorSpotIDList.begin() ; it != m_ColorSpotIDList.end(); ++it, i++)
        {
            itoa( *it, temp.GetBuffer(), 10 );
            tempKey.Append( temp.GetString() );
            tempKey.Append( ";" );

            tempValue.Append(m_ColorSpotNameList[i]);
            tempValue.Append( ";" );
        }

        AddColorSpot( m_CurrentSearchColor, tempKey, tempValue );
        //go through the list & consolidate the key and value
        return true;
    }

    bool CColorSpotController::AddColorSpot( char cColor, CString key, CString value)
    {
         map <CString, CString> *pMap ;
        switch( cColor )
        {
        case 'b':
            pMap = &m_BlueSpotList;
            break;

        case 'r':
           pMap = &m_RedSpotList;
            break;

        case 'g':
             pMap = &m_GreenSpotList;
            break;
        }

        if( NULL == pMap )
        {
            return false;
        }

         if( true == IsDuplicateSpot( key, *pMap ) )
         {
             return false;
         }
        
        (*pMap)[key] = value;

        return true;
    }

    int CColorSpotController::GetColorSpotCount()
    {
        return m_BlueSpotList.size() + m_RedSpotList.size() + m_GreenSpotList.size();
    }

    int CColorSpotController::GetColorSpotCount(char cColor)
    {
        map <CString, CString> *pMap = NULL ;

        switch( cColor )
        {
        case 'b':
            pMap = &m_BlueSpotList;
            break;

        case 'r':
            pMap = &m_RedSpotList;
            break;

        case 'g':
            pMap = &m_GreenSpotList;
            break;
        }

        if( NULL == pMap )
        {
            return 0;
        }

        return pMap->size();
    }

    bool CColorSpotController::GetColorSpotIndex( char cColor, int nSearchIndex,  std::vector<CString> colorSpotNameList)
    {
         map <CString, CString> *pMap ;
         int nIndex = 0;
        switch( cColor )
        {
        case 'b':
            pMap = &m_BlueSpotList;
            break;

        case 'r':
           pMap = &m_RedSpotList;
            break;

        case 'g':
             pMap = &m_GreenSpotList;
            break;
        }

         for (std::map<CString,CString>::iterator it=pMap->begin(); it!=pMap->end(); ++it, nIndex++)
         {
             if( nSearchIndex == nIndex )
             {
                 ParseColorSpot( it->second );
                 colorSpotNameList = m_ColorSpotNameList;
             }
         }

         return true;
    }

    bool CColorSpotController::GetColorSpotIndex( char cColor, int nSearchIndex,  CString &colorSpots)
    {
         map <CString, CString> *pMap ;
         int nIndex = 0;
        switch( cColor )
        {
        case 'b':
            pMap = &m_BlueSpotList;
            break;

        case 'r':
           pMap = &m_RedSpotList;
            break;

        case 'g':
             pMap = &m_GreenSpotList;
            break;
        }

         for (std::map<CString,CString>::iterator it=pMap->begin(); it!=pMap->end(); ++it, nIndex++)
         {
             if( nSearchIndex == nIndex )
             {
                 colorSpots =  it->second;
             }
         }

         return true;
    }

    bool CColorSpotController::ParseColorSpot( CString Value)
    {
        int nPosition = 0;
        CString szToken;
        m_ColorSpotNameList.clear();

        szToken = Value.Tokenize( ";" , nPosition );;
        while(!szToken.IsEmpty())
        {
            m_ColorSpotNameList.push_back( szToken.GetString() );
            szToken = Value.Tokenize( ";" , nPosition );            
        }

        return true;
    }

    bool CColorSpotController::IsDuplicateSpot(CString key, map <CString, CString> currentSpotList)
    {
        bool bDuplicate = false;

        for (std::map<CString, CString>::iterator it = currentSpotList.begin() ; it != currentSpotList.end(); ++it)
        {
            if( it->first == key )
            {
                bDuplicate = true;
                break;
            }

            if( -1 != it->first.Find( key ) )
            {
                bDuplicate = true;
                break;
            }

            if( key.Find( it->first ) )
            {
                bDuplicate = true;
                break;
            }

        }

        return bDuplicate;
    }
}
