#include "window.hpp"
#include "resource.hpp"

MainWin::MainWin(QWidget* parent)
:QMainWindow(parent)
{
    restoreSettings();
    auto centralWidget = new QWidget(this);
    centralWidget->setLayout(new QHBoxLayout());
    setStyleFromCss(*centralWidget, QString("../resource/css/dark.css"));
    setContentsMargins(0, 0, 0, 0);
}



void MainWin::saveSettings()
{
    QSettings settings("imgtag", "mainWin");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("maximized", isMaximized());
    if (!isMaximized())
    {
        settings.setValue("pos", pos());
        settings.setValue("size", size());
    }
}

void MainWin::restoreSettings()
{
    QSettings settings("imgtag", "mainWin");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    move(settings.value("pos", pos()).toPoint());
    resize(settings.value("size", size()).toSize());
    if (settings.value("maximized", isMaximized()).toBool())
        showMaximized();
}

void MainWin::closeEvent(QCloseEvent *event)
{
    saveSettings();
    QWidget::closeEvent(event);
}