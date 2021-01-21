#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

 private slots:
    void on_pushButton_calculate_clicked();

 private:
    Ui::MainWindow *ui_;
};

#endif // MAINWINDOW_H
