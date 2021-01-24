#ifndef SIMULATION_WIDGET_H
#define SIMULATION_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <memory>

#include "simulation_engine.hpp"

namespace Ui {
class SimulationWidget;
}

class SimulationWidget : public QWidget {
 Q_OBJECT

 public:

    explicit SimulationWidget(QWidget *parent = nullptr);

    ~SimulationWidget() override;

    void update_engine(const PhysParams &phys_params);

 signals:

    void uv_pose(const QString &x, const QString &y);

 protected:

    void paintEvent(QPaintEvent *e) override;

 private:

    void scale(Point<> reference_point);
    void draw_water(const std::unique_ptr<QPainter> &painter) const;
    void draw_ship(const std::unique_ptr<QPainter> &painter) const;
    void draw_cells(const std::unique_ptr<QPainter> &painter) const;
    void draw_uv(const std::unique_ptr<QPainter> &painter) const;

 private:

    Ui::SimulationWidget *ui_;
    std::optional<SimulationEngine> engine_{};
    double scale_{1};
};

#endif // SIMULATION_WIDGET_H
