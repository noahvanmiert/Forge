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
    }

    links
    {
        "GLFW",
        "opengl32.lib",
    }

    filter "system:windows"
        defines "FG_PLATFORM_WINDOWS"
        systemversion "latest"

    filter "configurations:Debug"
       defines "FG_DEBUG"
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines "FG_RELEASE"
       runtime "Release"
       symbols "On"
       optimize "On"