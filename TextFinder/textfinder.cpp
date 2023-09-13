#include "textfinder.h"
#include "ui_textfinder.h"
#include <QTextEdit> 
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTextCursor>

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);

    // Create a QTextEdit widget
     textEdit = new QTextEdit(this);

    // Set the fixed size of the widget (width x height in pixels)
    textEdit->setFixedSize(300, 300);

    // Set the x and y coordinates for the widget's position
    textEdit->move(10, 40);  // Set x = 100, y = 100

    // Enable text wrapping
    textEdit->setWordWrapMode(QTextOption::WordWrap);

     // You can set the initial text if needed
    textEdit->setPlainText("This is a multi-line text editor with word wrapping.");

    // Connect the button's clicked signal to the search slot
    connect(ui->pushButtonSelect, &QPushButton::clicked, this, &TextFinder::searchAndHighlight);

}

void TextFinder::searchAndHighlight() {

    // Ensure QTextEdit is not in read-only mode and has focus
    ui->inputTextToSearch->setReadOnly(false);
    ui->inputTextToSearch->setFocus();

    // Get the word to search for from the first QTextEdit
    QString inputText = ui->inputTextToSearch->toPlainText(); // Get plain text content

    // Get the QTextDocument from the second QTextEdit
    QTextDocument* documentToSearchIn = textEdit->document();
    // Create a QTextCursor to search for the word
    QTextCursor cursor(documentToSearchIn);
    QTextCharFormat highlightFormat;
    highlightFormat.setBackground(Qt::yellow); // Highlight color
    int foundCount = 0;

    // Search for and highlight all occurrences of the word
    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = documentToSearchIn->find(inputText, cursor);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(highlightFormat);
            foundCount++;
        }
}
    // Display a dialog with the search result
    QMessageBox msgBox;
    msgBox.setWindowTitle("Search Result");

    if (foundCount > 0) {
        msgBox.setText("Found " + QString::number(foundCount) + " occurrences of '" + inputText + "'.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStandardButtons(QMessageBox::Ok);
    } else {
        msgBox.setText("Word not found.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok);
    }

    msgBox.exec();
}

TextFinder::~TextFinder()
{
    delete ui;
    delete textEdit;
}

