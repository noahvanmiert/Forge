workspace "Forge"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Sandbox"

    filter "system:windows"
        buildoptions { 
           "/EHsc",
           "/Zc:preprocessor",
           "/Zc:__cplusplus" 
        }
        
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Forge"
    location "Forge"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files { 
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp",
    }

    includedirs {
        "%{prj.name}/Source"
    }

    filter "system:windows"
       systemversion "latest"
       defines {
            "FG_PLATFORM_WINDOWS"
        }

   filter "configurations:Debug"
       defines { "FG_DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "FG_RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp",
    }

    includedirs {
        "Forge/Source"
    }

    links {
        "Forge"
    }

    filter "system:windows"
		systemversion "latest"
		defines {
			"FG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HR_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines "HR_Release"
		optimize "On"
		runtime "Release"