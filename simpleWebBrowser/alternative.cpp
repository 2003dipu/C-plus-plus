#include <QApplication>
#include <QMainWindow>
#include <QWebEngineView>
#include <QLineEdit>
#include <QPushButton>
#include<iostream>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow()
    {
        // Create the web view
        QWebEngineView *webView = new QWebEngineView(this);

        // Create the URL bar
        QLineEdit *urlBar = new QLineEdit(this);
        urlBar->setPlaceholderText("Enter a URL...");

        // Create the navigation buttons
        QPushButton *backButton = new QPushButton("Back");
        QPushButton *forwardButton = new QPushButton("Forward");
        QPushButton *refreshButton = new QPushButton("Refresh");

        // Connect the URL bar to the web view
        connect(urlBar, &QLineEdit::returnPressed, webView, &QWebEngineView::load);

        // Connect the navigation buttons to the web view
        connect(backButton, &QPushButton::clicked, webView, &QWebEngineView::back);
        connect(forwardButton, &QPushButton::clicked, webView, &QWebEngineView::forward);
        connect(refreshButton, &QPushButton::clicked, webView, &QWebEngineView::reload);

        // Set the central widget of the main window to the web view
        setCentralWidget(webView);

        // Add the URL bar and navigation buttons to the layout
        layout()->addWidget(urlBar, 0, 0);
        layout()->addWidget(backButton, 0, 1);
        layout()->addWidget(forwardButton, 0, 2);
        layout()->addWidget(refreshButton, 0, 3);
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
