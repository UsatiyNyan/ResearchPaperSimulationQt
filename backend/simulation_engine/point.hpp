//
// Created by kira on 20.01.2021.
//

#ifndef NIRS_BACKEND_SIMULATION_ENGINE_POINT_HPP_
#define NIRS_BACKEND_SIMULATION_ENGINE_POINT_HPP_

#include <cmath>
#include <string>

template <class T = double>
class Point : public std::pair<T, T> {
 public:
    using std::pair<T, T>::pair;
    T x() const {
        return this->first;
    }
    T y() const {
        return this->second;
    }

    [[nodiscard]] Point operator-(const Point& other) const {
        return Point{this->first - other.first, this->second - other.second};
    }

    [[nodiscard]] Point operator+(const Point& other) const {
        return Point{this->first + other.first, this->second + other.second};
    }

    Point &operator-=(const Point &other) {
        this->first -= other.first;
        this->second -= other.second;
        return *this;
    }

    Point &operator+=(const Point &other) {
        this->first += other.first;
        this->second += other.second;
        return *this;
    }

    [[nodiscard]] Point scale(T scale) const {
        return {this->cos() * scale, this->sin() * scale};
    }

    [[nodiscard]] double cos() const {
        return x() / magnitude();
    }

    [[nodiscard]] double sin() const {
        return y() / magnitude();
    }

    [[nodiscard]] double magnitude() const {
        return std::sqrt(x() * x() + y() * y());
    }

    [[nodiscard]] std::string format() const {
        return "x: " + std::to_string(x()) + " |y: " + std::to_string(y());
    }
};

#endif //NIRS_BACKEND_SIMULATION_ENGINE_POINT_HPP_
