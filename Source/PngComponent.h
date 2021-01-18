/*
  ==============================================================================

	PngComponent.h
	Created: 18 Jan 2021 3:03:53pm
	Author:  kocia

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
* This component encapsulates a PNG image, essentially is a ImageComponent and as such can be displayed like a Component.
*/
class PngComponent : public juce::Component
{
public:
	PngComponent(const juce::String absoluteImagePath);
	~PngComponent() override;

	void paint(juce::Graphics&) override;
	void resized() override;

	/// <summary>
	/// Changes the underlying image.
	/// </summary>
	/// <param name="absoluteImagePath">The absolute image path.</param>
	void changeImage(const juce::String absoluteImagePath);

private:
	juce::File pFile;
	std::unique_ptr<juce::FileInputStream> pStream;
	juce::PNGImageFormat pImageFormat;
	juce::Image pImage;
	juce::ImageComponent pImageComponent;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PngComponent)
};
