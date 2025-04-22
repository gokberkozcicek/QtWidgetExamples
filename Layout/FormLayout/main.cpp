#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>

class ExampleForm : public QWidget
{
public:
    ExampleForm()
    {
        // Set window title
        setWindowTitle("Form Layout Example");

        // Create a form layout
        QFormLayout* layout = new QFormLayout(this);

        // Create form elements: labels and corresponding input fields
        QLabel* nameLabel = new QLabel("Name:");
        QLineEdit* nameEdit = new QLineEdit(this);

        QLabel* ageLabel = new QLabel("Age:");
        QSpinBox* ageSpin = new QSpinBox(this);

        QLabel* emailLabel = new QLabel("Email:");
        QLineEdit* emailEdit = new QLineEdit(this);

        // Add rows to the layout (label, input widget pair)
        layout->addRow(nameLabel, nameEdit);
        layout->addRow(ageLabel, ageSpin);
        layout->addRow(emailLabel, emailEdit);

        // Add a submit button
        QPushButton* submitButton = new QPushButton("Submit", this);
        layout->addWidget(submitButton);

        // Set the layout for the window
        setLayout(layout);

        // Set window size
        setGeometry(100, 100, 300, 200);
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Create and show the form window
    ExampleForm window;
    window.show();

    return app.exec();
}
