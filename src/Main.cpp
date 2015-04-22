// =================================================================================
// Includes 
// =================================================================================
#include "Includes.h"
#include "GTALua.h"
#include "Memory/Memory.h"
#include "lua/Lua.h"
#include "ScriptBinds/ScriptBinds.h"

// =================================================================================
// Init 
// =================================================================================
GTALua::GTALua()
{
	// Attach Console
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout); 

	// Prepare Memory
	Memory::Init(); 
	GameMemory::Init();
}

// =================================================================================
// Init 
// This is called shortly before the game window is created
// At this point the exe is already unpacked, safe to do anything we want
// =================================================================================
void GTALua::ProperInit()
{
	// Debug
	printf("[GTALua] Initializing..\n");

	// Hooks & Patches
	GameMemory::InstallHooks();
	GameMemory::InstallPatches();

	// Initialize Lua
	lua = new LuaManager();
	lua->Init();

	// Script Binds
	ScriptBinds::ScriptEngine::Bind();
	ScriptBinds::ScriptThread::Bind();
	ScriptBinds::Console::Bind();
	ScriptBinds::BindBlockedFunction();

	// Include main.lua
	if (!lua->IncludeFile("GTALua/main.lua"))
		printf("fail\n");
}