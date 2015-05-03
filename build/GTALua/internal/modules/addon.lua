-- Addons
addon = {}
addon.AddonTable = {}

-- Load Addon
function addon.Load(name)
	-- TODO: Add error handling, version checking, etc.
	-- TODO: Config files
	include("../../addons/"..name.."/main.lua")
	
	-- Game Pause
	if IsScriptEngineInitialized() and game.IsPaused() then
		print("Note: Game is paused. Script Thread will reset after you unpaused it!")
	end
end