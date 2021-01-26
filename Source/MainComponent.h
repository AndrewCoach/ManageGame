#pragma once

#include <JuceHeader.h>
#include "PngComponent.h"
#include "BehaviorComponent.h"
#include "PersonalityComponent.h"
#include "TabComponent.h"
#include "GridComponent.h"
#include "ProgressBarsComponent.h"
#include "ButtonImage.h"

//==============================================================================
/*
	This component lives inside our window, and this is where you should put all
	your controls and content.
*/
class MainComponent : public juce::Component
{
public:
	//==============================================================================
	MainComponent();
	~MainComponent() override;

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

private:
	std::unique_ptr<BehaviorComponent> ptr;
	PersonalityComponent personalityComponent;
	std::shared_ptr< CalculationManager> mgrP;
	GridComponent myGrid;
	GridComponent myGrid2;
	TabComponent myTab;
	ProgressBarsComponent progressBars;

	// the look and feel
	juce::LookAndFeel_V4 look1;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
