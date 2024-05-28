project "Forge"
    kind "StaticLib"
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
        "Source",
        "Vendor/spdlog/include",
    }

    filter "system:windows"
        systemversion "latest"

        defines 
        {
            "FG_PLATFORM_WINDOWS",
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