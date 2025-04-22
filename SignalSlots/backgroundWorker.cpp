#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QThread>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT

public:
    Worker(QProgressBar* progressBar) : m_progressBar(progressBar) {}

public slots:
    void doWork() {
        // Simulate long-running task
        for (int i = 0; i <= 100; ++i) {
            QThread::sleep(1);  // Simulate work by sleeping for 1 second
            emit progressChanged(i);  // Emit signal to update progress bar in the main thread
        }
        emit workFinished();
    }

signals:
    void progressChanged(int progress);  // Signal to report progress
    void workFinished();  // Signal when work is done

private:
    QProgressBar* m_progressBar;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent)
    {
        // Set up the UI
        QWidget* centralWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);

        QLabel* label = new QLabel("Click to start background work", this);
        layout->addWidget(label);

        m_progressBar = new QProgressBar(this);
        m_progressBar->setRange(0, 100);
        layout->addWidget(m_progressBar);

        QPushButton* startButton = new QPushButton("Start Background Work", this);
        layout->addWidget(startButton);

        setCentralWidget(centralWidget);

        // Create the worker and move it to a new thread
        m_worker = new Worker(m_progressBar);
        m_workerThread = new QThread(this);
        m_worker->moveToThread(m_workerThread);

        // Connect the signals from the worker to the main window
        connect(m_workerThread, &QThread::started, m_worker, &Worker::doWork);
        connect(m_worker, &Worker::progressChanged, this, &MainWindow::updateProgress, Qt::QueuedConnection);
        connect(m_worker, &Worker::workFinished, this, &MainWindow::onWorkFinished);

        // Connect thread finished signal to cleanup
        connect(m_worker, &Worker::workFinished, m_workerThread, &QThread::quit);
        connect(m_worker, &Worker::workFinished, m_worker, &QObject::deleteLater);
        connect(m_workerThread, &QThread::finished, m_workerThread, &QObject::deleteLater);

        // Connect the start button to the start function
        connect(startButton, &QPushButton::clicked, this, &MainWindow::startWork);
    }

private slots:
    void startWork() {
        // Start the worker thread
        m_workerThread->start();
    }

    void updateProgress(int progress) {
        // Update the progress bar in the main thread
        m_progressBar->setValue(progress);
    }

    void onWorkFinished() {
        // Handle when work is finished
        qDebug() << "Background work finished!";
    }

private:
    Worker* m_worker;
    QThread* m_workerThread;
    QProgressBar* m_progressBar;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

#include "main.moc"  // Include this if you're using Q_OBJECT macro
