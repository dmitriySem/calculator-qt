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


    m_display_up->setReadOnly(true);
    m_display_down->setReadOnly(true);

    m_display_up->setAlignment(Qt::AlignRight);
    m_display_down->setAlignment(Qt::AlignRight);

    m_display_up->setMaxLength(15);
    m_display_down->setMaxLength(15);

    m_display_up->setFont(QFont("Times",13,-1,false));
    m_display_down->setFont(QFont("Times",13,-1,false));

    for (int i = 0; i < 10; ++i)
        m_digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));

    pointButton = createButton(".", SLOT(pointClicked()));
    changeSignButton = createButton(m_change_sign, SLOT(changeSignClicked()));

    backspaceButton = createButton("Backspace", SLOT(backspaceClicked()));
    clearButton = createButton("Clear", SLOT(clear()));
    clearAllButton = createButton("ClearAll", SLOT(clearAll()));

    clearMemoryButton = createButton("MC", SLOT(clearMemory()));
    readMemoryButton = createButton("MR", SLOT(readMemory()));
    setMemoryButton = createButton("M+", SLOT(addToMemory()));
    addToMemoryButton = createButton("M-", SLOT(minToMemory()));

    divisionButton = createButton(m_division_sign, SLOT(doubleOperandClicked()));
    timesButton = createButton(m_times_sign, SLOT(doubleOperandClicked()));
    minusButton = createButton(m_minus_sign, SLOT(doubleOperandClicked()));
    plusButton = createButton(m_plus_sign, SLOT(doubleOperandClicked()));

    squareRootButton = createButton(m_squareRoot_sign, SLOT(unaryOperatorClicked()));
    powerButton = createButton(m_power_sign, SLOT(unaryOperatorClicked()));
    reciprocalButton = createButton(m_reciprocal_sign, SLOT(unaryOperatorClicked()));

    equalButton = createButton("=", SLOT(equalClicked()));

    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


    mainLayout->addWidget(m_digitButtons[1], 4, 1);
    mainLayout->addWidget(m_digitButtons[2], 4, 2);
    mainLayout->addWidget(m_digitButtons[3], 4, 3);
    mainLayout->addWidget(m_digitButtons[4], 5, 1);
    mainLayout->addWidget(m_digitButtons[5], 5, 2);
    mainLayout->addWidget(m_digitButtons[6], 5, 3);
    mainLayout->addWidget(m_digitButtons[7], 6, 1);
    mainLayout->addWidget(m_digitButtons[8], 6, 2);
    mainLayout->addWidget(m_digitButtons[9], 6, 3);
    mainLayout->addWidget(m_digitButtons[0], 7, 1);

    mainLayout->addWidget(m_display_up, 0, 0, 1, 6);
    mainLayout->addWidget(m_sign, 1, 5, 1, 1);
    mainLayout->addWidget(m_display_down, 2, 0, 1, 6);
    mainLayout->addWidget(backspaceButton, 3, 0, 1, 2);
    mainLayout->addWidget(clearButton, 3, 2, 1, 2);
    mainLayout->addWidget(clearAllButton, 3, 4, 1, 2);

    mainLayout->addWidget(clearMemoryButton, 4, 0);
    mainLayout->addWidget(readMemoryButton, 5, 0);
    mainLayout->addWidget(setMemoryButton, 6, 0);
    mainLayout->addWidget(addToMemoryButton, 7, 0);
    mainLayout->addWidget(pointButton, 7, 2);
    mainLayout->addWidget(changeSignButton, 7, 3);

    mainLayout->addWidget(divisionButton, 4, 4);
    mainLayout->addWidget(timesButton, 5, 4);
    mainLayout->addWidget(minusButton, 6, 4);
    mainLayout->addWidget(plusButton, 7, 4);

    mainLayout->addWidget(squareRootButton, 4, 5);
    mainLayout->addWidget(powerButton, 5, 5);
    mainLayout->addWidget(reciprocalButton, 6, 5);
    mainLayout->addWidget(equalButton, 7, 5);

    setLayout(mainLayout);

    setWindowTitle("Calculator");
}

void Calculator::digitClicked()
{

}

void Calculator::unaryOperatorClicked()
{

}

void Calculator::doubleOperandClicked()
{

}

void Calculator::equalClicked()
{

}

void Calculator::pointClicked()
{

}

void Calculator::changeSignClicked()
{

}

void Calculator::backspaceClicked()
{

}

void Calculator::clear()
{

}

void Calculator::clearAll()
{

}

void Calculator::clearMemory()
{

}

void Calculator::readMemory()
{

}

void Calculator::addToMemory()
{

}

void Calculator::minToMemory()
{

}


Button *Calculator::createButton(const QString &text, const char *member)
{
    Button* btn = new Button(text);
    connect(btn, SIGNAL(clicked()), this, member); // this этот класс обрабатывает
    return btn;
}
