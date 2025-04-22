#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QGridLayout Example");

    // Widgets
    QLabel* nameLabel = new QLabel("Name:");
    QLineEdit* nameEdit = new QLineEdit;

    QLabel* ageLabel = new QLabel("Age:");
    QLineEdit* ageEdit = new QLineEdit;

    QLabel* emailLabel = new QLabel("Email:");
    QLineEdit* emailEdit = new QLineEdit;

    QPushButton* submitButton = new QPushButton("Submit");

    // Create a QGridLayout
    QGridLayout* gridLayout = new QGridLayout;

    // Add widgets to the layout (row, column)
    gridLayout->addWidget(nameLabel, 0, 0);
    gridLayout->addWidget(nameEdit, 0, 1);

    gridLayout->addWidget(ageLabel, 1, 0);
    gridLayout->addWidget(ageEdit, 1, 1);

    gridLayout->addWidget(emailLabel, 2, 0);
    gridLayout->addWidget(emailEdit, 2, 1);

    gridLayout->addWidget(submitButton, 3, 0, 1, 2);  // Span across two columns

    // Set the layout for the window
    window.setLayout(gridLayout);

    // Resize the window and show
    window.resize(400, 200);
    window.show();

    return app.exec();
}
