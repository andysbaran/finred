#ifndef VALIDATEDLINEEDIT_H
#define VALIDATEDLINEEDIT_H

#include <QLineEdit>
#include <QValidator>

class ValidatedLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit ValidatedLineEdit(QWidget *parent = 0);
    
    bool isAcceptable();

signals:
    
public slots:
    void setValidationState(QValidator::State state);
    
};

#endif // VALIDATEDLINEEDIT_H
