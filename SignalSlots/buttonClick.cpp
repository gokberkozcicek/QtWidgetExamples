#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent)
    {
        // Set up the central widget and layout
        QWidget* centralWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);

        // Create a label
        label = new QLabel("Hello, World!", this);
        layout->addWidget(label);

        // Create a button
        QPushButton* button = new QPushButton("Click Me!", this);
        layout->addWidget(button);

        // Set central widget and layout
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        // Connect the button's clicked signal to the custom slot
        connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

        setWindowTitle("Signal-Slot Example");
        resize(300, 200);
    }

private slots:
    // Define the custom slot method
    void onButtonClicked()
    {
        label->setText("Button Clicked!");
    }

private:
    QLabel* label; // Declare label as a class member
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

#include "main.moc"
