#pragma once
#include "Project/RegenAdjuster.h"

namespace Loki {

	class Hooks : protected RegenAdjuster {
	
	public:
		Hooks() {
		}
		virtual ~Hooks() {
		}
		static void InstallActorUpdateHook();

	private:

	protected:
	
	};

};