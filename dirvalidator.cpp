#include "dirvalidator.h"
#include <QFileInfo>
#include <QDir>
#include <QDebug>

DirValidator::DirValidator(QObject *parent) :
    QValidator(parent)
{
}

QValidator::State DirValidator::validate(QString &input, int &pos) const
{
    QFileInfo dir(input);

    QValidator::State status;

    if (dir.exists() && dir.isDir()) { // it exists and is a directory
        status = Acceptable;
    }
    else if (dir.dir().exists()) { // the parent directory exists
        qDebug() << dir.dir();
        status = Intermediate;
    }
    else { // total junk
        status = Invalid;
    }

    // send a signal so we can change colors, etc later
    emit validationState(status);
    return status;
}

void DirValidator::fixup(QString &input) const
{
    QFileInfo dir(input);

    // if the user typed in a file name we can
    // replace it with the directory that file exists in
    if (dir.isFile()) {
        input = dir.dir().path();
    }
}
