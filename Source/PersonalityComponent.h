/*
  ==============================================================================

	PersonalityComponent.h
	Created: 19 Jan 2021 11:30:39pm
	Author:  kocia

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "BehaviorComponent.h"

/// <summary>
/// This enum holds the different behavior types, that can be supplied to PersonalityComponent.
/// We supply the correct type of the enum to the switchBeavior() method to control which behavior is shown.
/// </summary>
enum class BehaviorType
{
	happy,
	hungry,
	wild,
};

//==============================================================================
/* Encompasses a multitude of BehaviorComponents and represents a personality. It controls, which image from which behavior is displayed.
*/
class PersonalityComponent : public juce::Component
{
public:
	PersonalityComponent(BehaviorType defaultType, std::unique_ptr<BehaviorComponent> defaultBehavior);
	~PersonalityComponent() override;

	/// <summary>
	/// Adds the behavior to a list of behaviors this component can display.
	/// </summary>
	/// <param name="behavior">The behavior.</param>
	void addBehavior(BehaviorType defaultType, std::unique_ptr<BehaviorComponent> defaultBehavior);

	/// <summary>
	/// Removes the behavior from this component.
	/// </summary>
	/// <param name="behaviorType">Type of the behavior.</param>
	void removeBehavior(BehaviorType behaviorType);

	/// <summary>
	/// This method is called periodically from the outside to display a different image belonging
	/// to a behavior currently set up to be shown with switchBehavior() every time, it is called.
	/// It is advised to make sure that this method cannot be called at
	/// the same time as the switchBehavior() method, maybe from different threads.
	/// This could cause problems and a use of mutexes before calling both methods is advised.
	/// </summary>
	void displayBehavior();

	/// <summary>
	/// Switches the displayed images belonging to the supplied behavior. Every time the displayBehavior() method is called, this behavior
	/// will now be displayed.
	/// </summary>
	/// <param name="behaviorType">ENUM - Type of the behavior.</param>
	void switchBehavior(BehaviorType behaviorType);

	void paint(juce::Graphics&) override;
	void resized() override;

private:
	std::map<BehaviorType, std::unique_ptr<BehaviorComponent>> behaviorMap;
	BehaviorType chosenType;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PersonalityComponent)
};
