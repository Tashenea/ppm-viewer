#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"


class NegateBlueEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				p.blue = 255 - p.blue;

				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};