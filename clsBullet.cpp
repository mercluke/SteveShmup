//#include "StdAfx.h"
#include "clsBullet.h"


clsBullet::clsBullet(void)
{
	bulletNext=NULL;
	dead = false;
}

clsBullet::~clsBullet(void)
{
	//sprite->Release();
}

/*void clsBullet::setPicture(LPDIRECT3DDEVICE9 dev)
{
	D3DXCreateTextureFromFileEx(dev,    // the device pointer
                                L"data/bullet.png",    // the file name
                                D3DX_DEFAULT,    // default width
                                D3DX_DEFAULT,    // default height
                                D3DX_DEFAULT,    // no mip mapping
                                NULL,    // regular usage
                                D3DFMT_A8R8G8B8,    // 32-bit pixels with alpha
                                D3DPOOL_MANAGED,    // typical memory handling
                                D3DX_DEFAULT,    // no filtering
                                D3DX_DEFAULT,    // no mip filtering
                                D3DCOLOR_XRGB(255, 0, 255),    // hot pink
                                NULL,    // no image info struct
                                NULL,    // not using 256 colors
                                &sprite);    // load to sprite
}

void clsBullet::draw(LPD3DXSPRITE spt)
{
	D3DXVECTOR2 spriteCentre=D3DXVECTOR2(32.0f,32.0f);
	D3DXVECTOR2 scaling(1.0f,1.0f);
	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat,NULL,0.0,&scaling,&spriteCentre,0,0);
	spt->SetTransform(&mat);

	D3DXVECTOR3 center(0.0f, 0.0f, 0.0f); // center at the upper-left corner
    D3DXVECTOR3 position(xPos,yPos,0);
    spt->Draw(sprite, NULL, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
	
}*/

void clsBullet::setXY(int x, int y)
{
	xPos = x;
	yPos = y;

}

int clsBullet::getX()
{
	return xPos;

}

int clsBullet::getY()
{
	return yPos;

}

void clsBullet::move(int direction)
{
	if(direction == 0)//up
	{
		if(yPos > 0)
		{
			yPos-=(SPEED*3);

		}
		else 
		{
			yPos = 0;
			dead = true;
		}
	}
}

bool clsBullet::checkDead()
{
	return dead;
}

bool clsBullet::collide(float AsteroidX, float AsteroidY)
{
	if((xPos+32) > AsteroidX && xPos < (AsteroidX+32))
	{
		if((yPos+11) < (AsteroidY + 32) && (yPos+11) > AsteroidY)
		{
			dead = true;
			return true;
		}
	}
	return false;
}