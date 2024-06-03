project "Forge"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir (SolutionDir .. "/Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir (SolutionDir .. "/Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")
    
    pchheader "fgpch.h"
    pchsource "Source/fgpch.cpp"

    files 
    { 
        "Source/**.h",
        "Source/**.cpp",
    }

    includedirs 
    {
        "Source",
        "Vendor/spdlog/include",

        SolutionDir .. "/%{IncludeDir.GLFW}",
        SolutionDir .. "/%{IncludeDir.Glad}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib",
    }

    filter "system:windows"
        systemversion "latest"
        defines 
        {
            "FG_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE",
        }

    filter "configurations:Debug"
       defines "FG_DEBUG"
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines "FG_RELEASE"
       runtime "Release"
       symbols "On"
       optimize "On"