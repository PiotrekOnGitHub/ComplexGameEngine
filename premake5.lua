workspace "ComplexGameEngine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ComplexGameEngine"
	location "ComplexGameEngine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/libs/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"CE_PLATFORM_WINDOWS",
			"CE_BUILD_DLL",
			"_DEBUG",
			"_CONSOLE"
		}

		postbuildcommands {
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}
	filter "configurations:Debug"
		defines "COMPLEX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "COMPLEX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "COMPLEX_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"ComplexGameEngine/libs/spdlog/include",
		"ComplexGameEngine/src"
	}

	links {
		"ComplexGameEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"CE_PLATFORM_WINDOWS",
			"_DEBUG",
			"_CONSOLE"
		}

	filter "configurations:Debug"
		defines "COMPLEX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "COMPLEX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "COMPLEX_DIST"
		optimize "On"
