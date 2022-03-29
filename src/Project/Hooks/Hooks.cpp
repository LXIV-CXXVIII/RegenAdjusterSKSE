#include "Hooks.h"

void Loki::Hooks::InstallActorUpdateHook() {

	REL::Relocation<std::uintptr_t> ActorUpdate{ REL::ID(36357) };

	auto& trampoline = SKSE::GetTrampoline();
	_ActorUpdateF = trampoline.write_call<5>(ActorUpdate.address() + 0x6D3, ActorUpdateF);

}