#include "StdAfx.h"
#include "RubiksCube.h"
#include <time.h>

CRubiksCube::CRubiksCube(void)
{
	m_pCubes = new CCubeState***[RUBIKS_CUBE_SIZE];

	for (int i = 0; i < RUBIKS_CUBE_SIZE; i++)
	{
		m_pCubes[i] = new CCubeState**[RUBIKS_CUBE_SIZE];

		for (int j = 0; j < RUBIKS_CUBE_SIZE; j++)
		{
			m_pCubes[i][j] = new CCubeState*[RUBIKS_CUBE_SIZE];

			for (int k = 0; k < RUBIKS_CUBE_SIZE; k++)
			{
				m_pCubes[i][j][k] = CreateCube(i, j, k);
			}
		}
	}
}

CRubiksCube::~CRubiksCube(void)
{
	for (int i = 0; i < RUBIKS_CUBE_SIZE; i++)
	{
		for (int j = 0; j < RUBIKS_CUBE_SIZE; j++)
		{
			for (int k = 0; k < RUBIKS_CUBE_SIZE; k++)
			{
				delete m_pCubes[i][j][k];
				m_pCubes[i][j][k] = NULL;
			}

			delete[] m_pCubes[i][j];
			m_pCubes[i][j] = NULL;
		}

		delete[] m_pCubes[i];
		m_pCubes[i] = NULL;
	}

	delete[] m_pCubes;
	m_pCubes = NULL;
}

CCubeState* CRubiksCube::CreateCube(int x, int y, int z)
{
	CColor left, right, top, bottom, front, back;

	if (x == 0)
	{
		left = CColor(255, 165, 0);	// orange
		right = CColor(0, 0, 0);	// black
	}

	else if (x == 1)
	{
		left = CColor(0, 0, 0);		// black
		right = CColor(0, 0, 0);	// black
	}

	else if (x == 2)
	{
		left = CColor(0, 0, 0);		// black
		right = CColor(255, 0, 0);	// red
	}

	if (y == 0)
	{
		bottom = CColor(0, 0, 255);	// blue
		top = CColor(0, 0, 0);		// black
	}

	else if (y == 1)
	{
		bottom = CColor(0, 0, 0);	// black
		top = CColor(0, 0, 0);		// black
	}

	else if (y == 2)
	{
		bottom = CColor(0, 0, 0);		// black
		top = CColor(255, 255, 255);	// white
	}
	
	if (z == 0)
	{
		back = CColor(255, 255, 0);	// yellow
		front = CColor(0, 0, 0);	// black
	}

	else if (z == 1)
	{
		back = CColor(0, 0, 0);		// black
		front = CColor(0, 0, 0);	// black
	}

	else if (z == 2)
	{
		back = CColor(0, 0, 0);		// black
		front = CColor(0, 255, 0);	// green
	}

	return new CCubeState(top, bottom, left, right, front, back);
}

CCubeState* CRubiksCube::GetCube(int x, int y, int z)
{
	if (!IsValidCube(x, y, z))
		return NULL;
	else
		return m_pCubes[x][y][z];
}

BOOL CRubiksCube::IsValidCube(int x, int y, int z)
{
	return (x >= 0 && x < RUBIKS_CUBE_SIZE) &&
			(y >= 0 && y < RUBIKS_CUBE_SIZE) &&
			(z >= 0 && z < RUBIKS_CUBE_SIZE);
}

VOID CRubiksCube::Rotate(int section, int turns)
{
	if (section >= 0 && section < 3)
	{
		for (int i = 0; i < RUBIKS_CUBE_SIZE; i++)
		{
			for (int k = 0; k < RUBIKS_CUBE_SIZE; k++)
			{
				for (int l = 0; l < turns; l++)
				{
					m_pCubes[i][section][k]->TurnRight();
				}
			}
		}

		for (int i = 0; i < turns; i++)
		{
			CCubeState* temp1 = m_pCubes[0][section][0];
			CCubeState* temp2 = m_pCubes[0][section][2];

			m_pCubes[0][section][2] = temp1;

			temp1 = m_pCubes[2][section][2];
			m_pCubes[2][section][2] = temp2;

			temp2 = m_pCubes[2][section][0];
			m_pCubes[2][section][0] = temp1;

			m_pCubes[0][section][0] = temp2;

			temp1 = m_pCubes[1][section][0];
			temp2 = m_pCubes[0][section][1];

			m_pCubes[0][section][1] = temp1;
			temp1 = m_pCubes[1][section][2];

			m_pCubes[1][section][2] = temp2;
			temp2 = m_pCubes[2][section][1];

			m_pCubes[2][section][1] = temp1;
			m_pCubes[1][section][0] = temp2;
		}
	}
}

VOID CRubiksCube::Tilt(int section, int turns)
{
	if (section >=0 && section < 3)
	{
		for (int j = 0; j < RUBIKS_CUBE_SIZE; j++)
		{
			for (int k = 0; k < RUBIKS_CUBE_SIZE; k++)
			{
				for (int l = 0; l < turns; l++)
				{
					m_pCubes[section][j][k]->TiltDown();
				}
			}
		}

		for (int i = 0; i < turns; i++)
		{
			CCubeState* temp1 = m_pCubes[section][0][0];
			CCubeState* temp2 = m_pCubes[section][2][0];

			m_pCubes[section][2][0] = temp1;

			temp1 = m_pCubes[section][2][2];
			m_pCubes[section][2][2] = temp2;

			temp2 = m_pCubes[section][0][2];
			m_pCubes[section][0][2] = temp1;

			m_pCubes[section][0][0] = temp2;

			temp1 = m_pCubes[section][1][0];
			temp2 = m_pCubes[section][2][1];

			m_pCubes[section][2][1] = temp1;
			temp1 = m_pCubes[section][1][2];

			m_pCubes[section][1][2] = temp2;
			temp2 = m_pCubes[section][0][1];

			m_pCubes[section][0][1] = temp1;
			m_pCubes[section][1][0] = temp2;
		}
	}
}

VOID CRubiksCube::Turn(int section, int turns)
{
	if (section >= 0 && section < 3)
	{
		// rotate each cube
		for (int i = 0; i < RUBIKS_CUBE_SIZE; i++)
		{
			for (int j = 0; j < RUBIKS_CUBE_SIZE; j++)
			{
				for (int l = 0; l < turns; l++)
				{
					m_pCubes[i][j][section]->TiltLeft();
				}
			}
		}

		for (int i = 0; i < turns; i++)
		{
			CCubeState* temp1 = m_pCubes[0][0][section];
			CCubeState* temp2 = m_pCubes[2][0][section];

			m_pCubes[2][0][section] = temp1;

			temp1 = m_pCubes[2][2][section];
			m_pCubes[2][2][section] = temp2;

			temp2 = m_pCubes[0][2][section];
			m_pCubes[0][2][section] = temp1;

			m_pCubes[0][0][section] = temp2;

			temp1 = m_pCubes[0][1][section];
			temp2 = m_pCubes[1][0][section];

			m_pCubes[1][0][section] = temp1;
			temp1 = m_pCubes[2][1][section];

			m_pCubes[2][1][section] = temp2;
			temp2 = m_pCubes[1][2][section];

			m_pCubes[1][2][section] = temp1;
			m_pCubes[0][1][section] = temp2;
		}
	}
}

VOID CRubiksCube::Randomize()
{
	int count = 0;
	bool done = false;
	srand((unsigned)time(NULL));

	while (!done)
	{
		int turns, section, axis;
		turns = (int)((double)rand() / (RAND_MAX + 1) * (4));
		section = (int)((double)rand() / (RAND_MAX + 1) * (RUBIKS_CUBE_SIZE));
		axis = (int)((double)rand() / (RAND_MAX + 1) * (3));

		switch (axis)
		{
		case 0:
			this->Rotate(section, turns);
			break;
		case 1:
			this->Tilt(section, turns);
		case 2:
			this->Turn(section, turns);
		}

		count++;

		if (count >= 20)
		{
			int diff = count - 20;
			int probability = (int)((double)rand() / (RAND_MAX + 1) * (100 - diff) + diff);

			if (probability >= 75)
				done = true;
		}
	}
}

BOOL CRubiksCube::IsSolved()
{
	return IsFaceSolved(Top) &&
		IsFaceSolved(Bottom) &&
		IsFaceSolved(Left) &&
		IsFaceSolved(Right) &&
		IsFaceSolved(Front) &&
		IsFaceSolved(Back);
}

BOOL CRubiksCube::IsFaceSolved(Face face)
{
	if (face == Top || face == Bottom)
	{
		int j = (face == Top)?2:0;

		CColor color = m_pCubes[0][j][0]->GetFaceColor(face);

		for (int i = 0; i < RUBIKS_CUBE_SIZE; i++)
		{
			for (int k = 0; k < RUBIKS_CUBE_SIZE; k++)
			{
				if (m_pCubes[i][j][k]->GetFaceColor(face) != color)
					return FALSE;
			}
		}
	}

	else if (face == Left || face == Right)
	{
		int i = (face == Left)?0:2;

		CColor color = m_pCubes[i][0][0]->GetFaceColor(face);

		for (int j = 0; j < RUBIKS_CUBE_SIZE; j++)
		{
			for (int k = 0; k < RUBIKS_CUBE_SIZE; k++)
			{
				if (m_pCubes[i][j][k]->GetFaceColor(face) != color)
					return FALSE;
			}
		}
	}

	else if (face == Front || face == Back)
	{
		int k = (face == Front)?2:0;

		CColor color = m_pCubes[0][0][k]->GetFaceColor(face);

		for (int i = 0; i < RUBIKS_CUBE_SIZE; i++)
		{
			for (int j = 0; j < RUBIKS_CUBE_SIZE; j++)
			{
				if (m_pCubes[i][j][k]->GetFaceColor(face) != color)
					return FALSE;
			}
		}
	}

	return TRUE;
}