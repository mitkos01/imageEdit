#include "editingjob.h"
#include <numeric>

EditingJob::EditingJob(int totalImages)
    : totalImages_(totalImages) {}

void EditingJob::distributeWork(std::vector<Editor>& editors) {

    double totalRate = std::accumulate(editors.begin(), editors.end(), 0.0,
                                       [](double sum, const Editor& editor) {
                                           return sum + editor.getRate();
                                       });


    int remainingImages = totalImages_;
    for (auto& editor : editors) {
        int imagesForThisEditor = static_cast<int>((editor.getRate() / totalRate) * totalImages_);
        editor.editImages(imagesForThisEditor);
        remainingImages -= imagesForThisEditor;
    }


    int editorIndex = 0;
    while (remainingImages > 0) {
        editors[editorIndex].editImages(1);
        --remainingImages;
        editorIndex = (editorIndex + 1) % editors.size(); 
    }
}

int EditingJob::calculateTotalTime(const std::vector<Editor>& editors) const {
    
    double totalRate = std::accumulate(editors.begin(), editors.end(), 0.0,
                                       [](double sum, const Editor& editor) {
                                           return sum + editor.getRate();
                                       });

    
    double totalTime = static_cast<double>(totalImages_) / totalRate;
    return static_cast<int>(totalTime);
}
