#include "stdafx.h"
#include "Globals.h"

BOOL g_bMouseDown;
CCamera g_cCamera;
CRubiksCube g_cCube;
int g_nPrevX = -1;
int g_nPrevY = -1;
BOOL g_bRotating = FALSE;
CVector3 g_vRotationAxis;
int g_nRotatingSection = 0;
int g_nRotationAngle = 0;
BOOL g_bFullScreen;
RECT g_rWnd;
CVector3 g_vMouseDown;
int g_nHitCount = 0;
GLuint g_pSelectBuffer[SELECT_BUFFER_SIZE];
HCURSOR g_hArrow;
HCURSOR g_hHand;
BOOL g_bFlipRotation = FALSE;
TCHAR g_szTitle[MAX_LOADSTRING];					// The title bar text
HWND g_hWnd;
HINSTANCE g_hInstance;								// current instance