#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt Layout Example");

    // Widgets
    QPushButton* button = new QPushButton("Submit");
    QLineEdit* lineEdit = new QLineEdit;
    QTextEdit* textEdit = new QTextEdit;

    // === Layout Row 1: Button + LineEdit ===
    QHBoxLayout* topLayout = new QHBoxLayout;
    topLayout->addWidget(button);
    topLayout->addWidget(lineEdit);

    // === Bottom-Right OK/Cancel buttons ===
    QPushButton* okButton = new QPushButton("OK");
    QPushButton* cancelButton = new QPushButton("Cancel");

    QHBoxLayout* bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch(); // pushes buttons to the right
    bottomLayout->addWidget(okButton);
    bottomLayout->addWidget(cancelButton);

    // === Main Layout: Vertical ===
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(textEdit);
    mainLayout->addLayout(bottomLayout); // add bottom buttons

    window.setLayout(mainLayout);
    window.resize(400, 250);
    window.show();

    return app.exec();
}
