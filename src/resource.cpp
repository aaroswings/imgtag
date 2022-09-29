#include "resource.hpp"

void setStyleFromCss(QWidget &widget, const QString &filePath)
{
    QString finalCss;
    QFile baseCssFile(filePath);
    if (baseCssFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        finalCss.append(baseCssFile.readAll().data());
    }
    widget.setStyleSheet(finalCss);
}
