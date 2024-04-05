#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

void MainWindow::setupUI()
{

    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);

    lineEditTotalImages = new QLineEdit(centralWidget);
    spinBoxEditors = new QSpinBox(centralWidget);
    buttonCalculate = new QPushButton("Calculate", centralWidget);
    textEditResults = new QTextEdit(centralWidget);

    spinBoxEditors->setRange(1, 100); // Обмеження кількості редакторів

    layout->addWidget(new QLabel("Total Images:"));
    layout->addWidget(lineEditTotalImages);
    layout->addWidget(new QLabel("Number of Editors:"));
    layout->addWidget(spinBoxEditors);
    layout->addWidget(buttonCalculate);
    layout->addWidget(new QLabel("Results:"));
    layout->addWidget(textEditResults);

    setCentralWidget(centralWidget);


    connect(buttonCalculate, &QPushButton::clicked, this, &MainWindow::calculateWorkload);
}

void MainWindow::calculateWorkload()
{

    bool ok;
    int totalImages = lineEditTotalImages->text().toInt(&ok); // Отримання загальної кількості зображень
    if (!ok || totalImages <= 0) {
        textEditResults->setText("Invalid number of images.");
        return;
    }


    int numberOfEditors = spinBoxEditors->value(); // Отримання кількості редакторів та їх швидкостей
    std::vector<Editor> editors;

    for (int i = 0; i < numberOfEditors; ++i) {
        int minutesPerImage = QInputDialog::getInt(this, tr("Editor Speed"),
                                                   tr("Enter the time in minutes required to process one image for editor %1:").arg(i + 1),
                                                   1, 1, 1000, 1, &ok);
        if (!ok || minutesPerImage <= 0) {
            textEditResults->setText("Invalid speed entered.");
            return;
        }
        double rate = 1.0 / minutesPerImage; // Обчислення швидкості
        editors.push_back(Editor(rate));
    }


    EditingJob editingJob(totalImages); // Отримання кількості редакторів та їх швидкостей
    editingJob.distributeWork(editors);

    // Розрахунок загального часу, потрібного для редагування всіх зображень
    int totalTime = editingJob.calculateTotalTime(editors);

    // Формування результату та відображення його у вікні
    QString results = "Results:\n";
    for (size_t i = 0; i < editors.size(); ++i) {
        results += tr("Editor %1 edited %2 images.\n").arg(i + 1).arg(editors[i].getImagesEdited());
    }
    results += tr("Total time required: %1 minutes.").arg(totalTime);

    textEditResults->setText(results);
}
