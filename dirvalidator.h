#ifndef DIRVALIDATOR_H
#define DIRVALIDATOR_H

#include <QValidator>

class DirValidator : public QValidator
{
    Q_OBJECT
public:
    explicit DirValidator(QObject *parent = 0);
    
    State validate(QString &input, int &pos) const;

    void fixup(QString &) const;

signals:

    void validationState(QValidator::State state) const;
    
public slots:
    
};

#endif // DIRVALIDATOR_H
