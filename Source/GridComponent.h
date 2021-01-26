/*
  ==============================================================================

	GridComponent.h
	Created: 21 Jan 2021 10:11:20pm
	Author:  kocia

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ButtonImage.h"

//==============================================================================
/*
*/
class GridComponent : public juce::Component
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="GridComponent"/> class with default amount of rows and columns set to 1.
	/// </summary>
	/// <param name="mgrP">The Calculation Manager object pointer that will get propagated down to all buttons in this grid.</param>
	GridComponent(std::shared_ptr<CalculationManager> mgrP);
	~GridComponent() override;

	/// <summary>
	/// Adds new grid item to the grid. If this item has the same image (same path) as a different item already
	/// present, then it gets added again.
	/// </summary>
	/// <param name="absoluteImagePath">The absolute image path.</param>
	void addGridItem(const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath, ButtonType type);

	/// <summary>
	/// Removes the grid item. If the same item (same path) is already present, both will be deleted.
	/// </summary>
	/// <param name="globalImagePath">The absolute image path.</param>
	void removeGridItem(const juce::String globalImagePath);

	/// <summary>
	/// Gets the first gridItem with this specified Button type.
	/// </summary>
	/// <param name="type">The type.</param>
	/// <returns></returns>
	MyIMageButton& getGridItem(ButtonType type);

	/// <summary>
	/// Sets the proportions of the grid.
	/// </summary>
	/// <param name="rows">The ammount of rows.</param>
	/// <param name="cols">The ammount of columns.</param>
	void setProportions(const unsigned int rows, const unsigned int cols);

	void paint(juce::Graphics&) override;
	void resized() override;

private:
	unsigned int rows;
	unsigned int cols;
	std::shared_ptr< CalculationManager> mgrP;
	std::vector<std::unique_ptr< MyIMageButton>> myArray;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GridComponent)
};
