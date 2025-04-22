#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QDockWidget>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QIcon>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;

    // Central widget (e.g. main editor area)
    QTextEdit* centralEdit = new QTextEdit;
    centralEdit->setText("This is the central widget.");
    mainWindow.setCentralWidget(centralEdit);

    // First Dockable Panel (Right side)
    QDockWidget* dock1 = new QDockWidget("Dockable Panel 1", &mainWindow);
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::TopDockWidgetArea ); // Allow docking on all four sides

    // Content inside the first dock panel
    QLabel* dockContent1 = new QLabel("This is Dockable Panel 1.");
    dock1->setWidget(dockContent1);

    // Add the first dock panel to the main window (Right side)
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, dock1);

    // Second Dockable Panel (Bottom side)
    QDockWidget* dock2 = new QDockWidget("Dockable Panel 2", &mainWindow);
    dock2->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::TopDockWidgetArea ); // Allow docking on all four sides

    // Content inside the second dock panel
    QLabel* dockContent2 = new QLabel("This is Dockable Panel 2.");
    dock2->setWidget(dockContent2);

    // Add the second dock panel to the main window (Bottom side)
    mainWindow.addDockWidget(Qt::LeftDockWidgetArea, dock2);

    // --- Menu Bar ---
    QMenu* fileMenu = mainWindow.menuBar()->addMenu("File");

    // Add actions to the File menu
    QAction* newAction = fileMenu->addAction("New");
    QAction* openAction = fileMenu->addAction("Open");
    QAction* saveAction = fileMenu->addAction("Save");

    // --- Tool Bar ---
    QToolBar* toolBar = mainWindow.addToolBar("Main Toolbar");

    // Add actions to the toolbar
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    // Set default icons for the toolbar actions
    newAction->setIcon(QIcon::fromTheme("document-new"));
    openAction->setIcon(QIcon::fromTheme("document-open"));
    saveAction->setIcon(QIcon::fromTheme("document-save"));

    // Set default icons for the menu actions (optional)
    newAction->setIcon(QIcon::fromTheme("document-new"));
    openAction->setIcon(QIcon::fromTheme("document-open"));
    saveAction->setIcon(QIcon::fromTheme("document-save"));

    // --- Window Title & Resize ---
    mainWindow.setWindowTitle("Qt Dock Panel Example");
    mainWindow.resize(600, 400);
    mainWindow.show();

    return app.exec();
}
