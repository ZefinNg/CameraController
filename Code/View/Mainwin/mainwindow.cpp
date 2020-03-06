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
    this->resize(APP_WIDTH, APP_HEIGHT);

    QDesktopWidget *desktopWidget = QApplication::desktop();
    this->move((desktopWidget->width() - this->width()) / 2,
               (desktopWidget->height() - this->height()) / 2);

    m_settingMenu = this->menuBar()->addMenu(tr("相机配置"));
    m_aboutMenu   = this->menuBar()->addMenu(tr("关于"));

    m_fullScreenAction  = new QAction(tr("全屏"), m_settingMenu);
    m_fullScreenAction->setCheckable(true);
    m_firstChoiceAction = new QAction(tr("首选项"), m_settingMenu);

    m_settingMenu->addAction(m_fullScreenAction);
    m_settingMenu->addAction(m_firstChoiceAction);

    connect(m_fullScreenAction,  SIGNAL(triggered(bool)), this, SLOT(onFullScreenAction(bool)));
    connect(m_firstChoiceAction, SIGNAL(triggered()),     this, SLOT(onFirstChoiceAction()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFullScreenAction(bool checked)
{

}

void MainWindow::onFirstChoiceAction()
{

}
