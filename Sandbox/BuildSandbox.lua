project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("../Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("../Binaries/Intermediates/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "Source/**.h",
        "Source/**.cpp",
    }

    includedirs 
    {
        "../Forge/Source",
        "../Forge/Vendor/spdlog/include",
    }

    links 
    {
        "Forge"
    }

    filter "system:windows"
		systemversion "latest"
		defines 
        {
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
