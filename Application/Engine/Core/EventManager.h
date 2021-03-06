#pragma once
#include "Singleton.h"
#include <string>
#include <map>
#include <list>
#include <functional>

namespace nc
{
	class Object;

	struct Event
	{
		std::string type;
		Object* sender;
		Object* receiver;
		void* data;
	};

	class EventManager : public Singleton<EventManager>
	{
	public:
		// struct stuff
		using function_t = std::function<void(const Event&)>;

		struct Observer
		{
			function_t function;
			Object* owner{ nullptr };
		};

	public:
		// functions

		void Subscribe(const std::string& type, function_t function, Object* owner = nullptr);
		void Notify(const Event& event);

	private:
		//data smata

		std::map < std::string, std::list<Observer>> m_observers;


	};
}