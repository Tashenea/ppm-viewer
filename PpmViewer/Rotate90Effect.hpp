#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"

class Rotate90Effect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int wid = doc.getHeight();
		int ht = doc.getWidth();
		vector<vector<Pixel>> newVector{};
		newVector.resize(ht);
		for (int i = 0; i < newVector.size(); i++)
		{
			newVector[i].resize(wid);
		}

		for (int i = 0; i < doc.getWidth(); i++)
		{
			vector<Pixel> temp_vector;
			for (int j = doc.getHeight() - 1; j >= 0; j--)
			{
				temp_vector.push_back(doc[j][i]);
			}
			newVector[i] = temp_vector;
		}



		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				doc[i][j] = newVector[i][j];
			}
		}

	}
};