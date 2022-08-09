workspace "Wylder"
	architecture "x64"
	configurations ({ "Debug", "Release", "Dist" })

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Create a Struct which will hold all of the include directories.  Simplifies file complexity by concentrating all of the includes in a single space in the file.
IncludeDir = {}
IncludeDir["GLFW"] = "Wylder/vendor/GLFW/include"
IncludeDir["Glad"] = "Wylder/vendor/Glad/include"

-- This tells premake to search these directories for additional premake5.lua files to process.
include "Wylder/vendor/GLFW"
include "Wylder/vendor/Glad"

project "Wylder"
	location "Wylder"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "wypch.h"
	pchsource "Wylder/src/wypch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{wks.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	-- Setup Project Dependencies
	links {
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines{
			"WY_PLATFORM_WINDOWS",
			"WY_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	postbuildcommands {
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}


	filter "configurations:Debug"
		defines "WY_DEBUG"
		defines "WY_ENABLE_ASSERTS"
		staticruntime "off"
		runtime "Debug"
		symbols "On"


	filter "configurations:Release"
		defines "WY_RELEASE"
		staticruntime "off"
		runtime "Release"
		optimize "On"


	filter "configurations:Dist"
		defines "WY_DIST"
		staticruntime "off"
		runtime "Release"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir (_WORKING_DIR .. "/bin/" .. outputdir .. "/%{prj.name}")
	objdir (_WORKING_DIR .. "/bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Wylder/vendor/spdlog/include",
		"Wylder/src"
	}

	links {
		"Wylder"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines{
			"WY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WY_DEBUG"
		defines "WY_ENABLE_ASSERTS"
		staticruntime "off"
		runtime "Debug"
		symbols "On"


	filter "configurations:Release"
		defines "WY_RELEASE"
		staticruntime "off"
		runtime "Release"
		optimize "On"


	filter "configurations:Dist"
		defines "WY_DIST"
		staticruntime "off"
		runtime "Release"
		optimize "On"