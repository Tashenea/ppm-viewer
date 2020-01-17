#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class PixelateEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i += 3)
		{
			for (int j = 0; j < doc.getWidth(); j += 3)
			{
				Pixel& pointer = doc[i][j];
				if (i + 1 == doc.getHeight() && j + 1 == doc.getWidth())
				{
					doc[i][j] = pointer;
				}
				else if (i + 2 == doc.getHeight() && j + 2 == doc.getWidth())
				{
					doc[i][j] = pointer;
					doc[i][j + 1] = pointer;
					doc[i + 1][j] = pointer;
					doc[i + 1][j + 1] = pointer;
				}
				else if (i + 2 == doc.getHeight() && j + 1 == doc.getWidth())
				{
					doc[i][j] = pointer;
					doc[i + 1][j] = pointer;
				}
				else if (i + 1 == doc.getHeight() && j + 2 == doc.getWidth())
				{
					doc[i][j] = pointer;
					doc[i][j + 1] = pointer;
				}
				else if (i + 1 == doc.getHeight())
				{
					doc[i][j] = pointer;
					doc[i][j + 1] = pointer;
					doc[i][j + 2] = pointer;
				}
				else if (i + 2 == doc.getHeight())
				{
					doc[i][j] = pointer;
					doc[i][j + 1] = pointer;
					doc[i][j + 2] = pointer;
					doc[i + 1][j] = pointer;
					doc[i + 1][j + 1] = pointer;
					doc[i + 1][j + 2] = pointer;
				}
				else if (j + 1 == doc.getWidth())
				{
					doc[i][j] = pointer;
					doc[i + 1][j] = pointer;
					doc[i + 2][j] = pointer;
				}
				else if (j + 2 == doc.getWidth())
				{
					doc[i][j] = pointer;
					doc[i][j + 1] = pointer;
					doc[i + 1][j] = pointer;
					doc[i + 1][j + 1] = pointer;
					doc[i + 2][j] = pointer;
					doc[i + 2][j + 1] = pointer;
				}
				else
				{
					doc[i][j] = pointer;
					doc[i][j + 1] = pointer;
					doc[i][j + 2] = pointer;
					doc[i + 1][j] = pointer;
					doc[i + 1][j + 1] = pointer;
					doc[i + 1][j + 2] = pointer;
					doc[i + 2][j] = pointer;
					doc[i][j + 2] = pointer;
					doc[i + 2][j + 2] = pointer;
				}
			}
		}
	}
};