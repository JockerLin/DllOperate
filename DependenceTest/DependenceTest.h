#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DependenceTest.h"
//#include "../QtClassLibraryA/QtClassLibraryA.h"


#include "windows.h"
#include "qdebug.h"

class DependenceTest : public QMainWindow
{
    Q_OBJECT

public:
    DependenceTest(QWidget *parent = Q_NULLPTR);

private:
    Ui::DependenceTestClass ui;
};
