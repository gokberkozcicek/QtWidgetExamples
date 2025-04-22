#include <QApplication>
#include <QWidget>
#include <QStackedLayout>
#include <QPushButton>
#include <QLabel>

class StackedLayoutExample : public QWidget
{
public:
    StackedLayoutExample()
    {
        // Set window title
        setWindowTitle("QStackedLayout Example");

        // Create a QStackedLayout
        QStackedLayout* stackedLayout = new QStackedLayout(this);

        // Create some widgets to be stacked
        QWidget* page1 = new QWidget(this);
        QLabel* label1 = new QLabel("This is Page 1", page1);
        QPushButton* button1 = new QPushButton("Go to Page 2", page1);

        QWidget* page2 = new QWidget(this);
        QLabel* label2 = new QLabel("This is Page 2", page2);
        QPushButton* button2 = new QPushButton("Go to Page 1", page2);

        // Layout for Page 1
        QVBoxLayout* page1Layout = new QVBoxLayout(page1);
        page1Layout->addWidget(label1);
        page1Layout->addWidget(button1);

        // Layout for Page 2
        QVBoxLayout* page2Layout = new QVBoxLayout(page2);
        page2Layout->addWidget(label2);
        page2Layout->addWidget(button2);

        // Add pages to stacked layout
        stackedLayout->addWidget(page1);
        stackedLayout->addWidget(page2);

        // Connect buttons to switch between pages
        connect(button1, &QPushButton::clicked, this, [=]() {
            stackedLayout->setCurrentWidget(page2);
            });
        connect(button2, &QPushButton::clicked, this, [=]() {
            stackedLayout->setCurrentWidget(page1);
            });

        // Set the layout for the QWidget
        setLayout(stackedLayout);

        // Set window size
        setGeometry(100, 100, 300, 200);
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Create and show the window
    StackedLayoutExample window;
    window.show();

    return app.exec();
}
