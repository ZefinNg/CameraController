#include "AboutDialog.h"
#include <QPixmap>

#define DIALOG_WIDTH  580
#define DIALOG_HEIGHT 320

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(tr("关于CameraController"));
    this->setFixedSize(DIALOG_WIDTH, DIALOG_HEIGHT);

    m_logoLabel = new QLabel(this);
    QPixmap logoPixmap(":/Logo.png");
    m_logoLabel->setPixmap(logoPixmap);
    m_logoLabel->move(100, 100);

}
