#include "simulation_widget.h"
#include "ui_simulation_widget.h"

#include <memory>
#include <QPainter>

SimulationWidget::SimulationWidget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::SimulationWidget) {
    ui_->setupUi(this);
}

SimulationWidget::~SimulationWidget() {
    delete ui_;
}

void SimulationWidget::paintEvent(QPaintEvent *) {
    if (engine_) {
        auto painter = std::make_unique<QPainter>(this);
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->save();
        painter->translate(width() / 2, 0);
        painter->setBrush(QBrush{Qt::black, Qt::BrushStyle::Dense3Pattern});
        painter->setPen(QPen(Qt::black, 2));

        std::vector<QPointF> pts;
        for (auto &p: engine_->points()) {
            pts.emplace_back(p.x(), p.y());
        }
        painter->drawPolyline(pts.data(), pts.size());

        painter->restore();
    }
}

void SimulationWidget::update_engine(const PhysParams &phys_params) {
    engine_ = SimulationEngine{phys_params};
    update();
}
