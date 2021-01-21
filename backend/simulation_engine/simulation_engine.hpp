//
// Created by kira on 20.01.2021.
//

#ifndef NIRS_BACKEND_SIMULATION_ENGINE_SIMULATION_ENGINE_HPP_
#define NIRS_BACKEND_SIMULATION_ENGINE_SIMULATION_ENGINE_HPP_

#include "point.hpp"

#include <vector>

using Vector = Point<>;

struct PhysParams {
    struct UV {
        Point<> pose{};
        Vector thrust{};  // P
        double lift{};    // W
        double length{};
        double diameter{};
        double speed{};
    };

    struct Cable {
        double one_length{};
        double whole_length{};
        double diameter{};
        double lift{};
    };

    UV uv{};
    Cable cable{};
};

class SimulationEngine {
 public:
    explicit SimulationEngine(PhysParams phys_params);

    [[nodiscard]] std::vector<Point<>> points() const;

 private:

    std::vector<Point<>> points_;

    static constexpr double cn = 1.2;
    static constexpr double ct = 0.2;
    static constexpr double ro = 1025.0;
    static constexpr double c_drag = 0.22;
};

#endif //NIRS_BACKEND_SIMULATION_ENGINE_SIMULATION_ENGINE_HPP_
