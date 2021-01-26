/*
  ==============================================================================

	ProgressBarsComponent.h
	Created: 23 Jan 2021 8:19:28pm
	Author:  kocia

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MyLookAndFeel.h"

enum class ProgressBarType
{
	health,
	hunger,
	thirst,
	sleep,
};

//==============================================================================
/* Represents the component with Progress bars in our application.
*/
class ProgressBarsComponent : public juce::Component
{
public:
	ProgressBarsComponent();
	~ProgressBarsComponent() override;

	void decreaseIncrease(ProgressBarType type, bool increase);
	void paint(juce::Graphics&) override;
	void resized() override;

private:

	double progress1;
	juce::ProgressBar bar1;
	juce::Label label1;

	double progress2;
	juce::ProgressBar bar2;
	juce::Label label2;

	double progress3;
	juce::ProgressBar bar3;
	juce::Label label3;

	double progress4;
	juce::ProgressBar bar4;
	juce::Label label4;

	MyLookAndFeel look;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgressBarsComponent)
};
