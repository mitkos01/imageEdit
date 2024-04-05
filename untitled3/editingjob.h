#ifndef EDITINGJOB_H
#define EDITINGJOB_H

#include <vector>
#include "editor.h"

class EditingJob {
public:

    EditingJob(int totalImages); // Ініціалізує загальну кількість зображень


    void distributeWork(std::vector<Editor>& editors); // Розподіл завдань між редакторами


    int calculateTotalTime(const std::vector<Editor>& editors) const; // Розрахунок загального часу

private:
    int totalImages_; // Загальна кількість зображень
};

#endif
