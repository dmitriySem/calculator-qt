#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QToolButton>

class Button : public QToolButton
{
    Q_OBJECT

private:

public:
    explicit Button(const QString& text, QWidget *parent = nullptr);

    QSize sizeHint() const override;
};

#endif
