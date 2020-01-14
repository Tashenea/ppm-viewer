#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
#include "Pixel.hpp"



class FlipHorizontallyEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		
		for (int i = 0; i < temp.size(); i++)
		{
			int col_counter = doc.getWidth() - 1;

			for (int j = 0; j < temp[i].size(); j++)
			{
				Pixel& a= doc[i][col_counter];
				Pixel b = temp[i][j];

				a = b;

				col_counter = col_counter -  1;

			}
		}
	}
};