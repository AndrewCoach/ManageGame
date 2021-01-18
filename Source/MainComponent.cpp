#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : pngComponent("E:\\GITHUB repositories\\ManageGame\\ManageGame\\defect4.png")
{
	this->setSize(600, 400);
	this->addAndMakeVisible(pngComponent);

	this->pngComponent.changeImage("E:\\GITHUB repositories\\ManageGame\\ManageGame\\ukol.png");

	juce::Thread::launch([&]()
		{
			bool b = 0;
			while (true)
			{
				juce::Thread::getCurrentThread()->wait(2000);
				const juce::MessageManagerLock mmLock;

				if (b == 0)
					this->pngComponent.changeImage("E:\\GITHUB repositories\\ManageGame\\ManageGame\\ukol.png");
				else
					this->pngComponent.changeImage("E:\\GITHUB repositories\\ManageGame\\ManageGame\\defect4.png");
				b = !b;
			}
		}
	);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
}

void MainComponent::resized()
{
	this->pngComponent.setBounds(getLocalBounds());
}
