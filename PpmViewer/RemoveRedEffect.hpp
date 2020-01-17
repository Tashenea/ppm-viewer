#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class RemoveRedEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& position = doc[i][j];
				position.red = 0;

				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = position;
			}
		}
	}
};