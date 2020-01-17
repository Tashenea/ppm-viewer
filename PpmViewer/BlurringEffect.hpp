#pragma once
# include "PpmDocument.hpp"
# include "ImageEffect.hpp"

class BlurEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		vector<vector<Pixel>> temp_vector = doc.getRawBytes;

		for (int counter = 0; counter < 1; counter++)
		{
			for (int i = 0; i < doc.getHeight(); i++)
			{
				for (int j = 0; j < doc.getWidth(); j++)
				{
					if (j == 0)
					{
						Pixel& a = doc[i][j];
						Pixel b = temp_vector[i][j];
						Pixel c = temp_vector[i][j + 1];
						int average = (c.red + b.red) / 2;
						a.red = average;
						average = (c.green + b.green) / 2;
						a.green = average;
						average = (c.blue + b.blue) / 2;
						a.blue = average;
					}
					else if (j == (doc.getWidth() - 1))
					{
						Pixel& a = doc[i][j];
						Pixel b = temp_vector[i][j];
						Pixel c = temp_vector[i][j - 1];
						int average = (c.red + b.red) / 2;
						a.red = average;
						average = (c.green + b.green) / 2;
						a.green = average;
						average = (c.blue + b.blue) / 2;
						a.blue = average;
					}
					else
					{
						Pixel& a = doc[i][j];
						Pixel b = temp_vector[i][j - 1];
						Pixel c = temp_vector[i][j];
						Pixel d = temp_vector[i][j + 1];
						int average = (b.red + c.red + d.red) / 3;
						a.red = average;
						average = (b.green + c.green + d.green) / 3;
						a.green = average;
						average = (b.blue + c.blue + d.blue) / 3;
						a.blue = average;
					}
				}
			}

			temp_vector = doc.getRawBytes;
			for (int j = 0; j < doc.getWidth(); j++)
			{
				for (int i = 0; i < doc.getHeight(); i++)
				{
					if (i == 0)
					{
						Pixel& a = doc[i][j];
						Pixel b = temp_vector[i][j];
						Pixel c = temp_vector[i + 1][j];
						int average = (b.red + c.red) / 2;
						a.red = average;
						average = (b.green + c.green) / 2;
						a.green = average;
						average = (b.blue + c.blue) / 2;
						a.blue = average;
					}
					else if (i == (doc.getHeight() - 1))
					{
						Pixel& a = doc[i][j];
						Pixel b = temp_vector[i][j];
						Pixel c = temp_vector[i - 1][j];
						int average = (b.red + c.red) / 2;
						a.red = average;
						average = (b.green + c.green) / 2;
						a.green = average;
						average = (b.blue + c.blue) / 2;
						a.blue = average;
					} 
					else
					{
						Pixel& a = doc[i][j];
						Pixel b = temp_vector[i - 1][j];
						Pixel c = temp_vector[i][j];
						Pixel d = temp_vector[i + 1][j];
						int average = (b.red + c.red + d.red) / 3;
						a.red = average;
						average = (b.green + c.green + d.green) / 3;
						a.green = average;
						average = (b.blue + c.blue + d.blue) / 3;
						a.blue = average;
					}
				}
			}
		}
	}
};