/*
  ==============================================================================

	BehaviorComponent.h
	Created: 18 Jan 2021 4:20:03pm
	Author:  kocia

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PngComponent.h"
//==============================================================================
/* This component encapsulates multiple PngComponent object, it stores these in a vector.
*/
class BehaviorComponent : public juce::Component
{
public:
	BehaviorComponent();
	~BehaviorComponent() override;

	/// <summary>
	/// Adds a PngComponent with the image specified by path.
	/// </summary>
	/// <param name="absoluteImagePath">The absolute image path.</param>
	void addImage(const juce::String absoluteImagePath);

	/// <summary>
	/// Removes a PngComponent with the image specified by path.
	/// </summary>
	/// <param name="absoluteImagePath">The absolute image path.</param>
	void removeImage(const juce::String absoluteImagePath);

	/// <summary>
	/// Changes the amount of PngComponents to loop through. Most common is 2 or 3.
	/// If the supplied number is higher than the amount of images contained, nothing will happen.
	/// </summary>
	/// <param name="imageCount">The image count. Default value is 1.</param>
	void changeCycleCount(const unsigned int imageCount);

	/// <summary>
	/// Changes the cycle speed in miliseconds, that is, how quickly the image changes to the next one.
	/// </summary>
	/// <param name="miliseconds">The miliseconds.</param>
	void changeCycleSpeed(const unsigned int miliseconds);

	/// <summary>
	/// Is called externally every X amount of miliseconds, and will move to the next correct image and display it.
	/// </summary>
	/// <param name="miliseconds">The miliseconds.</param>
	void displayImage();

	void paint(juce::Graphics&) override;
	void resized() override;

private:
	std::vector<PngComponent> imageVector;
	unsigned int vectorPosition;
	unsigned int cycleCount;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BehaviorComponent)
};
