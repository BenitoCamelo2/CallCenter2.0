cmake_minimum_required(VERSION 3.21)
project(Programa)

set(CMAKE_CXX_STANDARD 14)

add_executable(Programa main.cpp MainMenu.cpp MainMenu.h AgentMenu.cpp AgentMenu.h ClientMenu.cpp ClientMenu.h AgentList.cpp AgentList.h AgentNode.cpp AgentNode.h Agent.cpp Agent.h Name.cpp Name.h Time.cpp Time.h Date.cpp Date.h AgentNodeException.cpp AgentNodeException.h ClientList.cpp ClientList.h ClientNode.cpp ClientNode.h Client.cpp Client.h ListException.h util.h)
