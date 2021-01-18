/*
  ==============================================================================

	PngComponent.cpp
	Created: 18 Jan 2021 3:03:53pm
	Author:  kocia

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PngComponent.h"

//==============================================================================
PngComponent::PngComponent(const juce::String absoluteImagePath)
{
	// Questionable
	this->setSize(this->getLocalBounds().getX(), this->getLocalBounds().getY());

	pFile = juce::File(absoluteImagePath);
	pStream.reset(new juce::FileInputStream(pFile));
	pImage = juce::Image();
	pImage = pImageFormat.decodeImage(*pStream);
	pImageComponent.setImage(pImage);
	this->addAndMakeVisible(pImageComponent);
}

PngComponent::~PngComponent()
{
}

void PngComponent::changeImage(const juce::String absoluteImagePath)
{
	this->pFile = juce::File(absoluteImagePath);
	this->pStream.reset(new juce::FileInputStream(pFile));
	this->pImage = this->pImageFormat.decodeImage(*this->pStream);
	this->pImageComponent.setImage(this->pImage);
	this->repaint();
}

void PngComponent::paint(juce::Graphics& g)
{
}

void PngComponent::resized()
{
	pImageComponent.setBounds(getLocalBounds());
}
