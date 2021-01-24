#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

 public slots:

    void uv_pose(const QString &x, const QString &y);

 private slots:

    void on_pushButton_calculate_clicked();

 private:
    Ui::MainWindow *ui_;
};

#endif // MAINWINDOW_H
