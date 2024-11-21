#pragma once
#include <QObject>
#include "Controller.h"

class ControllerWorker : public QObject
{
    Q_OBJECT

public:
    Controller* controller;

public slots:
    void caseUp() {
        controller->caseUp();
    }

    void backHome() {
        controller->backHome();
    }

    void caseDown() {
        controller->caseDown();
    }

    void stop() {
        controller->stop();
    }
};
