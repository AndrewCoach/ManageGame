/*
  ==============================================================================

	GridComponent.cpp
	Created: 21 Jan 2021 10:11:20pm
	Author:  kocia

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GridComponent.h"

using Track = juce::Grid::TrackInfo;
using Fr = juce::Grid::Fr;

//==============================================================================
GridComponent::GridComponent(std::shared_ptr< CalculationManager> mgr) :
	rows(1), cols(1),
	mgrP(mgr)
{
}

GridComponent::~GridComponent()
{
}

void GridComponent::addGridItem(const juce::String absoluteImagePath, const juce::String absoluteImageOnHoverPath, ButtonType type)
{
	std::unique_ptr< MyIMageButton> temp;
	temp.reset(new MyIMageButton(
		this->mgrP, absoluteImagePath, absoluteImageOnHoverPath, type));

	this->myArray.push_back(std::move(temp));

	for (auto it = this->myArray.begin(); it != this->myArray.end(); ++it)
	{
		if (it->get()->getImagePath() == absoluteImagePath)
		{
			this->addAndMakeVisible(it->get());
		}
	}
}

void GridComponent::removeGridItem(const juce::String globalPath)
{
	for (auto it = this->myArray.begin(); it != this->myArray.end(); ++it)
	{
		if (it->get()->getImagePath() == globalPath)
		{
			this->myArray.erase(it);
			this->childrenChanged();
		}
	}
}

MyIMageButton& GridComponent::getGridItem(ButtonType type)
{
	for (auto it = this->myArray.begin(); it != this->myArray.end(); ++it)
	{
		if (it->get()->getButtonType() == type)
		{
			return *it->get();
		}
	}
}

void GridComponent::setProportions(const unsigned int rows, const unsigned int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->repaint();
}

void GridComponent::paint(juce::Graphics& g)
{
	juce::Grid grid;

	for (int i = 0; i < this->rows; ++i)
	{
		grid.templateRows.add(Track(Fr(1)));
	}
	for (int i = 0; i < this->cols; ++i)
	{
		grid.templateColumns.add(Track(Fr(1)));
	}

	std::for_each(this->myArray.begin(), this->myArray.end(),
		[&](std::unique_ptr<MyIMageButton>& elem)
		{
			grid.items.add(juce::GridItem(elem.get()));
		});

	grid.performLayout(getLocalBounds());
}

void GridComponent::resized()
{
	juce::Grid grid;

	for (int i = 0; i < this->rows; ++i)
	{
		grid.templateRows.add(Track(Fr(1)));
	}
	for (int i = 0; i < this->cols; ++i)
	{
		grid.templateColumns.add(Track(Fr(1)));
	}

	std::for_each(this->myArray.begin(), this->myArray.end(),
		[&](std::unique_ptr<MyIMageButton>& elem)
		{
			grid.items.add(juce::GridItem(elem.get()));
		});

	grid.performLayout(getLocalBounds());
}
