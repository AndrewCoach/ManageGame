/*
  ==============================================================================

	ButtonImage.cpp
	Created: 21 Jan 2021 8:31:56pm
	Author:  kocia

  ==============================================================================
*/

#include "ButtonImage.h"

/*
  ==============================================================================
*/

ButtonImage::ButtonImage(const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath) :
	imagePath(absoluteImagePath),
	pFile(juce::File(absoluteImagePath)),
	pStream(new juce::FileInputStream(pFile)),
	pImage(pImageFormat.decodeImage(*this->pStream)),
	imagePath2(absoluteImageOnHoverPath),
	pFile2(juce::File(absoluteImageOnHoverPath)),
	pStream2(new juce::FileInputStream(pFile2)),
	pImageOnHover(pImageFormat2.decodeImage(*this->pStream2)),
	pImageOnClick(juce::Image(this->pImage))
{
	pImageOnHover.duplicateIfShared();

	// SETTINGS FOR ONCILCK/ONHOVER BUTTON LOOKS
	// pImageOnHover.desaturate();
	// pImageOnClick.multiplyAllAlphas(0.8F);
}

ButtonImage::~ButtonImage()
{
}

juce::Image& ButtonImage::getImage()
{
	return pImage;
}

const juce::String ButtonImage::getPath()
{
	return this->imagePath;
}

juce::Image& ButtonImage::getImageOnClick()
{
	return pImageOnClick;
}

juce::Image& ButtonImage::getImageOnHover()
{
	return pImageOnHover;
}

void ButtonImage::changeImages(const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath)
{
	this->imagePath = absoluteImagePath;
	this->pFile = juce::File(absoluteImagePath);
	this->pStream.reset(new juce::FileInputStream(pFile));
	this->pImage = this->pImageFormat.decodeImage(*this->pStream);

	this->imagePath2 = absoluteImageOnHoverPath;
	this->pFile2 = juce::File(absoluteImageOnHoverPath);
	this->pStream2.reset(new juce::FileInputStream(pFile2));
	this->pImageOnHover = this->pImageFormat2.decodeImage(*this->pStream2);

	this->pImageOnClick = juce::Image(this->pImage);
	pImageOnClick.duplicateIfShared();
}

/*
  ==============================================================================
*/

MyIMageButton::MyIMageButton(std::shared_ptr<CalculationManager> pCalcManager,
	const juce::String absoluteImagePath, const juce::String absoluteImageOnHOverPath, ButtonType initialType) :
	pCManager(pCalcManager),
	bImage(absoluteImagePath, absoluteImageOnHOverPath), type(initialType)
{
	// Here we can set the different properties of image normal/onclick/onhover.
	this->setImages(false, true, true, this->bImage.getImage(), 1.0F,
		juce::Colour((juce::uint8) 255, (juce::uint8) 255, (juce::uint8)255, (juce::uint8) 0),
		this->bImage.getImageOnHover(), 1.0F,
		juce::Colour((juce::uint8) 255, (juce::uint8) 255, (juce::uint8)255, (juce::uint8) 0),
		this->bImage.getImageOnClick(), 1.0F,
		juce::Colour((juce::uint8) 255, (juce::uint8) 255, (juce::uint8)255, (juce::uint8) 0));

	// This is the callBack to the Calculation manager.
	this->onClick = [this]() {pCManager.get()->calculate(type, this); };
}

MyIMageButton::~MyIMageButton()
{
}

void MyIMageButton::changeImages(const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath, ButtonType initialType)
{
	this->bImage.changeImages(absoluteImagePath, absoluteImageOnHoverPath);
	this->type = initialType;

	// Here we can set the different properties of image normal/onclick/onhover.
	this->setImages(false, true, true, this->bImage.getImage(), 1.0F,
		juce::Colour((juce::uint8) 255, (juce::uint8) 255, (juce::uint8)255, (juce::uint8) 0),
		this->bImage.getImageOnHover(), 1.0F,
		juce::Colour((juce::uint8) 255, (juce::uint8) 255, (juce::uint8)255, (juce::uint8) 0),
		this->bImage.getImageOnClick(), 1.0F,
		juce::Colour((juce::uint8) 255, (juce::uint8) 255, (juce::uint8)255, (juce::uint8) 0));
}

juce::String MyIMageButton::getImagePath()
{
	return this->bImage.getPath();
}

ButtonType MyIMageButton::getButtonType()
{
	return this->type;
}
