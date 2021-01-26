/*
  ==============================================================================

	TabComponent.cpp
	Created: 21 Jan 2021 8:20:45pm
	Author:  kocia

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TabComponent.h"

//==============================================================================
TabComponent::TabComponent() :
	tab(juce::TabbedButtonBar::Orientation::TabsAtTop)
{
	this->addAndMakeVisible(this->tab);
}

TabComponent::~TabComponent()
{
}

void TabComponent::addTab(juce::Component& componentToShow, juce::String text, juce::Colour bgColour)
{
	this->tab.addTab(text, bgColour, &componentToShow, false);
}

void TabComponent::removeTab(const unsigned int tabIndex)
{
	this->tab.removeTab(tabIndex);
}

void TabComponent::paint(juce::Graphics& g)
{
	this->tab.setBounds(this->getLocalBounds());
}

void TabComponent::resized()
{
	this->tab.setBounds(this->getLocalBounds());
}
