/*
  ==============================================================================

	TabComponent.h
	Created: 21 Jan 2021 8:20:44pm
	Author:  kocia

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "GridComponent.h"
//==============================================================================
/* Contains a tabbedComponent and a Component full of imageButtons and other things for each Tab.
*/
class TabComponent : public juce::Component
{
public:
	TabComponent();
	~TabComponent() override;

	/// <summary>
	/// Adds the tab to the Tab bar. The component is accepted by reference, and so it is important that it stays in scope (alive)
	/// for the whole duration of the app.
	/// </summary>
	/// <param name="componentToShow">The component to show.</param>
	/// <param name="text">The text displayed in the tab.</param>
	/// <param name="bgColour">The background colour of the tab.</param>
	void addTab(juce::Component& componentToShow, juce::String text, juce::Colour bgColour);

	/// <summary>
	/// Removes one of the tabs by its index, starts at 0;
	/// </summary>
	/// <param name="tabIndex">Index of the tab from 0.</param>
	void removeTab(const unsigned int tabIndex);
	void paint(juce::Graphics&) override;
	void resized() override;

private:
	juce::TabbedComponent tab;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TabComponent)
};
