#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QInputDialog>
#include "editingjob.h"
#include "editor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:

    void calculateWorkload();

private:

    void setupUI();

    QWidget *centralWidget;
    QVBoxLayout *layout;
    QLineEdit *lineEditTotalImages;
    QSpinBox *spinBoxEditors;
    QPushButton *buttonCalculate;
    QTextEdit *textEditResults;
};

#endif
