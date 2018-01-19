workspace "HelloWorld"
    configurations { "debug", "release" }

project "HelloWorld"
    kind "ConsoleApp"
    language "C++"
    toolset "gcc"
    location "build/%{__ACTION}"

    links { "sfml-graphics", "sfml-window", "sfml-system" }
    files { "src/**.h", "src/**.cpp" }

    filter { "language:C++" and "toolset:gcc or clang" }
        buildoptions { "-std=c++17" }