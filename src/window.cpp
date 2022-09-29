#include "window.hpp"

#include <iostream>
#include <QVBoxLayout>

MainWin::MainWin(QWidget* parent)
:QMainWindow(parent)
{
    //Since this is a QMainWindow we cannot set a layout,
    //we can only set a central widget.
    auto centralWidget = new QWidget(this);
    centralWidget->setLayout(new QHBoxLayout());
    

}
