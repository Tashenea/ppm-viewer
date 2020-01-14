#pragma once
# include "PpmDocument.hpp"
# include "ImageEffect.hpp"

class BlurringEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		vector<vector<Pixel>> temp(doc.getRawBytes);

		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < doc.getHeight(); j++)
			{
				if (j == 0)
				{
					int average;
					Pixel& a = doc[i][j];
					Pixel b = temp[i][j];
					Pixel c = temp[i][j + 1];
					average = ((a.red + b.red) / 2);
					a.red = average;
					average = ((a.blue + b.blue) / 2);
					a.blue = average;
					average = ((a.green + b.green) / 2);
					a.green = average;


				}
				else if (j == (doc.getWidth() - 1))
				{
					int average;
					Pixel& a = doc[i][j];
					Pixel b = temp[i][j];
					Pixel c = temp[i][j - 1];
					average = ((c.red + b.red) / 2);
					a.red = average;
					average = ((c.blue + b.blue) / 2);
					a.blue = average;
					average = ((c.green + b.green) / 2);
					a.green = average;
				}
				else
				{
					int average;
					Pixel& a = doc[i][j];
					Pixel b = temp[i][j - 1];
					Pixel c = temp[i][j];
					Pixel d = temp[i][j + 1];
					average = ((b.red + c.red + d.red) / 3);
					a.red = average;
					average = ((b.blue + c.blue + d.blue) / 3);
					a.blue = average;
					average = ((b.green + c.green + d.green) / 3);
					a.green = average;
				}

			}
		}
		for (int k = 0;k < doc.getWidth(); k++)
		{
			for (int U = 0; U < doc.getHeight(); U++)
			{
				if (U == 0)
				{
					int average;
					Pixel& a = doc[U][k];
					Pixel b/* q*/ = temp[U][k];
					Pixel e/* r*/ = temp[U + 1][k];
					average = (b.red + e.red) / 2;
					a.red = average;
					average = (b.blue + e.blue) / 2;
					a.blue= average;
					average = (b.green + e.green) / 2;
					a.green = average;
				}
				else if (U == (doc.getHeight() - 1))
				{
					int average;
					Pixel& a = doc[U][k];
					Pixel b = temp[U][k];
					Pixel f = temp[U - 1][k];
					average = (b.red + f.red) / 2;
					a.red = average;
					average = (b.green + f.green) / 2;
					a.green = average;
					average = (b.blue + f.blue) / 2;
					a.blue = average;
				}
				else
				{
					int average;
					Pixel& a = doc[U][k];
					Pixel b = temp[U - 1][k];
					Pixel c = temp[U][k];
					Pixel g = temp[U + 1][k];
					average = (b.red + c.red + g.red) / 3;
					a.red = average;
					average = (b.green + c.green + g.green) / 3;
					a.green = average;
					average = (b.blue + c.blue + g.blue) / 3;
					a.blue = average;
				}
			}
		}
	}
};