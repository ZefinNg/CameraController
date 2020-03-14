#include "mainwindow.h"

#define APP_WIDTH  (1280)
#define APP_HEIGHT (720)

#define LANGUAGE_FILE_PREFIX "./Resources/Languages/"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_translator(NULL)
{
    this->setWindowIcon(QIcon(":/Logo.ico"));
    this->setWindowTitle(tr("CameraController"));

    QDir::setCurrent(QApplication::applicationDirPath());

    m_menuBar = new QMenuBar(this);

    //Parse App config file
    m_configService = new ConfigService("./Resources/Configs/AppConfigs.ini", this);
    QString appLanguage = m_configService->getStringValue("Settings", "language", "Chinese");
    this->loadLanguage(appLanguage);


    this->resize(APP_WIDTH, APP_HEIGHT);

    QDesktopWidget *desktopWidget = QApplication::desktop();
    this->move((desktopWidget->width() - this->width()) / 2,
               (desktopWidget->height() - this->height()) / 2);

    m_settingMenu = this->menuBar()->addMenu(tr("mainwin.cameraSetting"));
    m_aboutMenu   = this->menuBar()->addMenu(tr("mainwin.about"));

    m_fullScreenAction  = new QAction(tr("mainwin.fullScreen"), m_settingMenu);
    m_fullScreenAction->setCheckable(true);
    m_firstChoiceAction = new QAction(tr("mainwin.firstChoice"), m_settingMenu);

    m_settingMenu->addAction(m_fullScreenAction);
    m_settingMenu->addAction(m_firstChoiceAction);

    connect(m_fullScreenAction,  SIGNAL(triggered(bool)), this, SLOT(onFullScreenAction(bool)));
    connect(m_firstChoiceAction, SIGNAL(triggered()),     this, SLOT(onFirstChoiceAction()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::onFullScreenAction(bool checked)
{

}

void MainWindow::onFirstChoiceAction()
{

}

void MainWindow::loadLanguage(QString language)
{
    if (m_translator == NULL) {
        m_translator = new QTranslator(this);
    }
    else {
        qApp->removeTranslator(m_translator);
    }

    QString languageFile = LANGUAGE_FILE_PREFIX;
    if (language == "Chinese") {
        languageFile += "zh_CN.qm";
    }
    else if (language == "English") {
        languageFile += "en.qm";
    }
    else {
        languageFile += "zh_CN.qm";
    }

    if (m_translator->load(languageFile)) {
        qApp->installTranslator(m_translator);
    }
}
