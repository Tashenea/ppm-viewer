#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class VerticalFlipEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int counter = 0;
		int x = 0;
		int y = 0;
		vector<vector<Pixel>> vacant{};
		vacant.resize(doc.getHeight());

		for (int i = 0; i < doc.getHeight(); i++)
		{
			vacant[i].resize(doc.getWidth());
		}

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				vacant[i][j] = doc[i][j];
			}
		}
		for (int i = doc.getHeight() - 1; i >= 0; i--)
		{
			for (int j = 0; j < doc[i].size(); j++)
			{
				doc[counter][j] = vacant[i][j];
				x++;
			}
			counter++;
			y++;
			x = 0;
		}
	}
};