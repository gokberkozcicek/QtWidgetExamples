#include <QApplication>
#include <QWidget>
#include <QSplitter>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>

class SplitterExample : public QWidget
{
public:
    SplitterExample()
    {
        // Set window title
        setWindowTitle("QSplitter Layout Example");

        // Create the main layout
        QVBoxLayout* mainLayout = new QVBoxLayout(this);

        // Create a QSplitter
        QSplitter* splitter = new QSplitter(this);

        // Create some widgets to place inside the splitter
        QWidget* leftWidget = new QWidget(this);
        QPushButton* button1 = new QPushButton("Button 1", leftWidget);
        QVBoxLayout* leftLayout = new QVBoxLayout(leftWidget);
        leftLayout->addWidget(button1);

        QWidget* rightWidget = new QWidget(this);
        QLabel* label = new QLabel("This is the right panel", rightWidget);
        QTextEdit* textEdit = new QTextEdit(rightWidget);
        QVBoxLayout* rightLayout = new QVBoxLayout(rightWidget);
        rightLayout->addWidget(label);
        rightLayout->addWidget(textEdit);

        // Add the widgets to the splitter
        splitter->addWidget(leftWidget);
        splitter->addWidget(rightWidget);

        // Add the splitter to the main layout
        mainLayout->addWidget(splitter);

        // Set the main layout for the window
        setLayout(mainLayout);

        // Set window size
        setGeometry(100, 100, 500, 300);
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Create and show the window
    SplitterExample window;
    window.show();

    return app.exec();
}
