workspace "HelloWorld"
    configurations { "debug", "release" }

project "HelloWorld"
    kind "ConsoleApp"
    language "C++"
    location "build/%{__ACTION}"

    links { "sfml-graphics", "sfml-window", "sfml-system" }
    files { "src/**.h", "src/**.cpp" }

    filter { "language:C++" }
        buildoptions { "-std=c++17" }