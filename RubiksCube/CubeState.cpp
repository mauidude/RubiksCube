#include "StdAfx.h"
#include "CubeState.h"

const int FACE_COUNT = 6;

CCubeState::CCubeState(CColor cTop, CColor cBottom, CColor cLeft, 
				CColor cRight, CColor cFront, CColor cBack)
{
	m_pFaces = new CColor[FACE_COUNT];

	m_pFaces[Top] = cTop;
	m_pFaces[Bottom] = cBottom;
	m_pFaces[Left] = cLeft;
	m_pFaces[Right] = cRight;
	m_pFaces[Front] = cFront;
	m_pFaces[Back] = cBack;
}

CCubeState::~CCubeState(void)
{
	delete[] m_pFaces;
	m_pFaces = NULL;
}

CColor CCubeState::GetFaceColor(Face eFace)
{
	return m_pFaces[eFace];
}

void CCubeState::TiltUp()
{
	CColor temp1 = m_pFaces[Top];
	CColor temp2 = m_pFaces[Back];

	m_pFaces[Top] = m_pFaces[Front];
	m_pFaces[Back] = temp1;

	temp1 = m_pFaces[Bottom];
	m_pFaces[Bottom] = temp2;

	m_pFaces[Front] = temp1;
}

void CCubeState::TiltDown()
{
	CColor temp1 = m_pFaces[Top];
	CColor temp2 = m_pFaces[Front];

	m_pFaces[Top] = m_pFaces[Back];
	m_pFaces[Front] = temp1;

	temp1 = m_pFaces[Bottom];
	m_pFaces[Bottom] = temp2;

	m_pFaces[Back] = temp1;
}

void CCubeState::TurnLeft()
{
	CColor temp1 = m_pFaces[Front];
	CColor temp2 = m_pFaces[Left];

	m_pFaces[Front] = m_pFaces[Right];
	m_pFaces[Left] = temp1;

	temp1 = m_pFaces[Back];
	m_pFaces[Back] = temp2;

	m_pFaces[Right] = temp1;
}

void CCubeState::TurnRight()
{
	CColor temp1 = m_pFaces[Front];
	CColor temp2 = m_pFaces[Right];

	m_pFaces[Front] = m_pFaces[Left];
	m_pFaces[Right] = temp1;

	temp1 = m_pFaces[Back];
	m_pFaces[Back] = temp2;

	m_pFaces[Left] = temp1;
}

void CCubeState::TiltLeft()
{
	CColor temp1 = m_pFaces[Top];
	CColor temp2 = m_pFaces[Left];

	m_pFaces[Top] = m_pFaces[Right];
	m_pFaces[Left] = temp1;

	temp1 = m_pFaces[Bottom];
	m_pFaces[Bottom] = temp2;

	m_pFaces[Right] = temp1;
}

void CCubeState::TiltRight()
{
	CColor temp1 = m_pFaces[Top];
	CColor temp2 = m_pFaces[Right];

	m_pFaces[Top] = m_pFaces[Left];
	m_pFaces[Right] = temp1;

	temp1 = m_pFaces[Bottom];
	m_pFaces[Bottom] = temp2;

	m_pFaces[Left] = temp1;
}