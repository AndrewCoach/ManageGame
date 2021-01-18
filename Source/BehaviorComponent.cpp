/*
  ==============================================================================

	BehaviorComponent.cpp
	Created: 18 Jan 2021 4:20:03pm
	Author:  kocia

  ==============================================================================
*/

#include <JuceHeader.h>
#include "BehaviorComponent.h"

//==============================================================================
BehaviorComponent::BehaviorComponent() : imageVector(std::vector<PngComponent>()), cycleCount(1), vectorPosition(0)
{
	this->imageVector.push_back(PngComponent("E:\\GITHUB repositories\\ManageGame\\ManageGame\\ukol.png"));
	this->addAndMakeVisible(*imageVector.begin());
}

BehaviorComponent::~BehaviorComponent()
{
}

void BehaviorComponent::addImage(const juce::String absoluteImagePath)
{
	this->imageVector.push_back(PngComponent(absoluteImagePath));
}

void BehaviorComponent::removeImage(const juce::String absoluteImagePath)
{
	for (auto it = this->imageVector.begin(); it != this->imageVector.end(); ++it)
	{
		if (it->getImagePath() == absoluteImagePath)
		{
			this->imageVector.erase(it);
			break;
		}
	}
}

void BehaviorComponent::changeCycleCount(const unsigned int imageCount)
{
	this->cycleCount = imageCount;
}

void BehaviorComponent::changeCycleSpeed(const unsigned int miliseconds)
{
}

void BehaviorComponent::displayImage()
{
	size_t maxPosition = this->imageVector.size() - 1;
	if (this->vectorPosition >= maxPosition || maxPosition < 0)
	{
		this->vectorPosition = 0;
	}
	else
	{
		++this->vectorPosition;
	}
}

void BehaviorComponent::paint(juce::Graphics& g)
{
}

void BehaviorComponent::resized()
{
	this->imageVector.at(this->vectorPosition).setBounds(this->getLocalBounds());
}
