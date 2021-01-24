#include "simulation_widget.h"
#include "ui_simulation_widget.h"

#include <memory>
#include <QPainter>
#include <QDebug>

SimulationWidget::SimulationWidget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::SimulationWidget) {
    ui_->setupUi(this);
}

SimulationWidget::~SimulationWidget() {
    delete ui_;
}

void SimulationWidget::paintEvent(QPaintEvent *) {
    if (not engine_) {
        return;
    }

    auto painter = std::make_unique<QPainter>(this);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->save();
    painter->translate(width() / 2, height() / 2);
    painter->setBrush(Qt::black);
    painter->setPen(QPen(Qt::black, 4));

    std::vector<QPointF> pts;
    for (auto &p: engine_->points()) {
        pts.emplace_back(p.x(), p.y());
    }

    painter->translate(-pts.back().x(), -pts.back().y());
    painter->drawPolyline(pts.data(), pts.size());

    emit uv_pose(QString::number(-pts.back().x()),
                 QString::number(-pts.back().y()));

    painter->restore();
}

void SimulationWidget::update_engine(const PhysParams &phys_params) {
    engine_ = SimulationEngine{phys_params};
    update();
}
