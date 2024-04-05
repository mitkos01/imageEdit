#ifndef EDITOR_H
#define EDITOR_H

class Editor {
public:

    Editor(double rate); // Ініціалізує швидкість редактора


    void editImages(int images); // Редагування зображень


    double getRate() const; // Отримання швидкості редактора


    int getImagesEdited() const; // Отримання кількості відредагованих зображень

private:
    double rate_;       // Швидкість редактора
    int imagesEdited_;  // Кількість відредагованих зображень
};

#endif
