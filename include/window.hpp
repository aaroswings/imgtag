#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSettings>
#include <QStackedWidget>

#include "gui/mwSidebar.hpp"

class MainWin : public QMainWindow
{
    Q_OBJECT

private:
    QHBoxLayout cwLayout;
    QWidget centralWidget;

    QVBoxLayout sbLayout;
    MWSidebar sideBar;

    QStackedWidget primaryContainer;
    QSettings settings{"imgtag", "mainWin"};

    QPushButton btn_primaryContainerOpenTagger{QIcon("../resource/icon/tagDark.png"), ""};
    QString darkCssFilepath{"../resource/css/dark.css"};

public:
    MainWin(QWidget* parent = nullptr);
    ~MainWin() = default;

    void setupCentralWidget();
    void setupSideBar();
    void saveSettings();
    void setStyles();
    void restoreSettings();
    void closeEvent(QCloseEvent *event);

signals:
    
};