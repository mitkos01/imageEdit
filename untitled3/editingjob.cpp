#include "editingjob.h"
#include <numeric>

EditingJob::EditingJob(int totalImages)
    : totalImages_(totalImages) {}

void EditingJob::distributeWork(std::vector<Editor>& editors) {

    double totalRate = 0.0; // Розрахунок загальної швидкості редакторів
    for (const auto& editor : editors) {
        totalRate += editor.getRate();
    }


    for (auto& editor : editors) { // Розподіл роботи між редакторами
        int imagesForThisEditor = static_cast<int>((editor.getRate() / totalRate) * totalImages_);
        editor.editImages(imagesForThisEditor);
    }
}

int EditingJob::calculateTotalTime(const std::vector<Editor>& editors) const {

    double totalRate = 0.0; // Розрахунок загальної швидкості редакторів
    for (const auto& editor : editors) {
        totalRate += editor.getRate();
    }


    double totalTime = static_cast<double>(totalImages_) / totalRate; // Розрахунок загального часу
    return static_cast<int>(totalTime);
}
