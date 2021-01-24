//
// Created by kira on 20.01.2021.
//

#include <iostream>

#include "simulation_engine.hpp"

SimulationEngine::SimulationEngine(PhysParams phys_params) {
    auto&[uv, cable] = phys_params;

    double R_x_drag = 0.125 * c_drag * ro * M_PI * std::pow(uv.diameter, 2) * std::pow(uv.speed, 2);
    Vector R{
        uv.thrust.x() - R_x_drag,
        uv.thrust.y() - uv.lift
    };
    Point p{};

    size_t N = phys_params.cable.whole_length / phys_params.cable.one_length;

    double precalculated = cable.one_length * cable.diameter * ro;
    double cable_lift = cable.lift * cable.one_length;
    for (size_t i = 0; i != N; ++i) {
        points_.push_back(p);
        double sin_phi = R.sin();
        double cos_phi = R.cos();
        double speed_n = sin_phi * uv.speed;
        double speed_t = cos_phi * uv.speed;
        double R_prev_n = 0.5 * cn * precalculated * std::pow(speed_n, 2);
        double R_prev_t = 0.5 * ct * M_PI * precalculated * std::pow(speed_t, 2);
        double R_delta_magnitude = R.magnitude() - R_prev_t;
        R = {
            R_delta_magnitude * cos_phi - R_prev_n * sin_phi,
            R_delta_magnitude * sin_phi + R_prev_n * cos_phi - cable_lift
        };
        Vector delta = R.scale(cable.one_length);
        p -= delta;
        std::cout << "R: { " << R.format() << " }" << std::endl;
        std::cout << "p: { " << p.format() << " }" << std::endl;
    }
}

std::vector<Point<>> SimulationEngine::points() const {
    return points_;
}
