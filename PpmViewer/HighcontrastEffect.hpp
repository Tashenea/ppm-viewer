#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class HighContrastEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& position = doc[i][j];
				if (position.red >= 128)
				{
					position.red = 255;
				}
				else
				{
					position.red = 0;
				}
				if (position.green >= 128)
				{
					position.green = 255;
				}
				else
				{
					position.green = 0;
				}
				if (position.blue >= 128)
				{
					position.blue = 255;
				}
				else
				{
					position.blue = 0;
				}
				doc[i][j] = position;
			}
		}
	}
};