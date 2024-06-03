workspace "Forge"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Sandbox"


SolutionDir = path.getabsolute(".")
OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to solution directory
IncludeDir = {}
IncludeDir["GLFW"] = "Forge/Vendor/GLFW/include"
IncludeDir["Glad"] = "Forge/Vendor/glad/include"


group "Core"
    include "Forge/BuildCore.lua"
group ""

group "Dependencies"
    include "Forge/Vendor/GLFW/BuildGLFW.lua"
    include "Forge/Vendor/glad/BuildGlad.lua"
group ""

include "Sandbox/BuildSandbox.lua"