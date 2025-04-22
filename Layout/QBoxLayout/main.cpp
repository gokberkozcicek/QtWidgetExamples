#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>

class BoxLayoutExample : public QWidget
{
public:
    BoxLayoutExample()
    {
        // Set window title
        setWindowTitle("QBoxLayout Example");

        // Create a main QBoxLayout with a vertical direction
        QBoxLayout* verticalLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

        // Create widgets to add to the layout
        QLabel* label = new QLabel("This is a label", this);
        QPushButton* button1 = new QPushButton("Button 1", this);
        QPushButton* button2 = new QPushButton("Button 2", this);

        // Add widgets to the vertical layout
        verticalLayout->addWidget(label);
        verticalLayout->addWidget(button1);
        verticalLayout->addWidget(button2);

        // Create a second QBoxLayout with a horizontal direction
        QBoxLayout* horizontalLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);

        // Create additional widgets for the horizontal layout
        QPushButton* button3 = new QPushButton("Button 3", this);
        QPushButton* button4 = new QPushButton("Button 4", this);

        // Add widgets to the horizontal layout
        horizontalLayout->addWidget(button3);
        horizontalLayout->addWidget(button4);

        // Set the layouts as children of the main layout
        QBoxLayout* mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);  // Main vertical layout
        mainLayout->addLayout(verticalLayout);  // Add the vertical layout
        mainLayout->addLayout(horizontalLayout); // Add the horizontal layout

        // Set the main layout for the QWidget
        setLayout(mainLayout);

        // Set window size
        setGeometry(100, 100, 300, 200);
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // Create and show the window
    BoxLayoutExample window;
    window.show();

    return app.exec();
}
