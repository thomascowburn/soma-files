//-----------------------------------------------------------------------------
// File: D3DTextr.h
//
// Desc: Functions to manage textures, including creating (loading from a
//       file), restoring lost surfaces, invalidating, and destroying.
//
//       Note: the implementation of these fucntions maintain an internal list
//       of loaded textures. After creation, individual textures are referenced
//       via their ASCII names.
//
// Copyright (c) 1997-1999 Microsoft Corporation. All rights reserved
//-----------------------------------------------------------------------------
#ifndef D3DTEXTR_H
#define D3DTEXTR_H
#include <ddraw.h>
#include <d3d.h>




//-----------------------------------------------------------------------------
// Access functions for loaded textures. Note: these functions search
// an internal list of the textures, and use the texture associated with the
// ASCII name.
//-----------------------------------------------------------------------------
LPDIRECTDRAWSURFACE7 D3DTextr_GetSurface( TCHAR* strName );




//-----------------------------------------------------------------------------
// Texture invalidation and restoration functions
//-----------------------------------------------------------------------------
HRESULT D3DTextr_Invalidate( TCHAR* strName );
HRESULT D3DTextr_Restore( TCHAR* strName, LPDIRECT3DDEVICE7 pd3dDevice );
HRESULT D3DTextr_InvalidateAllTextures();
HRESULT D3DTextr_RestoreAllTextures( LPDIRECT3DDEVICE7 pd3dDevice );




//-----------------------------------------------------------------------------
// Texture creation and deletion functions
//-----------------------------------------------------------------------------
#define D3DTEXTR_TRANSPARENTWHITE 0x00000001
#define D3DTEXTR_TRANSPARENTBLACK 0x00000002
#define D3DTEXTR_32BITSPERPIXEL   0x00000004
#define D3DTEXTR_16BITSPERPIXEL   0x00000008
#define D3DTEXTR_CREATEWITHALPHA  0x00000010


HRESULT D3DTextr_CreateTextureFromFile( TCHAR* strName, DWORD dwStage=0L,
                                        DWORD dwFlags=0L );
HRESULT D3DTextr_CreateEmptyTexture( TCHAR* strName, DWORD dwWidth,
                                     DWORD dwHeight, DWORD dwStage,
                                     DWORD dwFlags );
HRESULT D3DTextr_DestroyTexture( TCHAR* strName );
VOID    D3DTextr_SetTexturePath( TCHAR* strTexturePath );

HRESULT SurfaceBitmapToSurface(LPDIRECTDRAWSURFACE7 DstSurface, RECT Dst,
							   HBITMAP hbmBitmap, RECT Src);// 우석..

//-----------------------------------------------------------------------------
// LSP를 활용한 함수들
//-----------------------------------------------------------------------------
HRESULT D3DTextr_RestoreAllTexturesSpl( LPDIRECT3DDEVICE7 pd3dDevice );
HRESULT D3DTextr_RestoreSpl( TCHAR* strName, LPDIRECT3DDEVICE7 pd3dDevice );
HRESULT D3DTextr_CreateTextureFromFileSpl( TCHAR* strName, DWORD dwStage, DWORD dwFlags );
HRESULT D3DTextr_TextureInfo( TCHAR* strName , int** pFrame, int** pCurFrame, float** pTu, 
							 float** pTv , int** pWidth = 0, int** pHeight = 0, int** pTime =0,int** pX = 0,int** pY =0);
HRESULT D3DTextr_TextureInfoEx( TCHAR* strName , int** pFrame, RECT** pRC );
HRESULT D3DTextr_DestroyAllTextures();

BOOL LoadMagicRes( TCHAR* strName, DWORD dwStage, DWORD dwFlags, LPDIRECT3DDEVICE7 pd3dDevice  );

#endif // D3DTEXTR_H
