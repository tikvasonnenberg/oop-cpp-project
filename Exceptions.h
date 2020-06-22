#pragma once
#include <iostream>
#include <exception>

class GeneralError :public std::exception
{
public:
	const char* what()const noexcept override {
		return "A general error has occurred, therfore the game can not be launched!";
	}
};
