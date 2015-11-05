#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 3.4)
#Name your project here
project(gbXMLIO)

add_executable(gbXMLIO gbxmlIOCPP.cpp
                       stdafx.cpp
                       rapidxml.hpp
                       rapidxml_print.hpp)