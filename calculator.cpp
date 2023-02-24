#include "calculator.h"
#include "mybutton.h"

#include <QGridLayout>
#include <QFont>
#include <QDebug>
#include <QToolButton>

Calculator::Calculator(){

    m_display_up = new QLineEdit();
    m_display_down = new QLineEdit();
    m_sign = new QLabel();

    QGridLayout* mainLayout = new QGridLayout();
    //mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    m_display_up->setReadOnly(true);
    m_display_down->setReadOnly(true);

    m_display_up->setAlignment(Qt::AlignRight);
    m_display_down->setAlignment(Qt::AlignRight);

    m_display_up->setMaxLength(15);
    m_display_down->setMaxLength(15);

    m_display_up->setFont(QFont("Times",13,-1,false));
    m_display_down->setFont(QFont("Times",13,-1,false));

    for (int i = 0; i < 10; ++i) {
        m_digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));


    }
    point = createButton(".", SLOT(digitClicked()));

    mainLayout->addWidget(m_digitButtons[1], 6, 1, 1, 1);
    mainLayout->addWidget(m_digitButtons[2], 6, 2, 1, 1);
    mainLayout->addWidget(m_digitButtons[3], 6, 3, 1, 1);
    mainLayout->addWidget(m_digitButtons[4], 7, 1, 1, 1);
    mainLayout->addWidget(m_digitButtons[5], 7, 2, 1, 1);
    mainLayout->addWidget(m_digitButtons[6], 7, 3, 1, 1);
    mainLayout->addWidget(m_digitButtons[7], 8, 1, 1, 1);
    mainLayout->addWidget(m_digitButtons[8], 8, 2, 1, 1);
    mainLayout->addWidget(m_digitButtons[9], 8, 3, 1, 1);
    mainLayout->addWidget(m_digitButtons[0], 9, 1, 1, 1);
    mainLayout->addWidget(point, 9, 2, 1, 1);

    mainLayout->addWidget(m_display_up, 0, 0, 6, 1);
    mainLayout->addWidget(m_sign, 1, 5, 1, 1);
    mainLayout->addWidget(m_display_down, 2, 0, 6, 1);

    setLayout(mainLayout);

    setWindowTitle("Calculator");
}

void Calculator::digitClicked()
{

}

void Calculator::unaryOperatorClicked()
{

}


Button *Calculator::createButton(const QString &text, const char *member)
{
    Button* btn = new Button(text);
    connect(btn, SIGNAL(clicked()), this, member); // this этот класс обрабатывает
    return btn;
}
