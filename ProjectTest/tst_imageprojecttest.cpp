#include <QtTest>
#include "../untitled3/editor.h"
#include "../untitled3/editingjob.h"


class ImageProjectTest : public QObject
{
    Q_OBJECT

private slots:
    void testEditor();  // Тест для класу Editor
    void testEditingJob();  // Тест для класу EditingJob
};

void ImageProjectTest::testEditor()
{
    Editor editor(0.5);
    editor.editImages(10);
    QCOMPARE(editor.getImagesEdited(), 10);
}

void ImageProjectTest::testEditingJob()
{

}

QTEST_APPLESS_MAIN(ImageProjectTest)

#include "tst_imageprojecttest.moc"
