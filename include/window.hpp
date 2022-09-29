#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSettings>

class MainWin : public QMainWindow
{
    Q_OBJECT


public:
    MainWin(QWidget* parent = nullptr);
    ~MainWin() = default;

    void saveSettings();
    void restoreSettings();
    void closeEvent(QCloseEvent *event);

    // signals:
    
};