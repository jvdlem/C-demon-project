#include "Application.h"
#include "Input_Output.h"


Application::Application()
	:menu(true), input(0)
{
}

Application::~Application()
{
}


bool Application::RunState(bool aRunState)
{
	system("CLS");
	Input_Output io;
	io.FillColorVector();
	user.SetPermission();
	Demon* currentDemon;
	std::vector < std::string > tempDemonList;
	while (aRunState == true) {

		

		switch (user.GetPermission())
		{
		case 0:
			make:
			std::cout << "U are now going to make a Demon" << std::endl;

			inputString0 = io.AskInput("what name does your demon get?");
			inputBool = io.AskBool("do u want horns?", {"no","yes"});
			inputString = io.AskString("What eye colour should the demon have?",io.GetColorVector());
			inputString1 = io.AskString("What size should the demon be?", {"small","medium","large"});
			inputBool1 = io.AskBool("do u want Guns?", {"no", "yes"});

			demonDatabase.AddDemon(demonSpawner.CreateDemon(inputString0, inputBool, inputString, inputString1, inputBool1));
			system("CLS");
			input = io.AskInt("Do u want to proceed or abort", { "proceed", "abort" });
			switch (input)
			{
			case 0:

				break;
			case 1:

				RunState(true);
				break;
			}
			break;

		case 1:
		read:
			std::cout << "U are now going to look at all the Demons" << std::endl;
			tempDemonList.clear();
			for (int i = 0; i < demonDatabase.GetDemonArray().size(); i++) {
				std::cout << demonDatabase.GetDemonArray().at(i)->GetName() << std::endl;
				tempDemonList.push_back(demonDatabase.GetDemonArray().at(i)->GetName());
			}
			if (!tempDemonList.empty())
			{
				input = io.AskInt("which demon do u want to see?", tempDemonList);
				currentDemon = demonDatabase.().at(input);
				std::cout << "Name =\t " << currentDemon->GetName() << std::endl;
				std::cout << "Horns =\t " << currentDemon->GetHorns() << std::endl;
				std::cout << "Eyecolor =\t " << currentDemon->GetEyeColor() << std::endl;
				std::cout << "Size =\t " << currentDemon->GetSize() << std::endl;
				std::cout << "Weapons =\t " << currentDemon->GetWeapons() << std::endl;

				input = io.AskInt("Do u want to proceed or abort", { "proceed", "abort" });
			}
			else
			{
				std::cout << "there are currently no demons in your demon list. plz make a demon first" << std::endl;
				input = io.AskInt("Do u want to proceed or abort", { "proceed", "abort" });
			}

			switch (input)
			{
			case 0:

				break;
			case 1:

				RunState(true);
				break;
			}
			break;

		case 2:
			input = io.AskInt("Do u want to Make or read?", { "Make", "read" });
			{
				if (input == 0)
				{
					goto make;
				}
				else if(input == 1)
				{
					goto read;
				}
			}
			break;

		case 3:
			return false;
			break;
			menu = false;
		}
	}
}
