/*
  ==============================================================================

	PersonalityComponent.cpp
	Created: 19 Jan 2021 11:30:39pm
	Author:  kocia

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PersonalityComponent.h"

//==============================================================================
PersonalityComponent::PersonalityComponent(BehaviorType defaultType, std::unique_ptr<BehaviorComponent> defaultBehavior)
{
	std::unique_ptr<BehaviorComponent> ptr;
	ptr.reset(defaultBehavior.release());
	this->behaviorMap.emplace(defaultType, std::move(ptr));
	this->addAndMakeVisible(this->behaviorMap.find(defaultType)->second.get());
	chosenType = defaultType;
}

PersonalityComponent::~PersonalityComponent()
{
}

void PersonalityComponent::addBehavior(BehaviorType behaviorType, std::unique_ptr<BehaviorComponent> defaultBehavior)
{
	if (this->behaviorMap.find(behaviorType) == this->behaviorMap.end())
	{
		std::unique_ptr<BehaviorComponent> ptr;
		ptr.reset(defaultBehavior.release());
		this->behaviorMap.emplace(behaviorType, std::move(ptr));
		this->addChildComponent(this->behaviorMap.find(behaviorType)->second.get());
	}
}

void PersonalityComponent::removeBehavior(BehaviorType behaviorType)
{
	if (this->behaviorMap.find(behaviorType) != this->behaviorMap.end())
	{
		this->behaviorMap.erase(behaviorType);
		this->childrenChanged();
	}
}

void PersonalityComponent::displayBehavior()
{
	this->behaviorMap.find(chosenType)->second.get()->displayImage();
}

void PersonalityComponent::switchBehavior(BehaviorType behaviorType)
{
	if (this->behaviorMap.find(behaviorType) != this->behaviorMap.end())
	{
		chosenType = behaviorType;
	}

	for (auto it = this->behaviorMap.begin(); it != this->behaviorMap.end(); ++it)
	{
		if (it == this->behaviorMap.find(chosenType))
		{
			it->second.get()->setVisible(true);
		}
		else
		{
			it->second.get()->setVisible(false);
		}
	}

	this->repaint();
}

void PersonalityComponent::paint(juce::Graphics& g)
{
	this->behaviorMap.find(chosenType)->second.get()->setBounds(this->getLocalBounds());
}

void PersonalityComponent::resized()
{
	this->behaviorMap.find(chosenType)->second.get()->setBounds(this->getLocalBounds());
}
