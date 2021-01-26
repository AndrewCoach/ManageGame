/*
  ==============================================================================

	ButtonImage.h
	Created: 21 Jan 2021 8:31:56pm
	Author:  kocia

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Calculation.h"

/// <summary>
/// An underlying class representing an assortment of images for a button.
/// </summary>
class ButtonImage
{
public:
	ButtonImage(const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath);
	~ButtonImage();

	/// <summary>
	/// Gets the default image.
	/// </summary>
	/// <returns>juce::Image&</returns>
	juce::Image& getImage();

	/// <summary>
	/// Gets the absolute path of the source image.
	/// </summary>
	/// <returns>const juce::String</returns>
	const juce::String getPath();

	/// <summary>
	/// Returns the image, that represents image when clicked.
	/// </summary>
	/// <returns>juce::Image&</returns>
	juce::Image& getImageOnClick();

	/// <summary>
	/// Gets the image that displays on mouse hover.
	/// </summary>
	/// <returns>juce::Image&</returns>
	juce::Image& getImageOnHover();

	/// <summary>
	/// Changes the underlying images.
	/// </summary>
	/// <param name="absoluteImagePath">The absolute image path.</param>
	void changeImages(const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath);

private:
	juce::String imagePath;
	juce::File pFile;
	std::unique_ptr<juce::FileInputStream> pStream;
	juce::PNGImageFormat pImageFormat;
	juce::Image pImage;

	juce::String imagePath2;
	juce::File pFile2;
	std::unique_ptr<juce::FileInputStream> pStream2;
	juce::PNGImageFormat pImageFormat2;
	juce::Image pImageOnHover;

	juce::Image pImageOnClick;
};

/// <summary>
/// This class encompasses a ButtonImage class, and represents an IMageButton component.
/// </summary>
/// <seealso cref="juce::ImageButton" />
class MyIMageButton : public juce::ImageButton
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="MyIMageButton"/> class.
	/// </summary>
	/// <param name="pCalcManager">The calculation manager. When the button is clicked, the callback function calls this object.</param>
	/// <param name="absoluteImagePath">The absolute image path for the image on a button.</param>
	/// <param name="absoluteImageOnHoverPath">The absolute image path for the image on a button.</param>
	/// <param name="initialType">The initial type of the image that will be delivered to the calc. manager with the callback for identification.</param>
	MyIMageButton(std::shared_ptr<CalculationManager> pCalcManager, const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath, ButtonType initialType);
	~MyIMageButton();

	/// <summary>
	/// Changes the underlying images.
	/// </summary>
	/// <param name="absoluteImagePath">The absolute image path.</param>
	void changeImages(const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath, ButtonType initialType);

	/// <summary>
	/// Gets the absolute image path.
	/// </summary>
	/// <returns>juce::String</returns>
	juce::String getImagePath();

	/// <summary>
	/// Gets the type of the button.
	/// </summary>
	/// <returns>ButtonType</returns>
	ButtonType getButtonType();

private:
	std::shared_ptr<CalculationManager> pCManager;
	ButtonType type;
	ButtonImage bImage;
};
