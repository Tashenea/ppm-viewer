#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"


class NegateBlue : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& position = doc[i][j];
				position.blue = 255 - position.blue;
				doc[i][j] = position;
			}
		}
	}
};