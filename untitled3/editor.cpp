#include "editor.h"

Editor::Editor(double rate)
    : rate_(rate), imagesEdited_(0) {}

void Editor::editImages(int images) {

    imagesEdited_ += images; // Додавання кількості відредагованих зображень
}

double Editor::getRate() const {

    return rate_; // Повернення швидкості редактора
}

int Editor::getImagesEdited() const {

    return imagesEdited_; // Повернення кількості відредагованих зображень
}
