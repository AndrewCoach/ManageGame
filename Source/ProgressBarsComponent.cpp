/*
  ==============================================================================

	ProgressBarsComponent.cpp
	Created: 23 Jan 2021 8:19:28pm
	Author:  kocia

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ProgressBarsComponent.h"

//==============================================================================
ProgressBarsComponent::ProgressBarsComponent() :
	progress1(1), bar1(progress1), label1("", "Health: "),
	progress2(1), bar2(progress2), label2("", "Happiness: "),
	progress3(1), bar3(progress3), label3("", "Hunger: "),
	progress4(1), bar4(progress4), label4("", "Thirst: ")
{
	this->addAndMakeVisible(bar1);
	this->addAndMakeVisible(bar2);
	this->addAndMakeVisible(bar3);
	this->addAndMakeVisible(bar4);

	this->setLookAndFeel(&this->look);

	this->progress1 = 0.1F;
	this->progress2 = 0.3F;
	this->progress3 = 0.7F;
	this->progress4 = 1.0F;

	this->addAndMakeVisible(label1);
	this->addAndMakeVisible(label2);
	this->addAndMakeVisible(label3);
	this->addAndMakeVisible(label4);

	this->label1.setJustificationType(juce::Justification::centredRight);
	this->label2.setJustificationType(juce::Justification::centredRight);
	this->label3.setJustificationType(juce::Justification::centredRight);
	this->label4.setJustificationType(juce::Justification::centredRight);
}

ProgressBarsComponent::~ProgressBarsComponent()
{
	this->setLookAndFeel(nullptr);
}

void ProgressBarsComponent::decreaseIncrease(ProgressBarType type, bool increase)
{
	switch (type)
	{
	case ProgressBarType::health:
		increase ? this->progress1 += 0.1F : this->progress1 -= 0.1F;
		if (this->progress1 > 1.0F)
			this->progress1 = 1.0F;
		if (this->progress1 < 0.0F)
			this->progress1 = 0.0F;
		break;

	case ProgressBarType::hunger:
		increase ? this->progress2 += 0.1F : this->progress2 -= 0.1F;
		if (this->progress2 > 1.0F)
			this->progress2 = 1.0F;
		if (this->progress2 < 0.0F)
			this->progress2 = 0.0F;
		break;
		break;

	case ProgressBarType::sleep:
		increase ? this->progress3 += 0.1F : this->progress3 -= 0.1F;
		if (this->progress3 > 1.0F)
			this->progress3 = 1.0F;
		if (this->progress3 < 0.0F)
			this->progress3 = 0.0F;
		break;
		break;

	case ProgressBarType::thirst:
		increase ? this->progress4 += 0.1F : this->progress4 -= 0.1F;
		if (this->progress4 > 1.0F)
			this->progress4 = 1.0F;
		if (this->progress4 < 0.0F)
			this->progress4 = 0.0F;
		break;
		break;

	default:
		break;
	}
	this->repaint();
}

void ProgressBarsComponent::paint(juce::Graphics& g)
{
}

void ProgressBarsComponent::resized()
{
	int gap = 20;
	int sideGap = 5;
	int numRows = 4;
	int labelWidth = 80;
	float barShaveoff = 0.28F;

	auto bounds = this->getLocalBounds();

	bounds.removeFromTop(gap);
	bounds.removeFromBottom(sideGap);
	bounds.removeFromRight(sideGap);
	bounds.removeFromLeft(sideGap);

	int rowHeight = bounds.getHeight() / numRows;

	auto row1 = bounds.removeFromTop(rowHeight);
	label1.setBounds(row1.removeFromLeft(labelWidth));

	row1.removeFromTop(rowHeight * barShaveoff);
	row1.removeFromBottom(rowHeight * barShaveoff);
	bar1.setBounds(row1);

	auto row2 = bounds.removeFromTop(rowHeight);
	label2.setBounds(row2.removeFromLeft(labelWidth));

	row2.removeFromTop(rowHeight * barShaveoff);
	row2.removeFromBottom(rowHeight * barShaveoff);
	bar2.setBounds(row2);

	auto row3 = bounds.removeFromTop(rowHeight);
	label3.setBounds(row3.removeFromLeft(labelWidth));

	row3.removeFromTop(rowHeight * barShaveoff);
	row3.removeFromBottom(rowHeight * barShaveoff);
	bar3.setBounds(row3);

	auto row4 = bounds.removeFromTop(rowHeight);
	label4.setBounds(row4.removeFromLeft(labelWidth));

	row4.removeFromTop(rowHeight * barShaveoff);
	row4.removeFromBottom(rowHeight * barShaveoff);
	bar4.setBounds(row4);
}
