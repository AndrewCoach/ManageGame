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
BehaviorComponent::BehaviorComponent(const juce::String absoluteImagePath)
	: imageVector(std::vector<std::unique_ptr<PngComponent>>()),
	cycleCount(1),
	vectorPosition(0)
{
	std::unique_ptr<PngComponent> ptr;
	ptr.reset(new PngComponent(absoluteImagePath));
	this->imageVector.push_back(std::move(ptr));
	this->addAndMakeVisible(this->imageVector.begin()->get());
}

BehaviorComponent::~BehaviorComponent()
{
}

void BehaviorComponent::addImage(const juce::String absoluteImagePath)
{
	std::unique_ptr<PngComponent> ptr;
	ptr.reset(new PngComponent(absoluteImagePath));
	this->imageVector.push_back(std::move(ptr));
	this->addAndMakeVisible(this->imageVector.at(this->imageVector.size() - 1).get());
}

void BehaviorComponent::removeImage(const juce::String absoluteImagePath)
{
	for (auto it = this->imageVector.begin(); it != this->imageVector.end(); ++it)
	{
		if (it->get()->getImagePath() == absoluteImagePath)
		{
			this->imageVector.erase(it);
			this->childrenChanged();
			break;
		}
	}
}

void BehaviorComponent::changeCycleCount(const unsigned int imageCount)
{
	if (imageCount > 0 && imageCount <= this->imageVector.size())
		this->cycleCount = imageCount;
}

void BehaviorComponent::changeCycleSpeed(const unsigned int miliseconds)
{
}

void BehaviorComponent::displayImage()
{
	size_t maxPosition = this->imageVector.size() - 1;
	if (this->vectorPosition >= maxPosition || this->vectorPosition >= this->cycleCount - 1 || maxPosition < 0)
	{
		this->vectorPosition = 0;
	}
	else
	{
		++this->vectorPosition;
	}

	// cycle for setting all children to invisible
	for (auto it = this->imageVector.begin(); it != this->imageVector.end(); ++it)
	{
		it->get()->setVisible(false);
		it->get()->repaint();
	}
}

void BehaviorComponent::paint(juce::Graphics& g)
{
	this->imageVector.at(this->vectorPosition).get()->setVisible(true);
	this->imageVector.at(this->vectorPosition).get()->setBounds(this->getLocalBounds());
}

void BehaviorComponent::resized()
{
	this->imageVector.at(this->vectorPosition).get()->setVisible(true);
	this->imageVector.at(this->vectorPosition).get()->setBounds(this->getLocalBounds());
}
