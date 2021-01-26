/*
  ==============================================================================

	Calculation.cpp
	Created: 24 Jan 2021 8:56:56pm
	Author:  kocia

  ==============================================================================
*/

#include "Calculation.h"

CalculationManager::CalculationManager(PersonalityComponent& personality, ProgressBarsComponent& progressBars) :
	personalityC(personality), progressBarsC(progressBars)
{
}

CalculationManager::~CalculationManager()
{
}

void CalculationManager::calculate(ButtonType sender, juce::Component* ptr)
{
	switch (sender)
	{
	case ButtonType::apple:
		this->progressBarsC.decreaseIncrease(ProgressBarType::health, true);
		this->progressBarsC.decreaseIncrease(ProgressBarType::health, true);
		this->progressBarsC.decreaseIncrease(ProgressBarType::health, true);
		this->progressBarsC.decreaseIncrease(ProgressBarType::health, true);
		this->personalityC.switchBehavior(BehaviorType::hungry);
		break;

	case ButtonType::bellPepper:
		this->progressBarsC.decreaseIncrease(ProgressBarType::hunger, true);
		this->progressBarsC.decreaseIncrease(ProgressBarType::hunger, true);
		this->progressBarsC.decreaseIncrease(ProgressBarType::hunger, true);
		this->progressBarsC.decreaseIncrease(ProgressBarType::hunger, true);
		this->personalityC.switchBehavior(BehaviorType::happy);
		break;

	case ButtonType::berries:
		this->progressBarsC.decreaseIncrease(ProgressBarType::sleep, false);
		this->progressBarsC.decreaseIncrease(ProgressBarType::sleep, false);
		this->progressBarsC.decreaseIncrease(ProgressBarType::sleep, false);
		this->progressBarsC.decreaseIncrease(ProgressBarType::sleep, false);
		this->personalityC.switchBehavior(BehaviorType::hungry);
		break;
	default:
		break;
	}
}
