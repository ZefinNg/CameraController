#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QMenu>
#include <QDesktopWidget>
#include <QAction>
#include <QTranslator>
#include <QApplication>
#include <QDir>
#include <QMenuBar>
#include "Service/ConfigService/ConfigService.h"
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onFullScreenAction(bool checked);
    void onFirstChoiceAction();

private:
    void loadLanguage(QString language);

private:
    QMenuBar *m_menuBar;

    QMenu   *m_settingMenu;
    QAction *m_fullScreenAction;
    QAction *m_firstChoiceAction;

    QMenu *m_aboutMenu;

    ConfigService *m_configService;

    QTranslator *m_translator;
};

#endif // MAINWINDOW_H
