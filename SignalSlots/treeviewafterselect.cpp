#include <QApplication>
#include <QMainWindow>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent)
    {
        // Create the central widget and layout
        QWidget* centralWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);

        // Create a label to display selected item
        label = new QLabel("Select an item from the tree.", this);
        layout->addWidget(label);

        // Create a QTreeView
        treeView = new QTreeView(this);

        // Create a model to hold tree data
        QStandardItemModel* model = new QStandardItemModel;
        model->setHorizontalHeaderLabels({ "Name" });

        // Create tree structure using QStandardItem
        QStandardItem* rootNode = model->invisibleRootItem();

        QStandardItem* parentItem = new QStandardItem("Parent");
        rootNode->appendRow(parentItem);

        QStandardItem* child1 = new QStandardItem("Child 1");
        QStandardItem* child2 = new QStandardItem("Child 2");
        parentItem->appendRow(child1);
        parentItem->appendRow(child2);

        QStandardItem* parentItem2 = new QStandardItem("Parent 2");
        rootNode->appendRow(parentItem2);

        QStandardItem* child3 = new QStandardItem("Child 3");
        parentItem2->appendRow(child3);

        // Set the model to the tree view
        treeView->setModel(model);

        // Connect the tree selection signal to the slot
        connect(treeView->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &MainWindow::onItemSelected);

        layout->addWidget(treeView);
        setCentralWidget(centralWidget);

        setWindowTitle("QTreeView Selection Example");
        resize(400, 300);
    }

private slots:
    // Slot to handle item selection
    void onItemSelected(const QModelIndex& current, const QModelIndex&)
    {
        // Get the item text based on the selected index
        QString selectedText = current.data().toString();
        label->setText("Selected Item: " + selectedText);
    }

private:
    QTreeView* treeView; // Tree view widget
    QLabel* label;       // Label to show selected item
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

#include "main.moc"
