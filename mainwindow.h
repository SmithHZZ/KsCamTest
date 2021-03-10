#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "kscam/KsCam.h"
#include "kscam/KsCamCommand.h"
#include "kscam/KsCamEvent.h"
#include "kscam/KsCamFeature.h"
#include "kscam/KsCamImage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
