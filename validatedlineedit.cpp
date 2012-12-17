#include "validatedlineedit.h"
#include <QDebug>

ValidatedLineEdit::ValidatedLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    setStyleSheet("QLineEdit {"
        "background-color: rgb(242,222,222)"
    "}");
}

bool ValidatedLineEdit::isAcceptable()
{
    // return if the current line text is acceptable or not

    QString text = this->text();
    int pos = text.length();
    return validator()->validate(text, pos) == QValidator::Acceptable;
}

void ValidatedLineEdit::setValidationState(QValidator::State state)
{
    // set the color based on the validation signal
    // (colors taken from Twitter Bootstrap)
    switch (state) {
    case QValidator::Invalid:
        setStyleSheet("QLineEdit {"
            "background-color: rgb(242,222,222)"
        "}");
        break;
    case QValidator::Intermediate:
        setStyleSheet("QLineEdit {"
            "background-color: rgb(252,248,227)"
        "}");
        break;
    case QValidator::Acceptable:
        setStyleSheet("QLineEdit {"
            "background-color: rgb(223,240,216)"
        "}");
        break;
    }
}
