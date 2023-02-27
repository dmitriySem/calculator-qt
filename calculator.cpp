#include "calculator.h"
#include "mybutton.h"

#include <QGridLayout>
#include <QFont>
#include <QDebug>
#include <QToolButton>
#include <QtMath>

Calculator::Calculator(){

    m_display_up = new QLineEdit();
    m_display_down = new QLineEdit();
    m_sign = new QLabel();


    m_display_up->setReadOnly(true);
    m_display_down->setReadOnly(true);
    m_display_down->setText("0");
    m_display_up->setText("0");

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
    Button* btn = (Button*) sender();
    int digit = btn->text().toUInt();
    if (m_display_down->text() == "0") {
        m_display_down->clear();
        m_display_up->clear();
    }
    m_display_down->setText(m_display_down->text() + QString::number(digit));
    qDebug() << "digit " << digit;
}

void Calculator::unaryOperatorClicked()
{
    Button* btn = (Button*) sender();
    QString operation = btn->text();

    double operand = m_display_down->text().toDouble();
    double result = 0.0;

    if (operation == m_squareRoot_sign) {
        if (operand < 0.0) {
            abortOperation();
            return;
        }
        result = std::sqrt(operand);
    }
    if (operation == m_power_sign) {
        result = std::pow(operand, 2.0);
    }
    if (operation == m_reciprocal_sign) {
        if (operand == 0.0) {
            abortOperation();
            return;
        }
        result = 1 / operand;
    }

    m_display_down->setText(QString::number(result));
}

void Calculator::doubleOperandClicked()
{
    Button* btn = (Button*) sender();
    QString operation = btn->text();

}

void Calculator::equalClicked()
{
    m_display_up->setText( m_display_down->text());
}

void Calculator::pointClicked()
{

}

void Calculator::changeSignClicked()
{
    QString text = m_display_down->text();
    double val = text.toDouble();
    if (val > 0.0)
        text.prepend("-");
     else if (val < 0.0)
        text.remove(0, 1);
    m_display_down->setText(text);
}

void Calculator::backspaceClicked()
{
    QString text = m_display_down->text();
    text.chop(1);
    if (text.isEmpty())
        text = "0";

     m_display_down->setText(text);
}

void Calculator::clear()
{
    m_display_down->setText("0");
}

void Calculator::clearAll()
{
    m_display_up->clear();
    m_display_down->setText("0");
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

void Calculator::abortOperation()
{
    m_display_up->setText("###");
    m_display_down->setText("###");
}
