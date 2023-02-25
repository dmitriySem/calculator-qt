#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "mybutton.h"

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator();

private slots:
    void digitClicked();
    void unaryOperatorClicked();
    void doubleOperandClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
    void clearMemory();
    void readMemory();
    void addToMemory();
    void minToMemory();



private:
   Button* createButton(const QString& text, const char* member);

   double m_sum_in_memmory;

   QString m_pending_operation;

   QLineEdit* m_display_up;
   QLineEdit* m_display_down;
   QLabel* m_sign;

   Button* m_digitButtons[10];
   Button* pointButton;
   Button* changeSignButton;

   Button* backspaceButton;
   Button* clearButton;
   Button* clearAllButton;

   Button* clearMemoryButton;
   Button* readMemoryButton;
   Button* setMemoryButton;
   Button* addToMemoryButton;

   Button* divisionButton;
   Button* timesButton;
   Button* minusButton;
   Button* plusButton;

   Button* squareRootButton;
   Button* powerButton;
   Button* reciprocalButton;

   Button* equalButton;

   QString m_squareRoot_sign = QChar(0x221A);
   QString m_power_sign = 'x' + QChar(0x000000b2);
   QString m_reciprocal_sign = "1/x";

   QString m_division_sign = QChar(0x000000F7);
   QString m_times_sign = QChar(0x000000D7);
   QString m_plus_sign = "+";
   QString m_minus_sign = "-";

   QString m_change_sign = QChar(0x000000b1);


};



#endif // CALCULATOR_H
