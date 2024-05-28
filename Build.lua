workspace "Forge"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Sandbox"

    filter "system:windows"
        buildoptions 
        { 
            "/EHsc",
            "/Zc:preprocessor",
            "/Zc:__cplusplus" 
        }
        

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


group "Core"
    include "Forge/BuildCore.lua"
group ""

include "/Sandbox/BuildSandbox.lua"