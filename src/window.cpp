#include "window.hpp"
#include "resource.hpp"

MainWin::MainWin(QWidget* parent)
:QMainWindow(parent)
{
    restoreSettings();
    setStyles();
    setupCentralWidget();
    setupSideBar();

}

void MainWin::setupCentralWidget()
{
    centralWidget.setLayout(&cwLayout);
    cwLayout.setContentsMargins(0, 0, 0, 0);
    cwLayout.setSpacing(0);
    setCentralWidget(&centralWidget);

    cwLayout.addWidget(&sideBar);
    cwLayout.addWidget(&primaryContainer);
}

void MainWin::setupSideBar()
{
    sideBar.setProperty("sideBarStyle", "true");
    sbLayout.setContentsMargins(0, 0, 0, 0);
    btn_primaryContainerOpenTagger.setProperty("isActive", "true");
    btn_primaryContainerOpenTagger.setIconSize(QSize(50, 50));
    sbLayout.addWidget(&btn_primaryContainerOpenTagger);
    sbLayout.addStretch();

    sideBar.setLayout(&sbLayout);
    sideBar.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
}

void MainWin::setStyles()
{
    setStyleFromCss(primaryContainer, darkCssFilepath);
    setStyleFromCss(sideBar, darkCssFilepath);
    setStyleFromCss(btn_primaryContainerOpenTagger, darkCssFilepath);
}

void MainWin::saveSettings()
{
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