#pragma once
#include <map>
class InvManagement
{
	public:
		static InvManagement& get() {
			static InvManagement instance;
			return instance;
		}

		//failsave to stop copying
		InvManagement(const InvManagement&) = delete;
		void operator=(const InvManagement&) = delete;

		const enum products {
			wood,
			stone,
			iron,

			wheat,
			bread
		};

		int getStock(const products& product);
		void addToStock(const products& product, const int& amount);
		void removeFromStock(const products& product, const int& amount);

	private:
		std::map<products, float> inv;
		InvManagement() {}
};

