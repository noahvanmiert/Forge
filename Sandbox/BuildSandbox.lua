project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir (SolutionDir .. "/Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir (SolutionDir .. "/Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

    files 
    {
        "Source/**.h",
        "Source/**.cpp",
    }

    includedirs 
    {
        SolutionDir .. "/Forge/Source",
        SolutionDir .. "/Forge/Vendor/spdlog/include",
    }

    links 
    {
        "Forge"
    }

    filter "system:windows"
		defines "FG_PLATFORM_WINDOWS"
		systemversion "latest"

	filter "configurations:Debug"
        defines "FG_DEBUG"
		symbols "On"
		runtime "Debug"
  
	filter "configurations:Release"
        defines "FG_RELEASE"
		optimize "On"
		runtime "Release"