#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class TextFinder; }
QT_END_NAMESPACE

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    TextFinder(QWidget *parent = nullptr);
    void searchAndHighlight();
    ~TextFinder();

private:
    Ui::TextFinder *ui;
    QTextEdit *textEdit;

};
#endif // TEXTFINDER_H
