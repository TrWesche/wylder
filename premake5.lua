workspace "Wylder"
	architecture "x64"
	configurations ({ "Debug", "Release", "Dist" })

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wylder"
	location "Wylder"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{wks.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"WY_PLATFORM_WINDOWS",
			"WY_BUILD_DLL"
		}

	postbuildcommands {
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}


	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"


	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "HZ_DIST"
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
		staticruntime "On"
		systemversion "latest"

		defines{
			"WY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"


	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"