#include "mybutton.h"


Button::Button(const QString &text, QWidget *parent) :QToolButton(parent)
{

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred); //кнопка занимают по горизонтали все место, кот ей данно; по вертикале - рекомендуемое
    setText(text);
}

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() +=30;
    size.rwidth() = qMax(size.width(),size.height());
    return size;
}


