#include "simulation_widget.h"
#include "ui_simulation_widget.h"

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

    draw_water(painter);

    painter->translate(width() / 2, height() / 2);

    draw_ship(painter);

    painter->setBrush(Qt::black);
    painter->setPen(QPen(Qt::black, 4));

    auto engine_pts = engine_->points();
    scale(engine_pts.back());
    std::vector<QPointF> pts;
    pts.reserve(engine_pts.size());
    for (auto &p: engine_pts) {
        pts.emplace_back(p.x() * scale_, p.y() * scale_);
    }

    draw_cells(painter);

    painter->translate(-pts.back().x(), -pts.back().y());
    painter->drawPolyline(pts.data(), pts.size());

    draw_uv(painter);

    emit uv_pose(QString::number(-engine_pts.back().x()),
                 QString::number(-engine_pts.back().y()));

    painter->restore();
}

void SimulationWidget::update_engine(const PhysParams &phys_params) {
    engine_ = SimulationEngine{phys_params};
    update();
}

void SimulationWidget::scale(Point<> reference_point) {
    double abs_x = std::abs(reference_point.x());
    double abs_y = std::abs(reference_point.y());

    if (abs_x > abs_y) {
        scale_ = (width() - 50) / abs_x / 2;
    } else {
        scale_ = (height() - 50) / abs_y / 2;
    }
}

void SimulationWidget::draw_water(const std::unique_ptr<QPainter> &painter) const {
    painter->setBrush(Qt::blue);
    painter->setPen(QPen(Qt::blue, 4));
    painter->drawLine(0, height() / 2, width(), height() / 2);
}

void SimulationWidget::draw_ship(const std::unique_ptr<QPainter> &painter) const {
    painter->setBrush(Qt::transparent);
    painter->setPen(QPen(Qt::black, 2));
    QPolygon polygon{};
    polygon.append(QPoint{-50, 0});
    polygon.append(QPoint{-80, -40});
    polygon.append(QPoint{90, -50});
    polygon.append(QPoint{50, 0});
    painter->drawPolygon(polygon);
    polygon.clear();
    polygon.append(QPoint{-30, -43});
    polygon.append(QPoint{-25, -60});
    polygon.append(QPoint{25, -60});
    polygon.append(QPoint{30, -48});
    painter->drawPolygon(polygon);
}

void SimulationWidget::draw_cells(const std::unique_ptr<QPainter> &painter) const {

}

void SimulationWidget::draw_uv(const std::unique_ptr<QPainter> &painter) const {
    painter->setBrush(Qt::white);
    painter->setPen(QPen(Qt::black, 3));
    QPolygon polygon{};
    polygon.append(QPoint{0, 20});
    polygon.append(QPoint{40, 0});
    polygon.append(QPoint{0, -20});
    polygon.append(QPoint{0, 20});
    painter->drawPolygon(polygon);
    painter->drawRoundedRect(QRect{0, -20, 80, 40}, 30, 20);
}
