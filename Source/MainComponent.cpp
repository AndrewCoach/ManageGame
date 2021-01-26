#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : ptr(new BehaviorComponent(juce::File::getCurrentWorkingDirectory().getFullPathName() + juce::String("\\Textures\\food\\icon (1).png"))),
personalityComponent(BehaviorType::happy, std::move(ptr)),
mgrP(new CalculationManager(this->personalityComponent, this->progressBars)),
myGrid(mgrP), myGrid2(mgrP)
{
	// Setting the basic things
	this->setSize(700, 400);
	this->setLookAndFeel(&this->look1);
	this->addAndMakeVisible(this->myTab);
	this->addAndMakeVisible(this->personalityComponent);
	this->addAndMakeVisible(this->progressBars);

	// FOOD TAB SETUP - 47 ITEMS
	for (int i = 1; i < 48; ++i)
	{
		this->myGrid.addGridItem
		(
			juce::File::getCurrentWorkingDirectory().getFullPathName() + juce::String("\\Textures\\food\\icon (") + juce::String(i) + juce::String(").png"),
			juce::File::getCurrentWorkingDirectory().getFullPathName() + juce::String("\\Textures\\food\\icon (") + juce::String(i) + juce::String(").png"),
			(ButtonType)int(i - 1)
		);
	}

	// DRINK TAB SETUP - 20 ITEMS
	for (int i = 1; i < 21; ++i)
	{
		this->myGrid2.addGridItem
		(
			juce::File::getCurrentWorkingDirectory().getFullPathName() + juce::String("\\Textures\\drink\\icon (") + juce::String(i) + juce::String(").png"),
			juce::File::getCurrentWorkingDirectory().getFullPathName() + juce::String("\\Textures\\drink\\icon (") + juce::String(i) + juce::String(").png"),
			(ButtonType) int(i + 46)
		);
	}

	// Setting grids proportions
	this->myGrid.setProportions(5, 10);
	this->myGrid2.setProportions(5, 10);

	// add both grids to the tab
	this->myTab.addTab(this->myGrid, "Food", juce::Colours::lightgrey);
	this->myTab.addTab(this->myGrid2, "Drink", juce::Colours::darkgrey);

	// putting BehaviorComponents (only 1 for now) into PersonalityComponent
	std::unique_ptr<BehaviorComponent> ptr2;
	ptr2.reset(new BehaviorComponent(juce::File::getCurrentWorkingDirectory().getFullPathName() + juce::String("\\Textures\\food\\icon (2).png")));
	ptr2.get()->addImage(juce::File::getCurrentWorkingDirectory().getFullPathName() + juce::String("\\Textures\\food\\icon (3).png"));
	ptr2.get()->changeCycleCount(2);
	this->personalityComponent.addBehavior(BehaviorType::hungry, std::move(ptr2));

	// Persistent thread to call rendering of personalitycomponent every x miliseconds
	juce::Thread::launch([&]()
		{
			while (true)
			{
				juce::Thread::getCurrentThread()->wait(200);
				const juce::MessageManagerLock mmLock;
				std::mutex lock;
				lock.lock();
				this->personalityComponent.displayBehavior();
				lock.unlock();
			}
		}
	);

	// thread to call test methods
	//juce::Thread::launch([&]()
	//	{
	//		while (true)
	//		{
	//			juce::Thread::getCurrentThread()->wait(4000);
	//			const juce::MessageManagerLock mmLock;
	//			std::mutex lock;
	//			lock.lock();
	//			//this->personalityComponent.switchBehavior(BehaviorType::hungry);
	//			this->myGrid.getGridItem(ButtonType::chocolate).changeImages
	//			(
	//				"E:\\GITHUB repositories\\ManageGame\\ManageGame\\IMAGES\\1_noshadow\\40.png",
	//				"E:\\GITHUB repositories\\ManageGame\\ManageGame\\IMAGES\\1_shadow\\40.png",
	//				ButtonType::milk
	//			);
	//			lock.unlock();
	//		}
	//	}
	//);
}

MainComponent::~MainComponent()
{
	this->setLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
}

void MainComponent::resized()
{
	auto bounds = this->getLocalBounds();
	auto topBounds = bounds.removeFromTop(bounds.getHeight() / 2);
	this->personalityComponent.setBounds(topBounds);
	auto bottomLeftBounds = bounds.removeFromLeft(bounds.getWidth() / 1.7F);
	this->myTab.setBounds(bottomLeftBounds);
	this->progressBars.setBounds(bounds);
}
