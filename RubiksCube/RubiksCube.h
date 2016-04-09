#pragma once

#include "CubeState.h"

const int RUBIKS_CUBE_SIZE = 3;

class CRubiksCube
{
public:
	CRubiksCube(void);
	~CRubiksCube(void);
	CCubeState* GetCube(int x, int y, int z);
	void Rotate(int section, int turns);	// around y axis
	void Tilt(int section, int turns);	// around x axis
	void Turn(int section, int turns);	// around z axis
	void Randomize();
	BOOL IsSolved();


protected:
	CCubeState*** *m_pCubes;
	BOOL IsValidCube(int x, int y, int z);

private:
	CCubeState* CreateCube(int x, int y, int z);
	BOOL IsFaceSolved(Face face);
};	
