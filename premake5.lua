-- premake5.lua
workspace "WMML"
configurations {"Debug", "Release"}
platforms {
    "Static_x86",
    "Static_x64",
    "UnitTest_x86",
    "UnitTest_x64"
}

project "WMML"
    kind "StaticLib"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    cppdialect "C++17"

    files {"**.h", "**.cpp", "**.cc", "**.inl"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"

    filter "platforms:Static_x86"
        kind "SharedLib"
        architecture "x86"

    filter "platforms:Static_x64"
        kind "SharedLib"
        architecture "x86_64"

    filter "platforms:UnitTest_x86"
		kind "ConsoleApp"
		architecture "x86"
		defines {"UNIT_TEST_ENABLED"}

    filter "platforms:UnitTest_x64"
		kind "ConsoleApp"
		architecture "x86_64"
		defines {"UNIT_TEST_ENABLED"}