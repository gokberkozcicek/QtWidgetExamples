#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QDockWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;

    // Central widget (e.g. main editor area)
    QTextEdit *centralEdit = new QTextEdit;
    centralEdit->setText("This is the central widget.");
    mainWindow.setCentralWidget(centralEdit);

    // Create a dockable widget
    QDockWidget *dock = new QDockWidget("Dockable Panel", &mainWindow);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // Content inside the dock panel
    QLabel *dockContent = new QLabel("This is a dockable panel.");
    dock->setWidget(dockContent);

    // Add the dock panel to the main window
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, dock);

    mainWindow.setWindowTitle("Qt Dock Panel Example");
    mainWindow.resize(600, 400);
    mainWindow.show();

    return app.exec();
}
