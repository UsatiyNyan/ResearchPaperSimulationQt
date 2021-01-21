add_library(simulation_engine STATIC
        simulation_engine/simulation_engine.cpp
        )
target_include_directories(simulation_engine PUBLIC
        simulation_engine)
