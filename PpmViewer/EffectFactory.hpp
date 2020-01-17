#pragma once
#include "RemoveRedEffect.hpp"
#include "RemoveGreen.hpp"
#include "Removeblue.hpp"
#include "NegateRedEffect.hpp"
#include "NegateGreenEffect.hpp"
#include "NegateBlueEffect.hpp"
#include "GreyscaleEffect.hpp"
#include "RandomNoiseEffect.hpp"
#include "HighContrastEffect.hpp"
#include "HorizontalFlipEffect.hpp"
#include "PixelatedEffect.hpp"
#include "VerticalFlipEffect.hpp"
#include "BlurringEffect.hpp"
#include "Rotate90Effect.hpp"


	enum class ImageEffectType
{
	RemoveRed = 1,
	RemoveGreen = 2,
	RemoveBlue = 3,
	NegateRed = 4,
	NegateGreen = 5,
	NegateBlue = 6,
	Greyscale = 7,
	RandomNoise = 8,
	HighContrast = 9,
	HorizontalFlip = 10,
	VerticalFlip = 11,
	PixelateImage = 12,
	BlurImage = 13,
	Rotate90 = 14,
	
};


class EffectFactory
{
public:
	static ImageEffect* createEffect(ImageEffectType effect_type)
	{
		enum class ImageEffectType
		{
			RemoveRed,
			RemoveGreen,
			RemoveBlue,
			NegateRed,
			NegateGreen,
			NegateBlue,
			Grayscale,
			RandomNoise,
			HighContrast,
			FlipHorizontally,
			FlipVertically,
			Blur,
			Pixelate,
			Rotate90
		};

		class EffectFactory
		{
		public:
			static ImageEffect* createEffect(ImageEffectType effect_type)
			{
				switch (effect_type)
				{
				case ImageEffectType::RemoveRed:
					return new RemoveRedEffect{};
					break;
				case ImageEffectType::RemoveGreen:
					return new RemoveGreenEffect{};
					break;
				case ImageEffectType::RemoveBlue:
					return new RemoveBlueEffect{};
					break;
				case ImageEffectType::NegateRed:
					return new NegateRedEffect{};
					break;
				case ImageEffectType::NegateGreen:
					return new NegateGreenEffect{};
					break;
				case ImageEffectType::NegateBlue:
					return new NegateBlueEffect{};
					break;
				case ImageEffectType::Grayscale:
					return new GrayscaleEffect{};
					break;
				case ImageEffectType::RandomNoise:
					return new RandomNoiseEffect{};
					break;
				case ImageEffectType::HighContrast:
					return new HighContrastEffect{};
					break;
				case ImageEffectType::FlipHorizontally:
					return new HorizontalFlipEffect{};
					break;
				case ImageEffectType::FlipVertically:
					return new VerticalFlipEffect{};
					break;
				case ImageEffectType::Blur:
					return new BlurEffect{};
					break;
				case ImageEffectType::Pixelate:
					return new PixelateImageEffect{};
					break;
				case ImageEffectType::Rotate90:
					return new Rotate90Effect{};
					break;
				default:
					break;
				}
			}
		};
	