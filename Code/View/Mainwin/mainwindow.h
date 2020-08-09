#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QMenu>
#include <QDesktopWidget>
#include <QAction>
#include <QDebug>

#include "AboutDialog/AboutDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onFullScreenActionTriggered(bool isChecked);
    void onFirstChoiceActionTriggered();

    void onAboutTriggered();

private:
    Ui::MainWindow *ui;
    QMenu *m_settingMenu;
    QAction *m_fullScreenAction;
    QAction *m_firstChoiceAction;

    QMenu *m_helpMenu;
    QAction *m_aboutAction;
};

#endif // MAINWINDOW_H
