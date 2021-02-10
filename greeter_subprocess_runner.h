#ifndef GREETER_SUBPROCESS_RUNNER_H
#define GREETER_SUBPROCESS_RUNNER_H

#include <QObject>
#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
class greeter_subprocess_runner : public QObject
{
    Q_OBJECT
public:
    explicit greeter_subprocess_runner(QObject *parent = nullptr);
    void exit_app();
public slots:
    void run();
signals:

};

#endif // GREETER_SUBPROCESS_RUNNER_H
