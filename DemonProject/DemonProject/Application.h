#pragma once
#include "DemonSpawner.h"
#include "DemonDatabase.h"
#include <iostream>
#include "string"
#include "User.h"
class Application
{
public:
	enum class GameStates
	{
		RUNNING,
		EXIT
	};
public:
	Application();
	~Application();
	bool RunState(bool aRunState);
private:
	User user;
	DemonDatabase demonDatabase;
	DemonSpawner demonSpawner;
	GameStates gameState;
	bool menu;
	int input;

	std::string inputString0;
	bool inputBool;
	std::string inputString;
	std::string inputString1;
	bool inputBool1;

};

