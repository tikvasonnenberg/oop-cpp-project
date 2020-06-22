#include "Factory.h"


Factory::Factory()
{
}

std::unique_ptr<GameItem> Factory::create(const std::string& name, sf::Vector2f position) {
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second(position);
}

bool Factory::Register(const std::string& name, m_function func) {// std::unique_ptr<Object>(*f)()) {
	getMap().emplace(name, func);
	return true;
}
//Factory::~Factory()
//{
//}
