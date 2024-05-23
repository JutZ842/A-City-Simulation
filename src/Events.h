#pragma once
#include <string>
#include <iostream>

class Events {
	public:
		Events(const std::string& evN) : m_evName(evN) {}

		void virtual execute() = 0;
	private:
		std::string m_evName;
};
