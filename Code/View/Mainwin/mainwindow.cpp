#include "mainwindow.h"
#include "ui_mainwindow.h"

#define APP_WIDTH  (1280)
#define APP_HEIGHT (720)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Logo.ico"));
    this->setWindowTitle(tr("CameraController"));
    this->setMinimumSize(APP_WIDTH, APP_HEIGHT);

    QDesktopWidget *desktopWidget = QApplication::desktop();
    this->move((desktopWidget->width() - this->width()) / 2,
               (desktopWidget->height() - this->height()) / 2);

    m_settingMenu = this->menuBar()->addMenu(tr("相机配置(&S)"));
    m_helpMenu   = this->menuBar()->addMenu(tr("帮助(&H)"));

    m_fullScreenAction  = new QAction(tr("全屏(&F)"), m_settingMenu);
    m_firstChoiceAction = new QAction(tr("首选项(&C)"), m_settingMenu);
    m_aboutAction = new QAction(tr("关于(&A)"), m_helpMenu);

    m_fullScreenAction->setCheckable(true);

    m_settingMenu->addAction(m_fullScreenAction);
    m_settingMenu->addAction(m_firstChoiceAction);
    m_helpMenu->addAction(m_aboutAction);

    connect(m_fullScreenAction,  SIGNAL(triggered(bool)), this, SLOT(onFullScreenActionTriggered(bool)));
    connect(m_firstChoiceAction, SIGNAL(triggered()),     this, SLOT(onFirstChoiceActionTriggered()));
    connect(m_aboutAction, SIGNAL(triggered()), this, SLOT(onAboutTriggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFullScreenActionTriggered(bool isChecked)
{
    if (isChecked)
        this->showMaximized();
    else
        this->showNormal();
}

void MainWindow::onFirstChoiceActionTriggered()
{

}

void MainWindow::onAboutTriggered()
{
    AboutDialog *aboutDialog = new AboutDialog(this);
    aboutDialog->exec();
}
