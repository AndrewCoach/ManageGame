/*
  ==============================================================================

	Calculation.h
	Created: 24 Jan 2021 8:56:56pm
	Author:  kocia

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PersonalityComponent.h"
#include "ProgressBarsComponent.h"

/// <summary>
/// Defines types of the button.
/// Different buttons have to tell the CalculationManager class in a callback, which ones they are.
/// </summary>
enum class ButtonType
{
	corn,
	cherries,
	bellPepper,
	harlic,
	radish,
	rawMeat,
	jam,
	berries,
	chickenDrumstick,
	mushroom,
	lilac,
	fish,
	redLilac,
	poisonousMushroom,
	bread,
	croissant,
	carrot,
	pudding,
	hotDogSausage,
	turnip,
	eggs,
	apple,
	sausages,
	drumstick,
	sandwich,
	spaghetti,
	pumpkin,
	vegeSoup,
	stuffedChicken,
	pear,
	strawberry,
	wheat,
	brocolli,
	peach,
	cheesecake,
	tomato,
	meal,
	peas,
	blackBerries,
	edamame,
	ham,
	olives,
	cucumber,
	donut,
	lolipop,
	pizza,
	cupcake,
};

//==============================================================================
/*
	This class takes care of calculating the current state of the app, and then informing the PersonalityComponent
	and the other visual elements to update to the correct determined state.
*/
class CalculationManager
{
public:
	CalculationManager(PersonalityComponent& personality, ProgressBarsComponent& progressBars);
	~CalculationManager();

	/// <summary>
	/// This method is a callback for all buttons from the game menu. Every button will upon clicking call this function,
	/// which will determine the sender by the sent in code, and update game state accordingly.
	/// </summary>
	/// <param name="sender">The sender Identifier.</param>
	void calculate(ButtonType sender, juce::Component* ptr);
private:
	PersonalityComponent& personalityC;
	ProgressBarsComponent& progressBarsC;
};
