#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class RandomNoiseEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		srand(time(NULL));
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& position = doc[i][j];
				int random = (rand() % 20);
				int random_val = random - 10;
				if ((position.red + random_val) >= 255)
				{
					position.red = 255;
				}
				else if ((position.red - random_val) <= 0)
				{
					position.red = 0;
				}
				else
				{
					position.red = position.red + random_val;
				}
				random = (rand() % 20);
				random_val = random - 10;
				if ((position.green + random_val) >= 255)
				{
					position.green = 255;
				}
				else if ((position.green - random_val) <= 0)
				{
					position.green = 0;
				}
				else
				{
					position.green = position.green + random_val;
				}
				random = (rand() % 20);
				random_val = random - 10;
				if ((position.blue + random_val) >= 255)
				{
					position.blue = 255;
				}
				else if ((position.blue - random_val) <= 0)
				{
					position.blue = 0;
				}
				else
				{
					position.blue = position.blue + random_val;
				}
				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = position;
			}
		}
	}
};