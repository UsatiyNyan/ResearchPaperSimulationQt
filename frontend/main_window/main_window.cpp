#include "main_window.h"
#include "./ui_main_window.h"

#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::on_pushButton_calculate_clicked() {
    PhysParams phys_params{};
    bool ok = false;

    phys_params.uv.pose.first = ui_->textEdit_uv_x->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.uv.pose.second = -ui_->textEdit_uv_y->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.uv.thrust.first = ui_->textEdit_thrust_x->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.uv.thrust.second = ui_->textEdit_thrust_y->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.uv.lift = ui_->textEdit_uv_lift->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.uv.length = ui_->textEdit_uv_length->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.uv.diameter = ui_->textEdit_uv_diameter->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.uv.speed = ui_->textEdit_uv_speed->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.cable.length = ui_->textEdit_cable_length->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.cable.diameter = ui_->textEdit_cable_diameter->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    phys_params.cable.lift = ui_->textEdit_cable_lift_force->toPlainText().toDouble(&ok);
    if (not ok) { return; }

    ui_->simulation_widget->update_engine(phys_params);
}
