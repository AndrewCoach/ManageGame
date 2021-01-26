/*
  ==============================================================================

	MyLookAndFeel.h
	Created: 23 Jan 2021 9:00:12pm
	Author:  kocia

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class MyLookAndFeel : public juce::LookAndFeel_V4
{
public:
	MyLookAndFeel();
	~MyLookAndFeel();

	void drawProgressBar(juce::Graphics&, juce::ProgressBar&, int width, int height, double progress, const juce::String& textToShow) override;

private:
};
