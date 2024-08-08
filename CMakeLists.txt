cmake_minimum_required(VERSION 3.28)
project(Uniform_sample_generator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Uniform_sample_generator main.cpp
        Uniform_sample_generator.C
        addParticle.C
        Generate_uniform_event.C
        Run.cpp
        BoolToString.C
        DisplyText.C)
