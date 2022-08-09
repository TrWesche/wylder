project "Glad"
  kind "StaticLib"
  language "C"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bit-int/" ..outputdir .. "/%{prj.name}")

files {
  "include/Glad/glad.h",
  "include/KHR/khrplatform.h",
  "src/glad.c"
}

includedirs {
	"include"
}

filter "system:linux"
  pic "On"

  systemversion "latest"
  staticruntime "On"



filter "system:windows" 
  systemversion "latest"
  staticruntime "On"


filter "configurations:Debug"
  runtime "Debug"
  symbols "on"

filter "configurations:Release"
  runtime "Release"
  optimize "on"
