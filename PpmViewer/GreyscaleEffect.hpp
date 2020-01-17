#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class GrayscaleEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& position = doc[i][j];
				int average = (position.red + position.green + position.blue) / 3;
				position.red = average;
				position.green = average;
				position.blue = average;

				doc[i][j] = position;
			}
		}
	}
};