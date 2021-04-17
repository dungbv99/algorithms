cmake_minimum_required(VERSION 3.19)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms kruskal.cpp prim.cpp primMinHeap.cpp icbus.cpp dijkstra.cpp topological.cpp boggle1.cpp graph/trie.cpp graph/boggle2.cpp graph/articulationPoint.cpp graph/test.cpp)