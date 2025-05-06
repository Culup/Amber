workspace "Amber"
	architecture "x64"
	startproject "sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 IncludeDir = {}
 IncludeDir["GLFW"] = "Amber/vendor/GLFW/include"

 include "Amber/vendor/GLFW"

project "Amber"
	location "Amber"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "abpch.h"
	pchsource "Amber/src/abpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	buildoptions {
		"/utf-8"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"AB_PLATFORM_WINDOWS",
			"AB_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "AB_DEBUG"
		staticruntime "Off"
		symbols "On"

	filter "configurations:Release"
		defines "AB_RELEASE"
		staticruntime "Off"
		optimize "On"

	filter "configurations:Dist"
		defines "AB_DIST"
		staticruntime "Off"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp" 
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Amber/vendor/spdlog/include",
		"Amber/src"
	}

	buildoptions {
		"/utf-8"
	}

	links
	{
		"Amber"
	}

	postbuildcommands
	{
		"{COPY} ../bin/" .. outputdir .. "/Amber/Amber.dll ../bin/" .. outputdir .. "/Sandbox"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"AB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AB_DEBUG"
		staticruntime "Off"
		symbols "On"

	filter "configurations:Release"
		defines "AB_RELEASE"
		staticruntime "Off"
		optimize "On"

	filter "configurations:Dist"
		defines "AB_DIST"
		staticruntime "Off"
		optimize "On"