#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class MainView : public QWidget {
    public:
        MainView(QWidget* parent = 0);

    private:
        QLabel* actions_label;
        QPushButton* done_button;
        QPushButton* delete_button;
};

MainView::MainView(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox = new QHBoxLayout();

    actions_label = new QLabel("Actions: ", this);

    done_button = new QPushButton("Done", this);
    delete_button = new QPushButton("Delete", this);

    hbox->addWidget(actions_label, 0, Qt::AlignLeft);
    hbox->addWidget(done_button, 0, Qt::AlignLeft);
    hbox->addWidget(delete_button, 1, Qt::AlignLeft);

    vbox->addLayout(hbox);
    vbox->addStretch(1);
}

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    MainView window;

    window.resize(600, 400);
    window.setWindowTitle("TaskManager");
    window.show();

    return app.exec();
}
