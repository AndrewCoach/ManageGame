/*
  ==============================================================================

	MyLookAndFeel.cpp
	Created: 23 Jan 2021 9:00:12pm
	Author:  kocia

  ==============================================================================
*/

#include "MyLookAndFeel.h"

MyLookAndFeel::MyLookAndFeel()
{
}

MyLookAndFeel::~MyLookAndFeel()
{
}

void MyLookAndFeel::drawProgressBar(juce::Graphics& g, juce::ProgressBar& p, int width, int height, double progress, const juce::String& textToShow)
{
	// Background
	g.setColour(juce::Colours::dimgrey);
	g.fillRect(0, 0, width, height);

	// the done part
	g.setColour(juce::Colours::lightsalmon);
	if (progress > 0.69F)
	{
		g.setColour(juce::Colours::white);
	}
	if (progress < 0.31F)
	{
		g.setColour(juce::Colours::orangered);
	}
	if (progress < 0.16F)
	{
		g.setColour(juce::Colours::red);
	}
	g.fillRect(0, 0, width * progress, height);

	// border
	g.setColour(juce::Colours::black);
	g.drawRect(0, 0, width, height);
}
