#ifndef SIMULATION_WIDGET_H
#define SIMULATION_WIDGET_H

#include <QWidget>

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

    Ui::SimulationWidget *ui_;
    std::optional<SimulationEngine> engine_{};
};

#endif // SIMULATION_WIDGET_H
